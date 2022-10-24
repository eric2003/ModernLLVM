clang -emit-llvm -S -c ../main.c -O3 main.ll
d:\work\llvm_work\llvm-project\build\Debug\bin\llc.exe main.ll
clang main.s -mllvm -Wall -g -Wl,-pie -o main.exe
clang main.s -mllvm -Wall -g -Wl,pie -o main.exe
clang main.s -mllvm -Wall -g -Wl -o main.exe
clang main.s -mllvm -g -Wl -o main.exe
clang main.s -mllvm -Wl -o main.exe
clang main.s -mllvm -o main.exe

nasm.exe -f win64 ./main.s -o ./main.obj