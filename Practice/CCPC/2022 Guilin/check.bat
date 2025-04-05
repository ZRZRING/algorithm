@echo off
cd %~dp0
echo compiling
g++ G.cpp -o G
g++ Gstd.cpp -o Gstd
g++ Gdata.cpp -o Gdata
for /l %%a in (1, 1, 10000) do (
	echo %%a
	Gdata.exe > 1.in
	G.exe < 1.in > 1.out
	Gstd.exe < 1.in > 1.ans
	fc 1.out 1.ans
	if errorlevel 1 (exit)
)