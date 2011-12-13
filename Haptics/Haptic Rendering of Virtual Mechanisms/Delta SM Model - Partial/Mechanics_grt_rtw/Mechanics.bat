set MATLAB=C:\Program Files\MATLAB\R2007b
set MSVCDir=c:\program files\microsoft visual studio 8\VC
set MSSdk=%MSSdk%
@if "%MSSdk%"=="" goto Usage1

"C:\Program Files\MATLAB\R2007b\rtw\bin\win32\envcheck" INCLUDE "%MSSdk%\include"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007b\rtw\bin\win32\envcheck" PATH "%MSSdk%\bin"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007b\rtw\bin\win32\envcheck" LIB "%MSSdk%\lib"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007b\rtw\bin\win32\envcheck" LIBPATH "%MSSdk%\lib"
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
call "C:\Program Files\MATLAB\R2007b\toolbox\rtw\rtw\private\vcvars32_800free.bat"

:make
cd .
nmake -f Mechanics.mk  GENERATE_REPORT=0
@if errorlevel 1 goto error_exit
exit /B 0

:Usage1
@echo Error: Build with MSVC 8.0 express edition requires MSSdk being defined as the location of Microsoft platformSDK installation.
@goto error_exit

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
