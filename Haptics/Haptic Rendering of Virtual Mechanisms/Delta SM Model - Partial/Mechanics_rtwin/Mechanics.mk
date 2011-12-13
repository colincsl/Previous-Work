# Abstract:
#	Real-Time Workshop template makefile for building Real-Time Windows
#	Target compatible real-time version of Simulink model using generated
#       C code and the built-in Open Watcom C/C++ Compiler.
#
#       The following defines (macro names) can be used to modify the behavior
#       of the build:
#	  OPT_OPTS       - Optimization option.
#	  OPTS           - User specific options.
#         CPP_OPTS       - C++ Compiler Options
#	  USER_OBJS      - Additional user objects, such as files needed by
#			   S-functions.
#         USER_PATH      - The directory path to the source (.c) files which
#                          are used to create any .obj files specified in
#                          USER_OBJS. Multiple paths must be separated
#                          with a semicolon. For example:
#                          "USER_PATH=path1;path2"
#	  USER_INCLUDES  - Additional include paths (i.e.
#			   "USER_INCLUDES=-Iinclude-path1 -Iinclude-path2")
#
#       Consider using "Real-Time Windows Target build options" page in RTW
#       options dialog instead of trying to change OPT_OPTS here.
#
#       In particular, note how the quotes are before the name of the macro
#       name.
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.ProjectDirSuffix' see grt.tlc
#
# $Revision: 1.1.6.14 $  $Date: 2007/06/04 21:15:08 $  $Author: batserve $
# Copyright 1994-2007 The MathWorks, Inc.
#



#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.
#
MAKECMD         = "%RTWIN%\openwat\binnt\wmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = rtwin.tlc


#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME        - Name of the Simulink block diagram
#  MODEL_MODULES_OBJ - Object file name for any additional generated source
#                      modules
#  MAKEFILE_NAME     - Name of makefile created from template makefile
#                      <model>.mk
#  MATLAB_ROOT       - Path to were MATLAB is installed.
#  MATLAB_BIN        - Path to MATLAB executable.
#  S_FUNCTIONS_LIB   - List of S-functions libraries to link.
#  S_FUNCTIONS_OBJ   - List of S-functions .obj sources
#  SOLVER_OBJ        - Solver object file name
#  NUMST             - Number of sample times
#  TID01EQ           - yes (1) or no (0): Are sampling rates of continuous
#                      task (tid=0) and 1st discrete task equal.
#  NCSTATES          - Number of continuous states
#  BUILDARGS         - Options passed in at the command line.
#  MULTITASKING      - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE          - yes (1) or no (0): Build for external mode
#  EXTMODE_TRANSPORT - Name of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  CC_OPTIMIZE       - yes (1) or no (0): Generate optimized code
#  CC_LISTING        - yes (1) or no (0): Generate assembly listings
#  REBUILD_ALL       - yes (1) or no (0): Rebuild all files

MODEL               = Mechanics
MODULES_OBJ         = Mechanics_data.obj rt_mechanism.obj rt_mechanism_data.obj rt_mechanism_map.obj 
MAKEFILE            = Mechanics.mk
MATLAB_ROOT         = C:\PROGRA~1\MATLAB\R2007b
MATLAB_BIN          = C:\PROGRA~1\MATLAB\R2007b\bin
S_FUNCTIONS         = 
S_FUNCTIONS_LIB     = 
SOLVER              = ode3.obj
NUMST               = 2
TID01EQ             = 1
NCSTATES            = 10
BUILDARGS           =  GENERATE_REPORT=0 TMW_EXTMODE_TESTING=0 MODELLIB=Mechanicslib.lib RELATIVE_PATH_TO_ANCHOR=.. MODELREF_TARGET_TYPE=NONE
MULTITASKING        = 0
EXT_MODE            = 1
EXTMODE_TRANSPORT   = 0
EXTMODE_STATIC      = 0
EXTMODE_STATIC_SIZE = 1000000
CC_OPTIMIZE         = 1
CC_LISTING          = 0
REBUILD_ALL         = 0


#--------------------------------- Tool Locations -----------------------------
#
RTWIN = $(MATLAB_ROOT)\toolbox\rtw\targets\rtwin
OPENWAT = $(RTWIN)\openwat
CC = wcc386
CPP = wpp386
AS = wasm
DISAS = wdis
LD = wlink
LIBCMD = wlib -q
PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl


