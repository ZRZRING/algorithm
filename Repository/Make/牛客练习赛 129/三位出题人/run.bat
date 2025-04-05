echo off
cd %~dp0
g++ std.cpp -o std -std=c++20 -O2
for /l %%i in (1, 1, 2) do (
	echo %%i
	g++ data%%i.cpp -o data%%i -std=c++20 -O2
	data%%i.exe > %%i.in
	std.exe < %%i.in > %%i.out
)