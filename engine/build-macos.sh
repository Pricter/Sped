set echo on

mkdir -p ../bin

cFilenames=$(find . -type f -name "*.c")

assembly="engine"
compilerFlags="-g -shared -fdeclspec -fPIC"
includeFlags="-Isrc -I$VULKAN_SDK/include"
linkerFlags="-lvulkan -lglfw -L$VULKAN_SDK/lib"
defines="-D_DEBUG -DSPEDEXPORT"

echo "Building $assembly..."
clang $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $includeFlags $linkerFlags