echo off
cd %~dp0
g++ std.cpp -o std
for /l %%a in (1, 1, 6) do (
	echo %%a
	g++ data%%a.cpp -o data%%a
	data%%a.exe > sub%%a-1.in
	std.exe < sub%%a-1.in > sub%%a-1.out
	data%%a.exe > sub%%a-2.in
	std.exe < sub%%a-2.in > sub%%a-2.out
	data%%a.exe > sub%%a-3.in
	std.exe < sub%%a-3.in > sub%%a-3.out
	data%%a.exe > sub%%a-4.in
	std.exe < sub%%a-4.in > sub%%a-4.out
	data%%a.exe > sub%%a-5.in
	std.exe < sub%%a-5.in > sub%%a-5.out
)