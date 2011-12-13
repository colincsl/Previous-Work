# Copyright 2008 Quanser, Inc.
#
# File    : quarc_windows.tmf   $Revision: 1.0 $
#
# Abstract:
#       Real-Time Workshop template makefile for building a standalone
#       QuaRC real-time version of a Simulink model using generated
#       C code and the Microsoft Visual C/C++ compiler versions: 6.0, 7.1
#
#       Note that this template is automatically customized by the Real-Time
#       Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#         OPT_OPTS       - Optimization option. Default is -O2. To enable
#                          debugging specify as OPT_OPTS=-Zd.
#         OPTS           - User specific options.
#         CPP_OPTS       - C++ compiler options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD             - This is the command used to invoke the make utility
#  HOST                - What platform this template makefile is targeted for
#                        (i.e. PC or UNIX)
#  BUILD               - Invoke make from the Real-Time Workshop build procedure
#                        (yes/no)?
#  SYS_TARGET_FILE     - Name of system target file.
#  BUILD_SUCCESS       - String that is used to indicate that the build succeeded
#  COMPILER_TOOL_CHAIN - Compiler suite that is used to compile the code

MAKECMD             = nmake
HOST                = PC
BUILD               = yes
SYS_TARGET_FILE     = quarc_windows.tlc
BUILD_SUCCESS	    = ^#^#^# Created
COMPILER_TOOL_CHAIN = vc

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  ALT_MATLAB_ROOT     - Alternate path to were MATLAB is installed. Used when MATLAB_ROOT contains spaces.
#  ALT_MATLAB_BIN      - Alternate path to MATLAB executable. Used when MATLAB_BIN contains spaces.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  MAT_FILE            - yes (1) or no (0): generate a model.mat file?
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  RELEASE_VERSION     - The release version of MATLAB.
#
#  MODELREFS           - A list of the referenced model names.
#  VISUAL_VER          - Visual C++ version information
#
#  MODELLIB                - The name of the library generated for the model.
#  MODELREF_LINK_LIBS      - A list of referenced model libraries that the top-level model links against.
#  MODELREF_INC_PATH       - The include path to the referenced models.
#  RELATIVE_PATH_TO_ANCHOR - The relative path from the location of the generated makefile to the MATLAB working directory.
#  MODELREF_TARGET_TYPE    - The type of target being built. Possible values are:
#                              NONE - standalone model or top-level model referencing other models.
#                              RTW  - model reference Real-Time Workshop target build.
#                              SIM  - model reference simulation target build.
#


MODEL                = Crane
MODULES              = Crane_data.c Crane_main.c rt_mechanism.c rt_mechanism_data.c rt_mechanism_map.c rt_nonfinite.c 
MAKEFILE             = Crane.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2007b
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2007b
MATLAB_BIN           = C:\Program Files\MATLAB\R2007b\bin
ALT_MATLAB_BIN       = C:\PROGRA~1\MATLAB\R2007b\bin
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = C:\PROGRA~1\Quanser\QuaRC\lib\windows\QU0C01~1.LIB C:\PROGRA~1\Quanser\QuaRC\lib\windows\QUANSE~2.LIB C:\PROGRA~1\Quanser\QuaRC\lib\windows\QUANSE~4.LIB C:\PROGRA~1\Quanser\QuaRC\lib\windows\QUANSE~3.LIB
SOLVER               = ode1.c
NUMST                = 2
TID01EQ              = 1
NCSTATES             = 21
COMPUTER             = PCWIN
BUILDARGS            =  GENERATE_REPORT=0 MAT_FILE=0 DEBUG=0
MULTITASKING         = 0
EXT_MODE             = 1
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000
RELEASE_VERSION      = R2007b

MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
TARGET_LANG_EXT      = c
VISUAL_VER           = 8.0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = Cranelib.lib
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = Crane_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE      = NONE

#-- In the case when directory name contains space ---
!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

#--------------------------- Additional options -------------------------------

ASSERTACTION = "Stop model with an error"
HAVESTDIO = 1

#--------------------------- Tool Specifications ------------------------------

!include $(QUARC)\include\vctools.mak

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl

#------------------------------ Include/Lib Path ------------------------------

MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional file include paths (from rtwmakecfg.m functions)

MATLAB_INCLUDES = $(MATLAB_INCLUDES);D:\colinlea\COLINL~1\BARSYS~1\CRANE_~1
MATLAB_INCLUDES = $(MATLAB_INCLUDES);D:\colinlea\COLINL~1\BARSYS~1
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\libsrc
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\mech\c
MATLAB_INCLUDES = $(MATLAB_INCLUDES);C:\PROGRA~1\Quanser\QuaRC\include

