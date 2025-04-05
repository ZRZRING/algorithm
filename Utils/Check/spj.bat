@echo off
g++ in.cpp -o in -w -Wl,--stack=19198101 -std=c++17 -O2
g++ wa.cpp -o wa -w -Wl,--stack=19198101 -std=c++17 -O2
g++ std.cpp -o std -w -Wl,--stack=19198101 -std=c++17 -O2
g++ checker.cc -o checker -w -Wl,--stack=19198101 -std=c++17 -O2
for /l %%a in (1,1,100000) do (
	echo %%a
	in.exe > in.txt
	wa.exe < in.txt > wa.txt
	std.exe < wa.txt > std.txt
	checker.exe in.txt wa.txt std.txt
	if errorlevel 1 pause
)
:ed