echo off
g++ data1.cpp -o data1
g++ n3.cpp -o n3
g++ std.cpp -o std
data1.exe > data1.txt
n3.exe < data1.txt > n3.txt
std.exe < data1.txt > std.txt
fc n3.txt std.txt
if errorlevel 1 pause
for /l %%a in (1, 1, 100000) do (
	echo %%a
	data1.exe > data1.txt
	n3.exe < data1.txt > n3.txt
	std.exe < data1.txt > std.txt
	fc n3.txt std.txt
	if errorlevel 1 pause
)