QUARC_INCLUDES = $(QUARC)\include

INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(QUARC_INCLUDES);$(MATLAB_INCLUDES);$(ADD_INCLUDES);$(INCLUDE);$(MODELREF_INC_PATH)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)
!endif

#------------------------ External mode ---------------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
!if $(EXT_MODE) == 1
EXT_CC_OPTS = -DEXT_MODE -DMODEL_URI="$(MODEL_URI)" -DVERBOSE
!if $(EXTMODE_TRANSPORT) == 0 #quarc_comm
EXT_SRC =
EXT_LIB = extmode_quarc.lib quanser_communications.lib          
!endif
!if $(TMW_EXTMODE_TESTING) == 1
EXT_SRC     = $(EXT_SRC) ext_test.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DTMW_EXTMODE_TESTING
!endif
!if $(EXTMODE_STATIC) == 1
EXT_SRC     = $(EXT_SRC) mem_mgr.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
!endif
!else
EXT_SRC     =
EXT_CC_OPTS =
EXT_LIB     =
!endif

#
# .mat File Logging
#
!if "$(MAT_FILE)" == "1"
LOG_OPTS  = -DMAT_FILE
!endif

#------------------------ rtModel ----------------------------------------------

RTM_CC_OPTS = -DUSE_RTMODEL

#----------------- Compiler and Linker Options --------------------------------

# Optimization Options. The DEFAULT_OPT_OPTS macro depends on the build configuration.
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =

CC_OPTS = $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS) $(LOG_OPTS) $(RTM_CC_OPTS)

# msvcprt.lib is the multi--threaded, dynamic lib version of the C++ standard lib
# msvcprtd.lib is the multi--threaded, dynamic debug lib version of the C++ standard lib
# /EHsc enables exception handling (needed to use C++ standard lib)

!if "$(DEBUG)" == "1"
OPT_DEFINES =
CPP_LIB = msvcprtd.lib
!else
OPT_DEFINES = -DNDEBUG
CPP_LIB = msvcprt.lib
!endif

ACTION = $(ASSERTACTION:"Ignore"=0)
ACTION = $(ACTION:"Stop model with an error"=1)
ACTION = $(ACTION:"Print assertion"=2)

ASSERT_DEFINES = -DASSERTIONS=$(ACTION)
!if $(ACTION) > 0
ASSERT_DEFINES = $(ASSERT_DEFINES) -DDOASSERTS
!endif

!if $(HAVESTDIO)
STDIO_DEFINES = -DHAVESTDIO
!else
STDIO_DEFINES =
!endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
		  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
		  -DMULTITASKING=$(MULTITASKING) $(STDIO_DEFINES) \
		  -DVXWORKS -DQUARC -DTARGET_TYPE=windows \
		  -D_CRT_SECURE_NO_DEPRECATE $(ASSERT_DEFINES) \
		  $(OPT_DEFINES)

!if "$(DEBUG)" == "1"
NODEFAULTFLAGS = /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib \
                 /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcprt.lib
!else
NODEFAULTFLAGS = /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrtd.lib \
                 /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcprtd.lib
!endif

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS   = $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES) \
	   $(cflags) $(cvarsdll) $(CFLAGS_VERSPECIFIC)
CPPFLAGS = $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES) \
	   $(cflags) $(cvarsdll) $(CPPFLAGS_VERSPECIFIC)
LDFLAGS  = $(ldebug) $(conlflags) $(NODEFAULTFLAGS) $(EXT_LIB) $(conlibsdll) $(CPP_LIB) winmm.lib

#----------------------------- Source Files -----------------------------------


# Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL)$(TARGET_EXT)

!if "$(TARGET_LANG_EXT)" == "cpp"
MAIN_SRC = $(MODEL)_main.c
!else
MAIN_SRC =
!endif

REQ_SRCS  = $(MODEL).$(TARGET_LANG_EXT) $(MODULES) \
            $(MAIN_SRC) rt_sim.c $(EXT_SRC) $(SOLVER)

# Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES) $(EXT_SRC)
!endif

USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
SHARED_OBJS = $(SHARED_SRC:.c=.obj)

# ------------------------- Additional Object Files ---------------------------

#QUARC_OBJS = "$(QUARC)\lib\quarc_entry.obj"

# ------------------------- Additional Libraries ------------------------------

# Set library search path
LIB = $(QUARC)\lib\windows;$(LIB)

