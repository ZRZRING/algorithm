@echo off
cd %~dp0
echo Compiling...
g++ C.cpp -o C -w -O2
g++ tmp.cpp -o tmp -w -O2
echo Compiled!
for /l %%a in (16,1,16) do (
	echo %%a > 1.in
	C.exe < 1.in > 1.out
	tmp.exe < 1.out
)