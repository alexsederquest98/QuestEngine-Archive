del /Q build
::cmake -B build -S . -G "Ninja" 
cmake -B build -S .. -DCMAKE_CXX_COMPILER:FILEPATH="C:/Program Files/LLVM/bin/clang.exe" -DCMAKE_C_COMPILER:FILEPATH="C:/Program Files/LLVM/bin/clang.exe" -DCMAKE_LINKER:FILEPATH="C:/Program Files/LLVM/bin/lld-link.exe" -G"Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=1
PAUSE