@echo off
cd %~dp0
echo Compiling...
g++ std.cpp -o std
echo Compiled!
for /l %%a in (1,1,1) do (
	echo %%a Running...
	g++ data%%a.cpp -o data%%a
	data%%a.exe > %%a.in
	std.exe < %%a.in > %%a.out
)
@REM for /l %%a in (6,1,7) do (
@REM 	echo %%a Running...
@REM 	g++ data4.cpp -o data4
@REM 	data4.exe > %%a.in
@REM 	std.exe < %%a.in > %%a.out
@REM )
@REM for /l %%a in (8,1,9) do (
@REM 	echo %%a Running...
@REM 	g++ data5.cpp -o data5
@REM 	data5.exe > %%a.in
@REM 	std.exe < %%a.in > %%a.out
@REM )