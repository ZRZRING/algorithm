echo off
g++ data.cpp -o data
g++ wa.cpp -o wa
g++ std.cpp -o std
data.exe > data.txt
wa.exe < data.txt > wa.txt
std.exe < data.txt > std.txt
fc wa.txt std.txt
if errorlevel 1 pause
for /l %%a in (1, 1, 100000) do (
	echo %%a
	data.exe > data.txt
	wa.exe < data.txt > wa.txt
	std.exe < data.txt > std.txt
	fc wa.txt std.txt
	if errorlevel 1 pause
)