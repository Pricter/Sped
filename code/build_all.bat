@ECHO OFF

ECHO "Building everything..."

cd engine
CALL build.bat
cd ..
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

cd test
CALL build.bat
cd ..
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

ECHO "ALL assemblies built successfully"