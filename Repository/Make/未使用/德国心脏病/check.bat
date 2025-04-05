echo off
g++ data2.cpp -o data2
g++ wa.cpp -o wa
g++ std.cpp -o std
data2.exe > data2.txt
wa.exe < data2.txt > wa.txt
std.exe < data2.txt > std.txt
fc wa.txt std.txt
if errorlevel 1 pause
for /l %%a in (1, 1, 100000) do (
	echo %%a
	data2.exe > data2.txt
	wa.exe < data2.txt > wa.txt
	std.exe < data2.txt > std.txt
	fc wa.txt std.txt
	if errorlevel 1 pause
)