#------------------------ External mode ---------------------------------------
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
!ifeq EXT_MODE 1
EXT_CC_OPTS_GEN = -DEXT_MODE
!ifeq EXTMODE_STATIC 1
EXT_OBJ_MEM     = mem_mgr.obj
EXT_CC_OPTS_MEM = -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
!else
EXT_OBJ_MEM     = 
EXT_CC_OPTS_MEM = 
!endif
EXTMODE_PATH    = $(MATLAB_ROOT)\rtw\c\src\ext_mode\common;$(MATLAB_ROOT)\rtw\c\src\ext_mode\custom;
EXT_OBJ         = $(EXT_OBJ_MEM)
EXT_CC_OPTS     = $(EXT_CC_OPTS_GEN) $(EXT_CC_OPTS_MEM)
!else
EXTMODE_PATH  =
EXT_OBJ       =
EXT_CC_OPTS   =
!endif


#------------------------------ Include Path -----------------------------

MATLAB_INCLUDES = &
$(MATLAB_ROOT)\simulink\include;&
$(MATLAB_ROOT)\extern\include;&
$(MATLAB_ROOT)\rtw\c\src;&
$(RTWIN)\src;&
$(MATLAB_ROOT)\rtw\c\src\ext_mode\common;

# Additional includes
ADD_INCLUDES = &
C:\Users\colin\Desktop\haptics\sim\Mechanics_rtwin;&
C:\Users\colin\Desktop\haptics\sim;&
$(MATLAB_ROOT)\rtw\c\libsrc;&
$(MATLAB_ROOT)\toolbox\physmod\mech\c;&


COMPILER_INCLUDES = $(OPENWAT)\include

INCLUDES = .;$(MATLAB_INCLUDES)$(ADD_INCLUDES)$(COMPILER_INCLUDES)

#-------------------------------- C Flags --------------------------------

# General Compiler Options
REQ_OPTS = -zq -ei -zp8 -6r -fpi87 -zl -wx
CC_REQ_OPTS = -wcd=302 -wcd=1180
CPP_REQ_OPTS = -wcd=139 -wcd=367 -wcd=389 -wcd=726

# Optimization Options.
# Change OPT_OPTS but never DEFAULT_OPT_OPTS !!!
!ifeq CC_OPTIMIZE 1
!ifeq CC_LISTING 1
DEFAULT_OPT_OPTS = -oneatxh -d1
!else
DEFAULT_OPT_OPTS = -oneatxh
!endif
!else
!ifeq CC_LISTING 1
DEFAULT_OPT_OPTS = -od -d2
!else
DEFAULT_OPT_OPTS = -od
!endif
!endif
OPT_OPTS = $(DEFAULT_OPT_OPTS)

CC_OPTS = -DUSE_RTMODEL $(REQ_OPTS) $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS)

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) &
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) &
                  -DMT=$(MULTITASKING)

CFLAGS = $(CC_REQ_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
CPPFLAGS = $(CPP_REQ_OPTS) $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)

#------------------------------- Source Files ---------------------------------

REQ_OBJS  = $(MODEL).obj $(MODULES_OBJ) rt_stub.obj rt_sim.obj rt_nonfinite.obj
USER_OBJS =

OBJS = $(REQ_OBJS) $(USER_OBJS) $(S_FUNCTIONS) $(SOLVER) $(EXT_OBJ)

#---------------------------- Additional Libraries ----------------------------

LIBS = 

!ifeq OPT_OPTS $(DEFAULT_OPT_OPTS)
LIBS += $(MATLAB_ROOT)\toolbox\physmod\mech\lib\win32\mech_rtwin_openwat.lib
!else
LIBS += mech.lib
!endif

!ifeq OPT_OPTS $(DEFAULT_OPT_OPTS)
LIBS += $(MATLAB_ROOT)\rtw\c\lib\win32\rtwlib_rtwin_openwat.lib
!else
LIBS += rtwlib.lib
!endif



RTWINTGTLIB = $(RTWIN)\lib\rtmodwat.lib

#-------------------------- Source Path ---------------------------------------

# User source path

!ifdef USER_PATH
EXTRA_PATH = ;$(USER_PATH)
!else
EXTRA_PATH =
!endif

# Additional sources

ADD_SOURCES = $(MATLAB_ROOT)\rtw\c\src;$(MATLAB_ROOT)\toolbox\physmod\mech\c;$(MATLAB_ROOT)\toolbox\physmod\mech\mech;$(MATLAB_ROOT)\rtw\c\libsrc;

# Source Path

