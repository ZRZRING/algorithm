echo off
cd %~dp0
echo compiling
g++ wa.cpp -o wa
g++ std.cpp -o std
g++ data0.cpp -o data0
for /l %%i in (1, 1, 10000) do (
	echo %%i
	echo data run
	data0.exe > 1.in
	echo wa run
	wa.exe < 1.in > 1.out
	echo std run
	std.exe < 1.in > 1.ans
	fc 1.out 1.ans
	if errorlevel 1 (exit)
)