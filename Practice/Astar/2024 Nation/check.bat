echo off
cd %~dp0
g++ E.cpp -o E
g++ Eforce.cpp -o Eforce
for /l %%a in (1, 1, 100000) do (
	echo %%a
	g++ Edata.cpp -o Edata
	Edata.exe > E.in
	E.exe < E.in > E.out
	Eforce < E.in > E.ans
	fc E.out E.ans
	if errorlevel 1 (exit)
)