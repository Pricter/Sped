echo "Building everything..."

make -f Makefile.engine.linux.mak all

ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then
echo "Error:"$ERRORLEVEL
fi

make -f Makefile.test.linux.mak all
ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then