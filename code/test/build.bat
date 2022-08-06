@ECHO OFF
SetLocal EnableDelayedExpansion

SET cFilenames=
FOR /R %%f in (*.c) do (
    SET cFilenames=!cFilenames! %%f
)

SET assembly=test
SET compilerFlags=-g 
REM -Wall -Werror
SET includeFlags=-Isrc -I../engine/src/
SET linkerFlags=-L../bin/ -lengine.lib
SET defines=-D_DEBUG -DKIMPORT

ECHO "Building %assembly%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%