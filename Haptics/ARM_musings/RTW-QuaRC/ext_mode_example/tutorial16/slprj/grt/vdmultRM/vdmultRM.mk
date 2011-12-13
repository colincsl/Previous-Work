# Copyright 1994-2007 The MathWorks, Inc.
#
# File    : grt_vc.tmf   $Revision: 1.71.4.24 $
#
# Abstract:
#       Real-Time Workshop template makefile for building a Windows-based
#       stand-alone generic real-time version of Simulink model using
#       generated C code and the
#          Microsoft Visual C/C++ compiler versions: 6.0, 7.1, 8.0
#
#       Note that this template is automatically customized by the Real-Time
#       Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#         OPT_OPTS       - Optimization option. See DEFAULT_OPT_OPTS in
#                          vctools.mak for default.
#         OPTS           - User specific options.
#         CPP_OPTS       - C++ compiler options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         specify OPT_OPTS=-Zd 
#         modify tmf LDFLAGS to include /DEBUG
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = nmake
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = grt.tlc
BUILD_SUCCESS	= ^#^#^# Created
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
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  MEX_OPT_FILE        - mex option file name
#  VISUAL_VER          - Visual C++ version information

MODEL                = vdmultRM
MODULES              = vdmultRM.c 
MAKEFILE             = vdmultRM.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2007b
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2007b
MATLAB_BIN           = C:\Program Files\MATLAB\R2007b\bin
ALT_MATLAB_BIN       = C:\PROGRA~1\MATLAB\R2007b\bin
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = 
SOLVER               = 
NUMST                = 1
TID01EQ              = 0
NCSTATES             = 0
BUILDARGS            =  GENERATE_REPORT=0
MULTITASKING         = 0
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MODELREFS            = 
SHARED_SRC           = ..\..\..\slprj\grt\_sharedutils\*.c*
SHARED_SRC_DIR       = ..\..\..\slprj\grt\_sharedutils
SHARED_BIN_DIR       = ..\..\..\slprj\grt\_sharedutils
SHARED_LIB           = ..\..\..\slprj\grt\_sharedutils\rtwshared.lib
TARGET_LANG_EXT      = c
MEX_OPT_FILE         = -f "$(MATLAB_BIN)\$(ML_ARCH)\mexopts\msvc80opts.bat"
VISUAL_VER           = 8.0
OPTIMIZATION_FLAGS   = /Od /Oy- /DNDEBUG

#--------------------------- Model and reference models -----------------------
MODELLIB                  = vdmultRM_rtwlib.lib
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = vdmultRM_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..\..\..
MODELREF_TARGET_TYPE      = RTW

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

#--------------------------- Tool Specifications ------------------------------

!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl
#------------------------------ Include/Lib Path ------------------------------

MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional file include paths

MATLAB_INCLUDES = $(MATLAB_INCLUDES);D:\colinlea\RTW\ext_mode_example\tutorial16\slprj\grt\vdmultRM
MATLAB_INCLUDES = $(MATLAB_INCLUDES);D:\colinlea\RTW\ext_mode_example\tutorial16
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\libsrc

INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(MATLAB_INCLUDES);$(INCLUDE)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)
!endif

#------------------------ External mode ---------------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
!if $(EXT_MODE) == 1
EXT_CC_OPTS = -DEXT_MODE # -DVERBOSE
!if $(EXTMODE_TRANSPORT) == 0 #tcpip
EXT_SRC = ext_svr.c updown.c ext_work.c ext_svr_tcpip_transport.c
EXT_LIB = wsock32.lib
!endif
!if $(EXTMODE_TRANSPORT) == 1 #serial_win32
EXT_SRC = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
EXT_SRC = $(EXT_SRC) ext_serial_pkt.c ext_serial_win32_port.c
EXT_LIB =
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

#------------------------ rtModel ----------------------------------------------

RTM_CC_OPTS = -DUSE_RTMODEL

#----------------- Compiler and Linker Options --------------------------------

# Optimization Options
#   Set  OPT_OPTS=-Zd  for debugging
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =

!if "$(OPTIMIZATION_FLAGS)" != ""
CC_OPTS = $(OPTIMIZATION_FLAGS) $(OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS)
!else
CC_OPTS = $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS)
!endif
CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
		  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
		  -DMT=$(MULTITASKING) -DHAVESTDIO 

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS   = $(MODELREF_INC_PATH) $(CC_OPTS) $(CPP_REQ_DEFINES)\
	   $(USER_INCLUDES) $(cflags) $(cvarsmt) $(CFLAGS_VERSPECIFIC)
CPPFLAGS = $(MODELREF_INC_PATH) $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) \
	   $(USER_INCLUDES) $(cflags) $(cvarsmt) $(CPPFLAGS_VERSPECIFIC)
LDFLAGS  = $(ldebug) $(conflags) $(EXT_LIB) $(conlibsmt) libcpmt.lib


# libcpmt.lib is the multi-threaded, static lib version of the C++ standard lib

#----------------------------- Source Files -----------------------------------


#Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).exe

REQ_SRCS  = $(MODEL).$(TARGET_LANG_EXT) $(MODULES) \
            grt_main.c rt_sim.c  $(SOLVER) $(EXT_SRC)

#Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)  $(EXT_SRC)
!endif

USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
SHARED_OBJS = $(SHARED_SRC:.c=.obj)
# ------------------------- Additional Libraries ------------------------------

LIBS =

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\rtw\c\lib\win32\rtwlib_vc.lib
!else
LIBS = $(LIBS) rtwlib.lib
!endif 

LIBS = $(LIBS)

# ---------------------------- Linker Script ----------------------------------

CMD_FILE = $(MODEL).lnk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

#--------------------------------- Rules --------------------------------------
all: set_environment_variables $(PRODUCT)

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) $(LDFLAGS) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@del $(CMD_FILE)
	@cmd /C "echo $(BUILD_SUCCESS) executable $(MODEL).exe"
!else
#--- Model reference RTW Target ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB)
	@cmd /C "echo $(BUILD_SUCCESS) static library $(MODELLIB)"
!endif

{$(MATLAB_ROOT)\rtw\c\grt}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\tcpip}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\serial}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\custom}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

# Additional sources

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\libsrc}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\libsrc}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

# Put these rule last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@cmd /C "echo ### Creating $@"
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ @<<
$?
<<
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@cmd /C "echo ### $@ Created"
!endif


set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries:



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
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_rtwlib)
	@cmd /C "echo ### $@ Created"



#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
