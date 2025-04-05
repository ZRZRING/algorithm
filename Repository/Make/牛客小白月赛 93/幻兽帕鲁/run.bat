@echo off
cd %~dp0
echo Compiling...
g++ std.cpp -o std -w -O2
echo Compiled!
for /l %%a in (1,1,7) do (
	echo %%a
	g++ data%%a.cpp -o data%%a
	data%%a.exe > %%a.in
	std.exe < %%a.in > %%a.out
)