.c :   ..;$(RTWIN)\src;$(MATLAB_ROOT)\rtw\c\src;$(MATLAB_ROOT)\simulink\src;$(EXTMODE_PATH)$(ADD_SOURCES)$(EXTRA_PATH)
.cpp : ..;$$(RTWIN)\src;(MATLAB_ROOT)\rtw\c\src;$(MATLAB_ROOT)\simulink\src;$(EXTMODE_PATH)$(ADD_SOURCES)$(EXTRA_PATH)

#----------------------- Exported Environment Variables -----------------------
#
#  Setup path for tools.
#
PATH = $(OPENWAT)\binnt

#--------------------------------- Rules --------------------------------------

!loaddll wcc386 wccd386
!loaddll wpp386 wppd386
!loaddll wlink  wlink
!loaddll wlib   wlibd


.ERASE

.BEFORE
	@set path=$(PATH)
	@set INCLUDE=$(INCLUDES)
	@set WATCOM=$(OPENWAT)
	@set MATLAB=$(MATLAB_ROOT)
!ifeq REBUILD_ALL 1
	@echo $#$#$# Rebuilding all object files ...
        @if exist ..\$(MODEL).rwd @del ..\$(MODEL).rwd
        @if exist *.lnk @del *.lnk
        @if exist *.obj @del *.obj
        @if exist *.lst @del *.lst
        @if exist *.lib @del *.lib
!endif

..\$(MODEL).rwd : $(OBJS) $(LIBS) $(MODEL).lnk
	$(LD) NAME $@ $(LDFLAGS) @$(MODEL).lnk
	@echo $#$#$# Created Real-Time Windows Target module $(MODEL).rwd.
	@del $(MODEL).lnk

$(MODEL).lnk : $(MAKEFILE)
  @echo.
  @echo    Creating linker response file $@
  @%create $@
  @%append $@ FORMAT windows nt dll
  @%append $@ RUNTIME native=2.00
  @%append $@ EXPORT Header=_Header
  @%append $@ EXPORT Inquiry=_Inquiry
  @%append $@ EXPORT Disable=_Disable
  @%append $@ EXPORT Enable=_Enable
  @%append $@ EXPORT GetBoards=_GetBoards
  @%append $@ OPTION caseexact
  @%append $@ OPTION quiet
!ifeq CC_LISTING 1
  @%append $@ OPTION map
!endif
  @%append $@ DISABLE 14
  @%append $@ DISABLE 1027
  @for %i in ($(OBJS)) do @%append $@ FILE %i
  @%append $@ LIBRARY $(RTWINTGTLIB)
  @%append $@ LIBRARY $(OPENWAT)\lib386\math387r
  @%append $@ LIBRARY $(OPENWAT)\lib386\clib3r
  @%append $@ LIBRARY $(OPENWAT)\lib386\plib3r
  @for %i in ($(LIBS)) do @%append $@ LIBRARY %i

