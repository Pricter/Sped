@ECHO OFF
SetLocal EnableDelayedExpansion

SET cFilenames=
FOR /R %%f in (*.c) do (SET cFilenames=!cFilenames! %%f)

echo "Files:" %cFilenames%

SET assembly=tests
SET compilerFlags=-g -Wno-missing-braces
REM -Wall -Werror -save-temps=obj -O0
SET includeFlags=-Isrc -I../engine/src/
SET linkerFlags=-L../bin/ -lengine.lib
SET defines=-D_DEBUG -DSPEDIMPORT

ECHO "Building %assembly%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%