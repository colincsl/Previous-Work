set MATLAB=C:\Program Files\MATLAB\R2007b
set MSVCDir=c:\program files\microsoft visual studio 8\VC

"C:\Program Files\MATLAB\R2007b\rtw\bin\win32\envcheck" INCLUDE "c:\program files\microsoft visual studio 8\VC\platformsdk\include"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007b\rtw\bin\win32\envcheck" INCLUDE "c:\program files\microsoft visual studio 8\VC\include"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007b\rtw\bin\win32\envcheck" PATH "c:\program files\microsoft visual studio 8\VC\bin"
if errorlevel 1 goto vcvars32
goto make

:vcvars32
set VSINSTALLDIR=c:\program files\microsoft visual studio 8
set VCINSTALLDIR=c:\program files\microsoft visual studio 8\VC
set FrameworkSDKDir=c:\program files\microsoft visual studio 8\SDK\v2.0
set FrameworkDir=c:\program files\microsoft visual studio 8\Framework
call "C:\Program Files\MATLAB\R2007b\toolbox\rtw\rtw\private\vcvars32_800.bat"

:make
cd .
nmake -f server.mk  GENERATE_REPORT=0 MAT_FILE=0 DEBUG=0
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