.c.obj:
	@echo $#$#$# Compiling $[@
	$(CC) $(CFLAGS) $[@
!ifeq CC_LISTING 1
	$(DISAS) -l -s $^@
!endif

.cpp.obj:
	@echo $#$#$# Compiling $[@
	$(CPP) $(CPPFLAGS) $[@
!ifeq CC_LISTING 1
	$(DISAS) -l -s $^@
!endif

$(OBJS) : $(MAKEFILE) rtw_proj.tmw .AUTODEPEND

# Libraries:



MODULES_mech = &
    mech_00006e65.obj &
    mech_0007b2a9.obj &
    mech_000ed056.obj &
    mech_01d87d3a.obj &
    mech_026a2d99.obj &
    mech_03b136ec.obj &
    mech_03bb34d9.obj &
    mech_03bb3c6d.obj &
    mech_04d5988f.obj &
    mech_04dd4c5e.obj &
    mech_06b3bf64.obj &
    mech_06b9086b.obj &
    mech_06bedb25.obj &
    mech_07671538.obj &
    mech_0767724b.obj &
    mech_0862eda6.obj &
    mech_086533bb.obj &
    mech_09b19182.obj &
    mech_09b1fec0.obj &
    mech_0bd00907.obj &
    mech_0bd0b77a.obj &
    mech_0bd10737.obj &
    mech_0bd2b991.obj &
    mech_0bd664f2.obj &
    mech_0bd7d25b.obj &
    mech_0cb0c361.obj &
    mech_0cb6ce08.obj &
    mech_0d650488.obj &
    mech_0d66d17e.obj &
    mech_0ed451b2.obj &
    mech_0ed45902.obj &
    mech_0ed45e06.obj &
    mech_0f089acf.obj &
    mech_0f0fff67.obj &
    mech_10d1a830.obj &
    mech_10dbc42c.obj &
    mech_1101d608.obj &
    mech_12bb508a.obj &
    mech_136d4516.obj &
    mech_136ff8ec.obj &
    mech_14033882.obj &
    mech_15d7fd16.obj &
    mech_166ecc83.obj &
    mech_17b3d969.obj &
    mech_17b5d2c8.obj &
    mech_18b74dc4.obj &
    mech_18bc4c78.obj &
    mech_19668514.obj &
    mech_1968edfa.obj &
    mech_196a81d3.obj &
    mech_196d5583.obj &
    mech_196f54b3.obj &
    mech_1ad1d08f.obj &
    mech_1ad8beb5.obj &
    mech_1ada66bb.obj &
    mech_1adadbd7.obj &
    mech_1adc0f49.obj &
    mech_1c60663f.obj &
    mech_1dbace12.obj &
    mech_1dbda3ff.obj &
    mech_1dbe1d9c.obj &
    mech_1e064a3f.obj &
    mech_1fd889d5.obj &
    mech_1fda8b96.obj &
    mech_1fdced41.obj &
    mech_206c58ce.obj &
    mech_206c8603.obj &
    mech_21b84b43.obj &
    mech_2205ccb7.obj &
    mech_220ec111.obj &
    mech_220f714b.obj &
    mech_23d70961.obj &
    mech_23dbb21d.obj &
    mech_24b71ad9.obj &
    mech_24b77237.obj &
    mech_24bb1149.obj &
    mech_24bba50d.obj &
    mech_24bfa08f.obj &
    mech_2567641e.obj &
    mech_256cde98.obj &
    mech_26d4ef1c.obj &
    mech_26d886a3.obj &
    mech_26db8855.obj &
    mech_26df8d12.obj &
    mech_28020b37.obj &
    mech_2802698b.obj &
    mech_280501aa.obj &
    mech_29d37a28.obj &
    mech_2a654443.obj &
    mech_2bb05015.obj &
    mech_2bba5516.obj &
    mech_2bbc8c68.obj &
    mech_2cd84f8c.obj &
    mech_2cdd985a.obj &
    mech_2d025ffd.obj &
    mech_2d0aed76.obj &
    mech_2eb2b298.obj &
    mech_2eb66379.obj &
    mech_2ebc07de.obj &
    mech_2ebebb91.obj &
    mech_30b648ac.obj &
    mech_31653540.obj &
    mech_316a3f58.obj &
    mech_32d20288.obj &
    mech_32d56014.obj &
    mech_32d9db4c.obj &
    mech_32de0762.obj &
    mech_3304c804.obj &
    mech_3305a484.obj &
    mech_330d7bc3.obj &
    mech_3462babe.obj &
    mech_35b51c4f.obj &
    mech_35b5cace.obj &
    mech_35b77254.obj &
    mech_35b915fd.obj &
    mech_35bec0a8.obj &
    mech_360546c6.obj &
    mech_360c2aa1.obj &
    mech_37d552b9.obj &
    mech_38d7a7ef.obj &
    mech_3901d369.obj &
    mech_39096856.obj &
    mech_390c6b4e.obj &
    mech_390e6b5a.obj &
    mech_3abc86c0.obj &
    mech_3abf521c.obj &
    mech_3b61901a.obj &
    mech_3b639cf6.obj &
    mech_3b6df100.obj &
    mech_3c0639b9.obj &
    mech_3c0839c5.obj &
    mech_3c0987b6.obj &
    mech_3c0c580b.obj &
    mech_3c0c5fd8.obj &
    mech_3dd0930b.obj &
    mech_3dd1969f.obj &
    mech_3ddb25c6.obj &
    mech_3ddbffa6.obj &
    mech_3ddd2456.obj &
    mech_3e60c0e6.obj &
    mech_3fbd66a7.obj &
    mech_4108afbe.obj &
    mech_4109157a.obj &
    mech_410bc4f2.obj &
    mech_410bc65c.obj &
    mech_42b09df4.obj &
    mech_42be9678.obj &
    mech_436631a7.obj &
    mech_440c2ed8.obj &
    mech_440d22de.obj &
    mech_440e9e4b.obj &
    mech_45d03616.obj &
    mech_4662030c.obj &
    mech_4667dbb7.obj &
    mech_4669043e.obj &
    mech_47b2a55c.obj &
    mech_47bf135b.obj &
    mech_48b789cc.obj &
    mech_4960f2f1.obj &
    mech_4ad07741.obj &
    mech_4adca3e0.obj &
    mech_4adca419.obj &
    mech_4adcc3ed.obj &
    mech_4adfc9a4.obj &
    mech_4b05b87a.obj &
    mech_4b060957.obj &
    mech_4b0e0291.obj &
    mech_4e0282f0.obj &
    mech_4e095d4e.obj &
    mech_4e0b5f0d.obj &
    mech_4e0f5c6a.obj &
    mech_4fd44d66.obj &
    mech_50071041.obj &
    mech_500a181b.obj &
    mech_51d06e5d.obj &
    mech_51d0d7b4.obj &
    mech_51d16f25.obj &
    mech_51dedbfe.obj &
    mech_52638b20.obj &
    mech_5265e44f.obj &
    mech_53b499b4.obj &
    mech_53b926f6.obj &
    mech_53bb4a1e.obj &
    mech_53bbf9bf.obj &
    mech_54d28978.obj &
    mech_54d28f65.obj &
    mech_54d33844.obj &
    mech_54db5fea.obj &
    mech_550dfb7b.obj &
    mech_56bda6f0.obj &
    mech_5760b8b3.obj &
    mech_586346cf.obj &
    mech_586c9b48.obj &
    mech_586cfb14.obj &
    mech_59b4e720.obj &
    mech_59b5542b.obj &
    mech_59b9ec0f.obj &
    mech_5cb80b48.obj &
    mech_5cbbb213.obj &
    mech_5f065a28.obj &
    mech_60b13b67.obj &
    mech_60b6e6b2.obj &
    mech_616827f3.obj &
    mech_62d1c262.obj &
    mech_6462c322.obj &
    mech_65b2670b.obj &
    mech_65b2d1f7.obj &
    mech_65b36df8.obj &
    mech_65bf06d4.obj &
    mech_67d04c46.obj &
    mech_67d244f0.obj &
    mech_67d54f32.obj &
    mech_67df977c.obj &
    mech_68d36d56.obj &
    mech_69081e4f.obj &
    mech_6ab1f394.obj &
    mech_6ab52289.obj &
    mech_6ab5f9a4.obj &
    mech_6b635a65.obj &
    mech_6b65599b.obj &
    mech_6b66390f.obj &
    mech_6b6c87b1.obj &
    mech_6c044da2.obj &
    mech_6c04f91c.obj &
    mech_6c06477b.obj &
    mech_6c0c4edb.obj &
    mech_6dd15c06.obj &
    mech_6dd532a0.obj &
    mech_6dd6eb16.obj &
    mech_6dde8c98.obj &
    mech_6fb01ff1.obj &
    mech_6fb8192c.obj &
    mech_6fbac67b.obj &
    mech_71baeedc.obj &
    mech_71bc5898.obj &
    mech_71bd8c55.obj &
    mech_720404ec.obj &
    mech_73d11bf4.obj &
    mech_73d21206.obj &
    mech_73d2a9d1.obj &
    mech_73d3ca8d.obj &
    mech_73dd73bb.obj &
    mech_73de785a.obj &
    mech_73df700a.obj &
    mech_74b20fb1.obj &
    mech_75637fd1.obj &
    mech_76d29623.obj &
    mech_79d0d97f.obj &
    mech_79d8061f.obj &
    mech_79debe9e.obj &
    mech_7a67e49e.obj &
    mech_7bb22415.obj &
    mech_7bba295f.obj &
    mech_7cd6efca.obj &
    mech_7cdae70c.obj &
    mech_7d044d4c.obj &
    mech_7d0d2988.obj &
    mech_7f6301ee.obj &
    mech_7f65b297.obj &
    mech_7f6cd5da.obj &
    mech_7f6f03ea.obj &
    mech_8064658e.obj &
    mech_806a6ff9.obj &
    mech_806ab471.obj &
    mech_81b010a6.obj &
    mech_81b2a7ec.obj &
    mech_81b31a70.obj &
    mech_81b3c62c.obj &
    mech_8202fad3.obj &
    mech_83db3577.obj &
    mech_84bdfd5b.obj &
    mech_8565e0ad.obj &
    mech_8567868b.obj &
    mech_856c886e.obj &
    mech_856feaf6.obj &
    mech_86d46dbd.obj &
    mech_86d803ff.obj &
    mech_86dcdc59.obj &
    mech_87031b9f.obj &
    mech_88015fa4.obj &
    mech_89d6ff6d.obj &
    mech_89df22b4.obj &
    mech_8bb6b456.obj &
    mech_8bb8da3f.obj &
    mech_8bbad533.obj &
    mech_8cd5ce68.obj &
    mech_8cdaa057.obj &
    mech_8cdd1bcd.obj &
    mech_8cde1353.obj &
    mech_8d01d08a.obj &
    mech_8d03b8e5.obj &
    mech_8d070edf.obj &
    mech_8d0bba30.obj &
    mech_8d0c037b.obj &
    mech_8d0f0713.obj &
    mech_8eba5477.obj &
    mech_8f654afc.obj &
    mech_90b0a5f4.obj &
    mech_90bd1984.obj &
    mech_9166b82a.obj &
    mech_9166d09b.obj &
    mech_916cb416.obj &
    mech_92d4853c.obj &
    mech_92d632c3.obj &
    mech_92d68cce.obj &
    mech_93002c63.obj &
    mech_93094c9e.obj &
    mech_94648110.obj &
    mech_946656b0.obj &
    mech_94693390.obj &
    mech_95b19739.obj &
    mech_95b59b14.obj &
    mech_95bf2300.obj &
    mech_960d79d4.obj &
    mech_97d304eb.obj &
    mech_98d02fb0.obj &
    mech_98d24db5.obj &
    mech_99015504.obj &
    mech_9ab6d772.obj &
    mech_9b611ed7.obj &
    mech_9b6aa470.obj &
    mech_9c046ba4.obj &
    mech_9dd3a3a7.obj &
    mech_9e649e52.obj &
    mech_9e6b9488.obj &
    mech_9fb0e687.obj &
    mech_9fbe31aa.obj &
    mech_9fbf5b04.obj &
    mech_9fbf8306.obj &
    mech_a0023621.obj &
    mech_a005e178.obj &
    mech_a1da4224.obj &
    mech_a1df4d1a.obj &
    mech_a2667e73.obj &
    mech_a266ca1b.obj &
    mech_a3b26127.obj &
    mech_a3bfd9f2.obj &
    mech_a4dca94e.obj &
    mech_a505d923.obj &
    mech_a5066f03.obj &
    mech_a50fbcc4.obj &
    mech_a6b05f4b.obj &
    mech_a6bd35b2.obj &
    mech_a6beeef9.obj &
    mech_a76b42bc.obj &
    mech_a76ef767.obj &
    mech_a76ffdc2.obj &
    mech_a865b9aa.obj &
    mech_a867be74.obj &
    mech_a9b3a416.obj &
    mech_a9bc1b9d.obj &
    mech_a9bdc32c.obj &
    mech_aa0594f2.obj &
    mech_aa07f0ff.obj &
    mech_aa0b9657.obj &
    mech_abd5e763.obj &
    mech_abd7ebac.obj &
    mech_abdbe416.obj &
    mech_acb043d9.obj &
    mech_acb0f0ee.obj &
    mech_acb29993.obj &
    mech_acb2f87a.obj &
    mech_acb8f1da.obj &
    mech_acbd4167.obj &
    mech_ad678530.obj &
    mech_ad6a8807.obj &
    mech_aed4b64f.obj &
    mech_aed8baf4.obj &
    mech_af00a969.obj &
    mech_af07c7d7.obj &
    mech_b0d42cb2.obj &
    mech_b0d59e1e.obj &
    mech_b0d89f46.obj &
    mech_b100583f.obj &
    mech_b1018990.obj &
    mech_b2b7b649.obj &
    mech_b2b80846.obj &
    mech_b36315a9.obj &
    mech_b36ece21.obj &
    mech_b36fa760.obj &
    mech_b409d050.obj &
    mech_b409dc44.obj &
    mech_b5dea0b1.obj &
    mech_b5dfa5d8.obj &
    mech_b66922b9.obj &
    mech_b66cf26c.obj &
    mech_b7ba32a8.obj &
    mech_b7bd5732.obj &
    mech_b965b86f.obj &
    mech_bad55464.obj &
    mech_bad5e786.obj &
    mech_bad95da7.obj &
    mech_bade89b1.obj &
    mech_bb00f157.obj &
    mech_bb044a51.obj &
    mech_bb0af744.obj &
    mech_bb0f2ab6.obj &
    mech_bc60369d.obj &
    mech_bc6355a7.obj &
    mech_bc638738.obj &
    mech_bc68822a.obj &
    mech_bc6c3377.obj &
    mech_bdbb4131.obj &
    mech_bdbdf636.obj &
    mech_be0ec8ca.obj &
    mech_bfd0d6a6.obj &
    mech_bfd2be09.obj &
    mech_bfd5d0aa.obj &
    mech_bfda09ef.obj &
    mech_bfdbdf48.obj &
    mech_c0b0b0fc.obj &
    mech_c0b76cb1.obj &
    mech_c0bab1b4.obj &
    mech_c0bf0ba2.obj &
    mech_c161c8f2.obj &
    mech_c166a924.obj &
    mech_c16a7c99.obj &
    mech_c16ac570.obj &
    mech_c2dc44de.obj &
    mech_c30e5a9e.obj &
    mech_c5b480c3.obj &
    mech_c5b53393.obj &
    mech_c608b9a8.obj &
    mech_c7dbcb47.obj &
    mech_c7dec30e.obj &
    mech_c8d589be.obj &
    mech_c8dce154.obj &
    mech_c8dce289.obj &
    mech_cab31321.obj &
    mech_cabc1f51.obj &
    mech_cabec90c.obj &
    mech_cc01ab49.obj &
    mech_ce68e76d.obj &
    mech_cfb5943b.obj &
    mech_cfb7fd53.obj &
    mech_d06212b7.obj &
    mech_d0627877.obj &
    mech_d067c907.obj &
    mech_d06c1589.obj &
    mech_d06ec12b.obj &
    mech_d20583ec.obj &
    mech_d3de49fd.obj &
    mech_d4b0e3ce.obj &
    mech_d4b63106.obj &
    mech_d4bf89ad.obj &
    mech_d6d41a0e.obj &
    mech_d709d89a.obj &
    mech_d70a6366.obj &
    mech_d70edcee.obj &
    mech_d8009864.obj &
    mech_d80122e1.obj &
    mech_d803970f.obj &
    mech_d8052afe.obj &
    mech_d805f7c4.obj &
    mech_d9d2e660.obj &
    mech_da606c44.obj &
    mech_da64d0eb.obj &
    mech_da6705de.obj &
    mech_da676a1c.obj &
    mech_da67d7de.obj &
    mech_dcdfbc35.obj &
    mech_dd02c6d0.obj &
    mech_dd0a7654.obj &
    mech_deb8fc9e.obj &
    mech_deb921be.obj &
    mech_df63e657.obj &
    mech_df648470.obj &
    mech_df6ee64b.obj &
    mech_e0d48ef5.obj &
    mech_e0d586d0.obj &
    mech_e10194d9.obj &
    mech_e1072c0e.obj &
    mech_e109fba1.obj &
    mech_e10a9195.obj &
    mech_e10e2e0e.obj &
    mech_e2b01603.obj &
    mech_e2b2cdb3.obj &
    mech_e2b5107a.obj &
    mech_e2b611cd.obj &
    mech_e2ba15be.obj &
    mech_e360bd67.obj &
    mech_e362637b.obj &
    mech_e367bb32.obj &
    mech_e40bcae0.obj &
    mech_e5d602c8.obj &
    mech_e5d9dae2.obj &
    mech_e5dfd66e.obj &
    mech_e6625355.obj &
    mech_e6635189.obj &
    mech_e7b426cd.obj &
    mech_e8beb74f.obj &
    mech_e9611264.obj &
    mech_e962a4b0.obj &
    mech_e96417d4.obj &
    mech_ead79cd6.obj &
    mech_eade219a.obj &
    mech_eade250c.obj &
    mech_eb03e71e.obj &
    mech_eb0b802a.obj &
    mech_eb0c589e.obj &
    mech_eb0ce008.obj &
    mech_ec63f9ff.obj &
    mech_ec66986d.obj &
    mech_ec67921f.obj &
    mech_ec6c45a1.obj &
    mech_edbd33c5.obj &
    mech_ee09b802.obj &
    mech_ee0a6df6.obj &
    mech_ee0bdc78.obj &
    mech_ee0f0a98.obj &
    mech_efd278dd.obj &
    mech_efd71c85.obj &
    mech_f1d435e3.obj &
    mech_f1d68a38.obj &
    mech_f1d85ae0.obj &
    mech_f1dee442.obj &
    mech_f1deeea4.obj &
    mech_f264d6f3.obj &
    mech_f3bea1d4.obj &
    mech_f3bfa70e.obj &
    mech_f4d005a3.obj &
    mech_f4d168d2.obj &
    mech_f4d4bd71.obj &
    mech_f4d9b522.obj &
    mech_f50418a0.obj &
    mech_f505a4af.obj &
    mech_f50611c4.obj &
    mech_f50d14d1.obj &
    mech_f50d7704.obj &
    mech_f6b24719.obj &
    mech_f6be2959.obj &
    mech_f760804c.obj &
    mech_f76381a2.obj &
    mech_f76585cd.obj &
    mech_f76c3512.obj &
    mech_f76f37e6.obj &
    mech_f8691088.obj &
    mech_f9b00ceb.obj &
    mech_f9b46bf1.obj &
    mech_fa028b96.obj &
    mech_fa0687e9.obj &
    mech_fcb6e96a.obj &
    mech_fcb88991.obj &
    mech_fcbce350.obj &
    mech_fd6223f1.obj &
    mech_ff04dc33.obj &
    mech_ff06b064.obj &
    mech_ff06b6e1.obj &
    mech_ff0ed07b.obj &


mech.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_mech)
	@echo $#$#$# Creating $@
	@if exist $@ @del $@
	@for %i in ($(MODULES_mech)) do $(LIBCMD) $@ +%i
	@echo $#$#$# Created $@

MODULES_rtwlib = &
    rt_backsubcc_dbl.obj &
    rt_backsubcc_sgl.obj &
    rt_backsubrc_dbl.obj &
    rt_backsubrc_sgl.obj &
    rt_backsubrr_dbl.obj &
    rt_backsubrr_sgl.obj &
    rt_enab.obj &
    rt_forwardsubcc_dbl.obj &
    rt_forwardsubcc_sgl.obj &
    rt_forwardsubcr_dbl.obj &
    rt_forwardsubcr_sgl.obj &
    rt_forwardsubrc_dbl.obj &
    rt_forwardsubrc_sgl.obj &
    rt_forwardsubrr_dbl.obj &
    rt_forwardsubrr_sgl.obj &
    rt_look.obj &
    rt_look1d.obj &
    rt_look1d32.obj &
    rt_look2d32_general.obj &
    rt_look2d32_normal.obj &
    rt_look2d_general.obj &
    rt_look2d_normal.obj &
    rt_look32.obj &
    rt_lu_cplx.obj &
    rt_lu_cplx_sgl.obj &
    rt_lu_real.obj &
    rt_lu_real_sgl.obj &
    rt_matdivcc_dbl.obj &
    rt_matdivcc_sgl.obj &
    rt_matdivcr_dbl.obj &
    rt_matdivcr_sgl.obj &
    rt_matdivrc_dbl.obj &
    rt_matdivrc_sgl.obj &
    rt_matdivrr_dbl.obj &
    rt_matdivrr_sgl.obj &
    rt_matmultandinccc_dbl.obj &
    rt_matmultandinccc_sgl.obj &
    rt_matmultandinccr_dbl.obj &
    rt_matmultandinccr_sgl.obj &
    rt_matmultandincrc_dbl.obj &
    rt_matmultandincrc_sgl.obj &
    rt_matmultandincrr_dbl.obj &
    rt_matmultandincrr_sgl.obj &
    rt_matmultcc_dbl.obj &
    rt_matmultcc_sgl.obj &
    rt_matmultcr_dbl.obj &
    rt_matmultcr_sgl.obj &
    rt_matmultrc_dbl.obj &
    rt_matmultrc_sgl.obj &
    rt_matmultrr_dbl.obj &
    rt_matmultrr_sgl.obj &
    rt_sat_div_int16.obj &
    rt_sat_div_int32.obj &
    rt_sat_div_int8.obj &
    rt_sat_div_uint16.obj &
    rt_sat_div_uint32.obj &
    rt_sat_div_uint8.obj &
    rt_sat_prod_int16.obj &
    rt_sat_prod_int32.obj &
    rt_sat_prod_int8.obj &
    rt_sat_prod_uint16.obj &
    rt_sat_prod_uint32.obj &
    rt_sat_prod_uint8.obj &


rtwlib.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_rtwlib)
	@echo $#$#$# Creating $@
	@if exist $@ @del $@
	@for %i in ($(MODULES_rtwlib)) do $(LIBCMD) $@ +%i
	@echo $#$#$# Created $@


