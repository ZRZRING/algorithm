@echo off
g++ std.cpp -o std -w -Wl,--stack=19198101 -std=c++17 -O2
for /l %%a in (1, 1, 5) do (
	echo %%a
	std.exe < %%a.in > %%a.out
)
:ed