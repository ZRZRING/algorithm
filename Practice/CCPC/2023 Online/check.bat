@echo off
echo 1
g++ data.cpp -o data
g++ Lforce.cpp -o Lforce
g++ L.cpp -o L
data.exe > data.txt
L.exe < data.txt > wa.txt
Lforce.exe < data.txt > std.txt
fc wa.txt std.txt
if errorlevel 1 pause
for /l %%a in (2, 1, 10000) do (
	echo %%a
	data.exe > data.txt
	L.exe < data.txt > wa.txt
	Lforce.exe < data.txt > std.txt
	fc wa.txt std.txt
	if errorlevel 1 pause
)
:ed