# Set QuaRC libraries
QUARC_LIBS = quanser_runtime.lib quanser_common.lib shell32.lib

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = 
LIBS = $(LIBS) "C:\DOCUME~1\ALLUSE~1\APPLIC~1\QuaRC\lib\2007b\windows\release\mech.lib"
LIBS = $(LIBS) "C:\DOCUME~1\ALLUSE~1\APPLIC~1\QuaRC\lib\2007b\windows\release\rtwlib.lib"
!else
LIBS = 
LIBS = $(LIBS) "mech.lib"
LIBS = $(LIBS) "rtwlib.lib"
!endif

# See rtwmakecfg.m documentation

LIBS = $(LIBS)

# ---------------------------- Linker Script ----------------------------------

CMD_FILE = $(MODEL).lk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

!if "$(DEBUG)" == "1"
MANIFEST_BASENAME=$(MODEL).Debug
!else
MANIFEST_BASENAME=$(MODEL)
!endif

#--------------------------------- Rules --------------------------------------
all: set_environment_variables $(PRODUCT)

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS) $(MANIFEST_BASENAME).auto.res
	@echo ### Linking ...
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS) $(MODELREF_LINK_LIBS)
	$(LD) $(LDFLAGS) /MANIFESTFILE:$(MODEL).manifest $(QUARC_OBJS) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) $(QUARC_LIBS) $(CRT_LIB) -out:$@
	@if exist $(MODEL).manifest \
		$(MT) -nologo -manifest $(MODEL).manifest -out:$(MANIFEST_BASENAME).auto.manifest \
		& if "%ERRORLEVEL%" == "0" \
			$(RC) /r $(MANIFEST_BASENAME).auto.rc \
			& $(LD) $(LDFLAGS) /MANIFESTFILE:$(MODEL).manifest $(QUARC_OBJS) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) $(QUARC_LIBS) $(CRT_LIB) $(MANIFEST_BASENAME).auto.res -out:$@
	@del $(CMD_FILE)
	@echo $(BUILD_SUCCESS) executable $(MODEL)$(TARGET_EXT)
!else
#--- Model reference RTW Target ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS)
	@echo ### Linking ...
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB)
	@echo $(BUILD_SUCCESS) static library $(MODELLIB)
!endif

{$(QUARC)\quarc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(QUARC)\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\tcpip}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\serial}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\custom}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(QUARC)\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

# Additional sources. See rtwmakecfg.m documentation.

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\mech\c}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\mech\mech}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\libsrc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\mech\c}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\mech\mech}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\libsrc}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

# Put these rule last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@echo ### Creating $@
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ @<<
$?
<<
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@echo ### $@ Created
!endif


set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries. See rtwmakecfg.m documentation.



