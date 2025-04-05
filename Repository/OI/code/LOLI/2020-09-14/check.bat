@echo off
g++ std.cpp -o std
g++ wa.cpp -o wa
g++ data.cpp -o data

:loop
    data.exe > std.in
    wa.exe < std.in > wa.out
    std.exe < std.in > std.out
    fc wa.out std.out
if not errorlevel 1 goto loop

pause