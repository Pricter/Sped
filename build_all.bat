ECHO "Building everything..."

@REM PUSHD engine
@REM CALL build.bat
@REM POPD
@REM IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

@REM PUSHD testbed
@REM CALL build.bat
@REM POPD
@REM IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

REM Engine
make -f "Makefile.engine.windows.mak" all
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL%)

REM Test
make -f "Makefile.test.windows.mak" all
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL%)

ECHO "All assemblies built successfully."