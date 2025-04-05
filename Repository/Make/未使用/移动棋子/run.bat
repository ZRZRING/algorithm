@echo off
cd %~dp0
echo Compiling...
g++ std.cpp -o std -w -std=c++20 -O2
echo Compiled!
for /l %%a in (1,1,2) do (
	echo %%a Running...
	g++ data%%a.cpp -o data%%a -w -std=c++20 -O2
	data%%a.exe > %%a.in
	std.exe < %%a.in > %%a.out
)