echo off
g++ data.cpp -o data
g++ std.cpp -o std
for /l %%a in (1, 1, 10) do (
	echo %%a
	g++ data.cpp -o data
	data.exe > %%a.in
	std.exe < %%a.in > %%a.out
)