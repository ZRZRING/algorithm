echo off
g++ std.cpp -o std
g++ d1.cpp -o d1
for /l %%a in (1, 1, 5) do (
	echo %%a
	g++ d1.cpp -o d1
	d1.exe > a%%a.in
	std.exe < a%%a.in > a%%a.out
)
g++ d2.cpp -o d2
for /l %%a in (1, 1, 5) do (
	echo %%a
	g++ d2.cpp -o d2
	d2.exe > b%%a.in
	std.exe < b%%a.in > b%%a.out
)
g++ d3.cpp -o d3
for /l %%a in (1, 1, 5) do (
	echo %%a
	g++ d3.cpp -o d3
	d3.exe > c%%a.in
	std.exe < c%%a.in > c%%a.out
)
g++ d4.cpp -o d4
for /l %%a in (1, 1, 5) do (
	echo %%a
	g++ d4.cpp -o d4
	d4.exe > d%%a.in
	std.exe < d%%a.in > d%%a.out
)