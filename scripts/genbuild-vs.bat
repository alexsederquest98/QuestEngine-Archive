::del /Q build
cmake -B build . -T clangcl -G "Visual Studio 17 2022"
PAUSE