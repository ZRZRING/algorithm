@echo off
cd %~dp0
echo Compiling...
g++ data.cpp -o data -w -std=c++20 -O2
g++ E.cpp -o E -w -std=c++20 -O2
echo Compiled!
for /l %%a in (1,1,100000) do (
	echo %%a
	data.exe > 1.in
	E.exe < 1.in > 1.out
)