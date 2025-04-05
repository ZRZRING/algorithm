@echo off
g++ std.cpp -o std
g++ wa.cpp -o wa
g++ data.cpp -o data


wa.exe < std.in > wa.out
std.exe < std.in > std.out