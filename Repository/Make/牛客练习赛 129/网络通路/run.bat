@echo off
cd %~dp0
echo Compiling...
g++ std.cpp -o std -w -O2
g++ wa.cpp -o wa -w -O2
echo Compiled!
for /l %%a in (1,1,15) do (
	echo %%a
	std.exe < %%a.in > %%a.out
)