MODULES_mech = \
	mech_00006e65.obj \
	mech_0007b2a9.obj \
	mech_000ed056.obj \
	mech_01d87d3a.obj \
	mech_026a2d99.obj \
	mech_03b136ec.obj \
	mech_03bb34d9.obj \
	mech_03bb3c6d.obj \
	mech_04d5988f.obj \
	mech_04dd4c5e.obj \
	mech_06b3bf64.obj \
	mech_06b9086b.obj \
	mech_06bedb25.obj \
	mech_07671538.obj \
	mech_0767724b.obj \
	mech_0862eda6.obj \
	mech_086533bb.obj \
	mech_09b19182.obj \
	mech_09b1fec0.obj \
	mech_0bd00907.obj \
	mech_0bd0b77a.obj \
	mech_0bd10737.obj \
	mech_0bd2b991.obj \
	mech_0bd664f2.obj \
	mech_0bd7d25b.obj \
	mech_0cb0c361.obj \
	mech_0cb6ce08.obj \
	mech_0d650488.obj \
	mech_0d66d17e.obj \
	mech_0ed451b2.obj \
	mech_0ed45902.obj \
	mech_0ed45e06.obj \
	mech_0f089acf.obj \
	mech_0f0fff67.obj \
	mech_10d1a830.obj \
	mech_10dbc42c.obj \
	mech_1101d608.obj \
	mech_12bb508a.obj \
	mech_136d4516.obj \
	mech_136ff8ec.obj \
	mech_14033882.obj \
	mech_15d7fd16.obj \
	mech_166ecc83.obj \
	mech_17b3d969.obj \
	mech_17b5d2c8.obj \
	mech_18b74dc4.obj \
	mech_18bc4c78.obj \
	mech_19668514.obj \
	mech_1968edfa.obj \
	mech_196a81d3.obj \
	mech_196d5583.obj \
	mech_196f54b3.obj \
	mech_1ad1d08f.obj \
	mech_1ad8beb5.obj \
	mech_1ada66bb.obj \
	mech_1adadbd7.obj \
	mech_1adc0f49.obj \
	mech_1c60663f.obj \
	mech_1dbace12.obj \
	mech_1dbda3ff.obj \
	mech_1dbe1d9c.obj \
	mech_1e064a3f.obj \
	mech_1fd889d5.obj \
	mech_1fda8b96.obj \
	mech_1fdced41.obj \
	mech_206c58ce.obj \
	mech_206c8603.obj \
	mech_21b84b43.obj \
	mech_2205ccb7.obj \
	mech_220ec111.obj \
	mech_220f714b.obj \
	mech_23d70961.obj \
	mech_23dbb21d.obj \
	mech_24b71ad9.obj \
	mech_24b77237.obj \
	mech_24bb1149.obj \
	mech_24bba50d.obj \
	mech_24bfa08f.obj \
	mech_2567641e.obj \
	mech_256cde98.obj \
	mech_26d4ef1c.obj \
	mech_26d886a3.obj \
	mech_26db8855.obj \
	mech_26df8d12.obj \
	mech_28020b37.obj \
	mech_2802698b.obj \
	mech_280501aa.obj \
	mech_29d37a28.obj \
	mech_2a654443.obj \
	mech_2bb05015.obj \
	mech_2bba5516.obj \
	mech_2bbc8c68.obj \
	mech_2cd84f8c.obj \
	mech_2cdd985a.obj \
	mech_2d025ffd.obj \
	mech_2d0aed76.obj \
	mech_2eb2b298.obj \
	mech_2eb66379.obj \
	mech_2ebc07de.obj \
	mech_2ebebb91.obj \
	mech_30b648ac.obj \
	mech_31653540.obj \
	mech_316a3f58.obj \
	mech_32d20288.obj \
	mech_32d56014.obj \
	mech_32d9db4c.obj \
	mech_32de0762.obj \
	mech_3304c804.obj \
	mech_3305a484.obj \
	mech_330d7bc3.obj \
	mech_3462babe.obj \
	mech_35b51c4f.obj \
	mech_35b5cace.obj \
	mech_35b77254.obj \
	mech_35b915fd.obj \
	mech_35bec0a8.obj \
	mech_360546c6.obj \
	mech_360c2aa1.obj \
	mech_37d552b9.obj \
	mech_38d7a7ef.obj \
	mech_3901d369.obj \
	mech_39096856.obj \
	mech_390c6b4e.obj \
	mech_390e6b5a.obj \
	mech_3abc86c0.obj \
	mech_3abf521c.obj \
	mech_3b61901a.obj \
	mech_3b639cf6.obj \
	mech_3b6df100.obj \
	mech_3c0639b9.obj \
	mech_3c0839c5.obj \
	mech_3c0987b6.obj \
	mech_3c0c580b.obj \
	mech_3c0c5fd8.obj \
	mech_3dd0930b.obj \
	mech_3dd1969f.obj \
	mech_3ddb25c6.obj \
	mech_3ddbffa6.obj \
	mech_3ddd2456.obj \
	mech_3e60c0e6.obj \
	mech_3fbd66a7.obj \
	mech_4108afbe.obj \
	mech_4109157a.obj \
	mech_410bc4f2.obj \
	mech_410bc65c.obj \
	mech_42b09df4.obj \
	mech_42be9678.obj \
	mech_436631a7.obj \
	mech_440c2ed8.obj \
	mech_440d22de.obj \
	mech_440e9e4b.obj \
	mech_45d03616.obj \
	mech_4662030c.obj \
	mech_4667dbb7.obj \
	mech_4669043e.obj \
	mech_47b2a55c.obj \
	mech_47bf135b.obj \
	mech_48b789cc.obj \
	mech_4960f2f1.obj \
	mech_4ad07741.obj \
	mech_4adca3e0.obj \
	mech_4adca419.obj \
	mech_4adcc3ed.obj \
	mech_4adfc9a4.obj \
	mech_4b05b87a.obj \
	mech_4b060957.obj \
	mech_4b0e0291.obj \
	mech_4e0282f0.obj \
	mech_4e095d4e.obj \
	mech_4e0b5f0d.obj \
	mech_4e0f5c6a.obj \
	mech_4fd44d66.obj \
	mech_50071041.obj \
	mech_500a181b.obj \
	mech_51d06e5d.obj \
	mech_51d0d7b4.obj \
	mech_51d16f25.obj \
	mech_51dedbfe.obj \
	mech_52638b20.obj \
	mech_5265e44f.obj \
	mech_53b499b4.obj \
	mech_53b926f6.obj \
	mech_53bb4a1e.obj \
	mech_53bbf9bf.obj \
	mech_54d28978.obj \
	mech_54d28f65.obj \
	mech_54d33844.obj \
	mech_54db5fea.obj \
	mech_550dfb7b.obj \
	mech_56bda6f0.obj \
	mech_5760b8b3.obj \
	mech_586346cf.obj \
	mech_586c9b48.obj \
	mech_586cfb14.obj \
	mech_59b4e720.obj \
	mech_59b5542b.obj \
	mech_59b9ec0f.obj \
	mech_5cb80b48.obj \
	mech_5cbbb213.obj \
	mech_5f065a28.obj \
	mech_60b13b67.obj \
	mech_60b6e6b2.obj \
	mech_616827f3.obj \
	mech_62d1c262.obj \
	mech_6462c322.obj \
	mech_65b2670b.obj \
	mech_65b2d1f7.obj \
	mech_65b36df8.obj \
	mech_65bf06d4.obj \
	mech_67d04c46.obj \
	mech_67d244f0.obj \
	mech_67d54f32.obj \
	mech_67df977c.obj \
	mech_68d36d56.obj \
	mech_69081e4f.obj \
	mech_6ab1f394.obj \
	mech_6ab52289.obj \
	mech_6ab5f9a4.obj \
	mech_6b635a65.obj \
	mech_6b65599b.obj \
	mech_6b66390f.obj \
	mech_6b6c87b1.obj \
	mech_6c044da2.obj \
	mech_6c04f91c.obj \
	mech_6c06477b.obj \
	mech_6c0c4edb.obj \
	mech_6dd15c06.obj \
	mech_6dd532a0.obj \
	mech_6dd6eb16.obj \
	mech_6dde8c98.obj \
	mech_6fb01ff1.obj \
	mech_6fb8192c.obj \
	mech_6fbac67b.obj \
	mech_71baeedc.obj \
	mech_71bc5898.obj \
	mech_71bd8c55.obj \
	mech_720404ec.obj \
	mech_73d11bf4.obj \
	mech_73d21206.obj \
	mech_73d2a9d1.obj \
	mech_73d3ca8d.obj \
	mech_73dd73bb.obj \
	mech_73de785a.obj \
	mech_73df700a.obj \
	mech_74b20fb1.obj \
	mech_75637fd1.obj \
	mech_76d29623.obj \
	mech_79d0d97f.obj \
	mech_79d8061f.obj \
	mech_79debe9e.obj \
	mech_7a67e49e.obj \
	mech_7bb22415.obj \
	mech_7bba295f.obj \
	mech_7cd6efca.obj \
	mech_7cdae70c.obj \
	mech_7d044d4c.obj \
	mech_7d0d2988.obj \
	mech_7f6301ee.obj \
	mech_7f65b297.obj \
	mech_7f6cd5da.obj \
	mech_7f6f03ea.obj \
	mech_8064658e.obj \
	mech_806a6ff9.obj \
	mech_806ab471.obj \
	mech_81b010a6.obj \
	mech_81b2a7ec.obj \
	mech_81b31a70.obj \
	mech_81b3c62c.obj \
	mech_8202fad3.obj \
	mech_83db3577.obj \
	mech_84bdfd5b.obj \
	mech_8565e0ad.obj \
	mech_8567868b.obj \
	mech_856c886e.obj \
	mech_856feaf6.obj \
	mech_86d46dbd.obj \
	mech_86d803ff.obj \
	mech_86dcdc59.obj \
	mech_87031b9f.obj \
	mech_88015fa4.obj \
	mech_89d6ff6d.obj \
	mech_89df22b4.obj \
	mech_8bb6b456.obj \
	mech_8bb8da3f.obj \
	mech_8bbad533.obj \
	mech_8cd5ce68.obj \
	mech_8cdaa057.obj \
	mech_8cdd1bcd.obj \
	mech_8cde1353.obj \
	mech_8d01d08a.obj \
	mech_8d03b8e5.obj \
	mech_8d070edf.obj \
	mech_8d0bba30.obj \
	mech_8d0c037b.obj \
	mech_8d0f0713.obj \
	mech_8eba5477.obj \
	mech_8f654afc.obj \
	mech_90b0a5f4.obj \
	mech_90bd1984.obj \
	mech_9166b82a.obj \
	mech_9166d09b.obj \
	mech_916cb416.obj \
	mech_92d4853c.obj \
	mech_92d632c3.obj \
	mech_92d68cce.obj \
	mech_93002c63.obj \
	mech_93094c9e.obj \
	mech_94648110.obj \
	mech_946656b0.obj \
	mech_94693390.obj \
	mech_95b19739.obj \
	mech_95b59b14.obj \
	mech_95bf2300.obj \
	mech_960d79d4.obj \
	mech_97d304eb.obj \
	mech_98d02fb0.obj \
	mech_98d24db5.obj \
	mech_99015504.obj \
	mech_9ab6d772.obj \
	mech_9b611ed7.obj \
	mech_9b6aa470.obj \
	mech_9c046ba4.obj \
	mech_9dd3a3a7.obj \
	mech_9e649e52.obj \
	mech_9e6b9488.obj \
	mech_9fb0e687.obj \
	mech_9fbe31aa.obj \
	mech_9fbf5b04.obj \
	mech_9fbf8306.obj \
	mech_a0023621.obj \
	mech_a005e178.obj \
	mech_a1da4224.obj \
	mech_a1df4d1a.obj \
	mech_a2667e73.obj \
	mech_a266ca1b.obj \
	mech_a3b26127.obj \
	mech_a3bfd9f2.obj \
	mech_a4dca94e.obj \
	mech_a505d923.obj \
	mech_a5066f03.obj \
	mech_a50fbcc4.obj \
	mech_a6b05f4b.obj \
	mech_a6bd35b2.obj \
	mech_a6beeef9.obj \
	mech_a76b42bc.obj \
	mech_a76ef767.obj \
	mech_a76ffdc2.obj \
	mech_a865b9aa.obj \
	mech_a867be74.obj \
	mech_a9b3a416.obj \
	mech_a9bc1b9d.obj \
	mech_a9bdc32c.obj \
	mech_aa0594f2.obj \
	mech_aa07f0ff.obj \
	mech_aa0b9657.obj \
	mech_abd5e763.obj \
	mech_abd7ebac.obj \
	mech_abdbe416.obj \
	mech_acb043d9.obj \
	mech_acb0f0ee.obj \
	mech_acb29993.obj \
	mech_acb2f87a.obj \
	mech_acb8f1da.obj \
	mech_acbd4167.obj \
	mech_ad678530.obj \
	mech_ad6a8807.obj \
	mech_aed4b64f.obj \
	mech_aed8baf4.obj \
	mech_af00a969.obj \
	mech_af07c7d7.obj \
	mech_b0d42cb2.obj \
	mech_b0d59e1e.obj \
	mech_b0d89f46.obj \
	mech_b100583f.obj \
	mech_b1018990.obj \
	mech_b2b7b649.obj \
	mech_b2b80846.obj \
	mech_b36315a9.obj \
	mech_b36ece21.obj \
	mech_b36fa760.obj \
	mech_b409d050.obj \
	mech_b409dc44.obj \
	mech_b5dea0b1.obj \
	mech_b5dfa5d8.obj \
	mech_b66922b9.obj \
	mech_b66cf26c.obj \
	mech_b7ba32a8.obj \
	mech_b7bd5732.obj \
	mech_b965b86f.obj \
	mech_bad55464.obj \
	mech_bad5e786.obj \
	mech_bad95da7.obj \
	mech_bade89b1.obj \
	mech_bb00f157.obj \
	mech_bb044a51.obj \
	mech_bb0af744.obj \
	mech_bb0f2ab6.obj \
	mech_bc60369d.obj \
	mech_bc6355a7.obj \
	mech_bc638738.obj \
	mech_bc68822a.obj \
	mech_bc6c3377.obj \
	mech_bdbb4131.obj \
	mech_bdbdf636.obj \
	mech_be0ec8ca.obj \
	mech_bfd0d6a6.obj \
	mech_bfd2be09.obj \
	mech_bfd5d0aa.obj \
	mech_bfda09ef.obj \
	mech_bfdbdf48.obj \
	mech_c0b0b0fc.obj \
	mech_c0b76cb1.obj \
	mech_c0bab1b4.obj \
	mech_c0bf0ba2.obj \
	mech_c161c8f2.obj \
	mech_c166a924.obj \
	mech_c16a7c99.obj \
	mech_c16ac570.obj \
	mech_c2dc44de.obj \
	mech_c30e5a9e.obj \
	mech_c5b480c3.obj \
	mech_c5b53393.obj \
	mech_c608b9a8.obj \
	mech_c7dbcb47.obj \
	mech_c7dec30e.obj \
	mech_c8d589be.obj \
	mech_c8dce154.obj \
	mech_c8dce289.obj \
	mech_cab31321.obj \
	mech_cabc1f51.obj \
	mech_cabec90c.obj \
	mech_cc01ab49.obj \
	mech_ce68e76d.obj \
	mech_cfb5943b.obj \
	mech_cfb7fd53.obj \
	mech_d06212b7.obj \
	mech_d0627877.obj \
	mech_d067c907.obj \
	mech_d06c1589.obj \
	mech_d06ec12b.obj \
	mech_d20583ec.obj \
	mech_d3de49fd.obj \
	mech_d4b0e3ce.obj \
	mech_d4b63106.obj \
	mech_d4bf89ad.obj \
	mech_d6d41a0e.obj \
	mech_d709d89a.obj \
	mech_d70a6366.obj \
	mech_d70edcee.obj \
	mech_d8009864.obj \
	mech_d80122e1.obj \
	mech_d803970f.obj \
	mech_d8052afe.obj \
	mech_d805f7c4.obj \
	mech_d9d2e660.obj \
	mech_da606c44.obj \
	mech_da64d0eb.obj \
	mech_da6705de.obj \
	mech_da676a1c.obj \
	mech_da67d7de.obj \
	mech_dcdfbc35.obj \
	mech_dd02c6d0.obj \
	mech_dd0a7654.obj \
	mech_deb8fc9e.obj \
	mech_deb921be.obj \
	mech_df63e657.obj \
	mech_df648470.obj \
	mech_df6ee64b.obj \
	mech_e0d48ef5.obj \
	mech_e0d586d0.obj \
	mech_e10194d9.obj \
	mech_e1072c0e.obj \
	mech_e109fba1.obj \
	mech_e10a9195.obj \
	mech_e10e2e0e.obj \
	mech_e2b01603.obj \
	mech_e2b2cdb3.obj \
	mech_e2b5107a.obj \
	mech_e2b611cd.obj \
	mech_e2ba15be.obj \
	mech_e360bd67.obj \
	mech_e362637b.obj \
	mech_e367bb32.obj \
	mech_e40bcae0.obj \
	mech_e5d602c8.obj \
	mech_e5d9dae2.obj \
	mech_e5dfd66e.obj \
	mech_e6625355.obj \
	mech_e6635189.obj \
	mech_e7b426cd.obj \
	mech_e8beb74f.obj \
	mech_e9611264.obj \
	mech_e962a4b0.obj \
	mech_e96417d4.obj \
	mech_ead79cd6.obj \
	mech_eade219a.obj \
	mech_eade250c.obj \
	mech_eb03e71e.obj \
	mech_eb0b802a.obj \
	mech_eb0c589e.obj \
	mech_eb0ce008.obj \
	mech_ec63f9ff.obj \
	mech_ec66986d.obj \
	mech_ec67921f.obj \
	mech_ec6c45a1.obj \
	mech_edbd33c5.obj \
	mech_ee09b802.obj \
	mech_ee0a6df6.obj \
	mech_ee0bdc78.obj \
	mech_ee0f0a98.obj \
	mech_efd278dd.obj \
	mech_efd71c85.obj \
	mech_f1d435e3.obj \
	mech_f1d68a38.obj \
	mech_f1d85ae0.obj \
	mech_f1dee442.obj \
	mech_f1deeea4.obj \
	mech_f264d6f3.obj \
	mech_f3bea1d4.obj \
	mech_f3bfa70e.obj \
	mech_f4d005a3.obj \
	mech_f4d168d2.obj \
	mech_f4d4bd71.obj \
	mech_f4d9b522.obj \
	mech_f50418a0.obj \
	mech_f505a4af.obj \
	mech_f50611c4.obj \
	mech_f50d14d1.obj \
	mech_f50d7704.obj \
	mech_f6b24719.obj \
	mech_f6be2959.obj \
	mech_f760804c.obj \
	mech_f76381a2.obj \
	mech_f76585cd.obj \
	mech_f76c3512.obj \
	mech_f76f37e6.obj \
	mech_f8691088.obj \
	mech_f9b00ceb.obj \
	mech_f9b46bf1.obj \
	mech_fa028b96.obj \
	mech_fa0687e9.obj \
	mech_fcb6e96a.obj \
	mech_fcb88991.obj \
	mech_fcbce350.obj \
	mech_fd6223f1.obj \
	mech_ff04dc33.obj \
	mech_ff06b064.obj \
	mech_ff06b6e1.obj \
	mech_ff0ed07b.obj \


