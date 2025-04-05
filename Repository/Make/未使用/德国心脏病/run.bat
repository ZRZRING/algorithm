echo off
g++ std1.cpp -o std1
for /l %%a in (1, 1, 7) do (
	echo %%a
	g++ data%%a.cpp -o data%%a
	data%%a.exe > sub%%a-1.in
	std1.exe < sub%%a-1.in > sub%%a-1.out
)