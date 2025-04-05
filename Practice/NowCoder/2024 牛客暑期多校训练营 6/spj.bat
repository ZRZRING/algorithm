cd %~dp0
g++ L.cpp -o L
L < 1.in > 1.out
g++ checker.cc -o checker
checker.exe 1.in 1.out 1.ans