mech.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_mech)
	@echo ### Creating $@
	$(LIBCMD) /nologo /out:$@ $(MODULES_mech)
	@echo ### $@ Created

MODULES_rtwlib = \
	rt_backsubcc_dbl.obj \
	rt_backsubcc_sgl.obj \
	rt_backsubrc_dbl.obj \
	rt_backsubrc_sgl.obj \
	rt_backsubrr_dbl.obj \
	rt_backsubrr_sgl.obj \
	rt_enab.obj \
	rt_forwardsubcc_dbl.obj \
	rt_forwardsubcc_sgl.obj \
	rt_forwardsubcr_dbl.obj \
	rt_forwardsubcr_sgl.obj \
	rt_forwardsubrc_dbl.obj \
	rt_forwardsubrc_sgl.obj \
	rt_forwardsubrr_dbl.obj \
	rt_forwardsubrr_sgl.obj \
	rt_look.obj \
	rt_look1d.obj \
	rt_look1d32.obj \
	rt_look2d32_general.obj \
	rt_look2d32_normal.obj \
	rt_look2d_general.obj \
	rt_look2d_normal.obj \
	rt_look32.obj \
	rt_lu_cplx.obj \
	rt_lu_cplx_sgl.obj \
	rt_lu_real.obj \
	rt_lu_real_sgl.obj \
	rt_matdivcc_dbl.obj \
	rt_matdivcc_sgl.obj \
	rt_matdivcr_dbl.obj \
	rt_matdivcr_sgl.obj \
	rt_matdivrc_dbl.obj \
	rt_matdivrc_sgl.obj \
	rt_matdivrr_dbl.obj \
	rt_matdivrr_sgl.obj \
	rt_matmultandinccc_dbl.obj \
	rt_matmultandinccc_sgl.obj \
	rt_matmultandinccr_dbl.obj \
	rt_matmultandinccr_sgl.obj \
	rt_matmultandincrc_dbl.obj \
	rt_matmultandincrc_sgl.obj \
	rt_matmultandincrr_dbl.obj \
	rt_matmultandincrr_sgl.obj \
	rt_matmultcc_dbl.obj \
	rt_matmultcc_sgl.obj \
	rt_matmultcr_dbl.obj \
	rt_matmultcr_sgl.obj \
	rt_matmultrc_dbl.obj \
	rt_matmultrc_sgl.obj \
	rt_matmultrr_dbl.obj \
	rt_matmultrr_sgl.obj \
	rt_sat_div_int16.obj \
	rt_sat_div_int32.obj \
	rt_sat_div_int8.obj \
	rt_sat_div_uint16.obj \
	rt_sat_div_uint32.obj \
	rt_sat_div_uint8.obj \
	rt_sat_prod_int16.obj \
	rt_sat_prod_int32.obj \
	rt_sat_prod_int8.obj \
	rt_sat_prod_uint16.obj \
	rt_sat_prod_uint32.obj \
	rt_sat_prod_uint8.obj \


