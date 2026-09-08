@echo off
g++ -O2 -o brute.exe brutb.cpp
g++ -O2 -o sol.exe B.cpp

for /l %%i in (1,1,1000) do (
    python gen.py > test_input.txt
    
    brute.exe < test_input.txt > out_brute.txt
    sol.exe < test_input.txt > out_sol.txt
    
    fc /b out_brute.txt out_sol.txt > nul
    if errorlevel 1 (
        echo DIFF on case %%i
        echo Input:
        type test_input.txt
        echo Brute:
        type out_brute.txt
        echo Sol:
        type out_sol.txt
        pause
        exit /b 1
    )
)
echo All tests passed