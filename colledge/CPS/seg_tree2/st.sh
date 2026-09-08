#!/bin/bash
set -e
DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$DIR"
 
echo "編譯中..."
g++ -O2 -o gen     gen.cpp
g++ -O2 -o brute   brute.cpp
g++ -O2 -o sol     b.cpp
echo "編譯完成，開始對拍"
echo ""
 
MAX=${1:-1000}
for i in $(seq 1 $MAX); do
    ./gen $i > input.txt
    expected=$(./brute < input.txt)
    got=$(./sol     < input.txt)
    if [ "$expected" != "$got" ]; then
        echo "❌ WA on case $i"
        echo "--- input ---"
        cat input.txt
        echo "--- expected ---"
        echo "$expected"
        echo "--- got ---"
        echo "$got"
        exit 1
    fi
done
echo "✅ AC on all $MAX cases"