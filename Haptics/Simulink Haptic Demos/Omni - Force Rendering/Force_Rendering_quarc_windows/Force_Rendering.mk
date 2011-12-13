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


MODEL                = Force_Rendering
MODULES              = Force_Rendering_data.c Force_Rendering_main.c rt_nonfinite.c 
MAKEFILE             = Force_Rendering.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2007b
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2007b
MATLAB_BIN           = C:\Program Files\MATLAB\R2007b\bin
ALT_MATLAB_BIN       = C:\PROGRA~1\MATLAB\R2007b\bin
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = C:\PROGRA~1\Quanser\QuaRC\lib\windows\hil.lib C:\PROGRA~1\Quanser\QuaRC\lib\windows\QUANSE~4.LIB C:\PROGRA~1\Quanser\QuaRC\lib\windows\QUANSE~3.LIB
SOLVER               = 
NUMST                = 1
TID01EQ              = 0
NCSTATES             = 0
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
MODELLIB                  = Force_Renderinglib.lib
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = Force_Rendering_ref.rsp
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

MATLAB_INCLUDES = $(MATLAB_INCLUDES);D:\colinlea\Finish\OTHERD~1\FORCE_~1
MATLAB_INCLUDES = $(MATLAB_INCLUDES);D:\colinlea\Finish\OTHERD~1
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\libsrc
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
LIBS = $(LIBS) "C:\DOCUME~1\ALLUSE~1\APPLIC~1\QuaRC\lib\2007b\windows\release\rtwlib.lib"
!else
LIBS = 
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

{$(MATLAB_ROOT)\rtw\c\libsrc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
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
	