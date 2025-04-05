@echo off
echo 1
g++ data.cpp -o data -w -Wl,--stack=19198101 -std=c++17 -O2
g++ std1.cpp -o std1 -w -Wl,--stack=19198101 -std=c++17 -O2
g++ std2.cpp -o std2 -w -Wl,--stack=19198101 -std=c++17 -O2
data.exe > data.txt
std1.exe < data.txt > std1.txt
std2.exe < data.txt > std2.txt
fc std1.txt std2.txt
if errorlevel 1 pause
for /l %%a in (2,1,100000) do (
	echo %%a
	data.exe > data.txt
	std1.exe < data.txt > std1.txt
	std2.exe < data.txt > std2.txt
	fc std1.txt std2.txt
	if errorlevel 1 pause
)
:ed