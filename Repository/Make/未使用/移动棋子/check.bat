@echo off
echo 1
g++ data.cpp -o data
data.exe > data.txt
g++ wa.cpp -o wa
wa.exe < data.txt > wa.txt
g++ std.cpp -o std
std.exe < data.txt > std.txt
fc wa.txt std.txt
if errorlevel 1 goto ed
for /l %%a in (2,1,100000) do (
	echo %%a
	data.exe > data.txt
	wa.exe < data.txt > wa.txt
	std.exe < data.txt > std.txt
	fc wa.txt std.txt
	if errorlevel 1 goto ed
)
:ed