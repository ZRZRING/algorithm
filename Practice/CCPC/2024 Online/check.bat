@echo off
cd %~dp0
echo compiling
g++ J.cpp -o J
g++ Jforce.cpp -o Jforce
g++ Jdata.cpp -o Jdata
for /l %%a in (1, 1, 10000) do (
	echo %%a
	Jdata.exe > 1.in
	J.exe < 1.in > 1.out
	Jforce.exe < 1.in > 1.ans
	fc 1.out 1.ans
	if errorlevel 1 (exit)
)