rtwlib.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_rtwlib)
	@echo ### Creating $@
	$(LIBCMD) /nologo /out:$@ $(MODULES_rtwlib)
	@echo ### $@ Created



#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(MANIFEST_BASENAME).auto.res:	$(MANIFEST_BASENAME).auto.rc

$(MANIFEST_BASENAME).auto.rc:	$(MANIFEST_BASENAME).auto.manifest
	@type > nul: <<$@
#include <winuser.h>
1 RT_MANIFEST "$(MANIFEST_BASENAME).auto.manifest"
<< KEEP

$(MANIFEST_BASENAME).auto.manifest:
	@type > nul: <<$@
<?xml version='1.0' encoding='UTF-8' standalone='yes'?>
<assembly xmlns='urn:schemas-microsoft-com:asm.v1' manifestVersion='1.0'>
  <ms_asmv2:trustInfo xmlns:ms_asmv2="urn:schemas-microsoft-com:asm.v2">
      <ms_asmv2:security>
         <ms_asmv2:requestedPrivileges>
            <ms_asmv2:requestedExecutionLevel level="asInvoker" uiAccess="false">
            </ms_asmv2:requestedExecutionLevel>
         </ms_asmv2:requestedPrivileges>
      </ms_asmv2:security>
   </ms_asmv2:trustInfo>
</assembly>
<< KEEP
	