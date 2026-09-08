#!/bin/bash
set -e
 
echo "=== 編譯中 ==="
g++ -O2 -std=c++17 -o brute brute.cpp && echo "brute OK"
g++ -O2 -std=c++17 -o sol   4-1.cpp   && echo "sol OK"
echo ""
 
ROUNDS=${1:-200}
echo "=== 開始對拍 $ROUNDS 輪 ==="
 
for seed in $(seq 1 $ROUNDS); do
    python3 Gen.py $seed > input.txt
 
    out_brute=$(./brute < input.txt)
    out_sol=$(./sol   < input.txt)
 
    if [ "$out_brute" != "$out_sol" ]; then
        echo ""
        echo "❌ HACK found at seed=$seed"
        echo "--- 輸入 ---"
        cat input.txt
        echo "--- 暴力輸出 ---"
        echo "$out_brute"
        echo "--- 正解輸出 ---"
        echo "$out_sol"
        exit 1
    fi
 
    if (( seed % 50 == 0 )); then
        echo "  ✓ $seed/$ROUNDS passed"
    fi
done
 
echo ""
echo "✅ All $ROUNDS tests passed!"