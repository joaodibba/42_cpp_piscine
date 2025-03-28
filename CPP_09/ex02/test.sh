#!/bin/bash

# color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
CYAN='\033[0;36m'

# Initialize counters
passed=0
failed=0

test_sort() {
    local input=$1
    local expected=$2
    echo -e $CYAN"Testing input: $input"$NC

    result=$(./PmergeMe $input 2>&1)
    exit_code=$?

    if [[ "$expected" == "fail" && $exit_code -ne 0 ]]; then
        echo -e $GREEN"Test passed! Properly failed with message: $result"$NC
        ((passed++))
    elif [[ "$expected" != "fail" && $exit_code -eq 0 ]]; then
        if [[ "$result" == "$expected" ]]; then
            echo -e $GREEN"Test passed! Output: $result"$NC
            ((passed++))
        else
            echo -e $RED"Test failed! Expected: $expected, Got: $result"$NC
            ((failed++))
        fi
    else
        echo -e $RED"Test failed! Unexpected result: $result"$NC
        ((failed++))
    fi
    echo
}

echo "Running tests on ./PmergeMe"

# Valid tests
test_sort "3 2 1" "1 2 3"
test_sort "10 9 8 7 6 5" "5 6 7 8 9 10"
test_sort "1" "1"
test_sort "100 50 0" "0 50 100"
test_sort "5 3 8 1 2 9 4" "1 2 3 4 5 8 9"
test_sort "20 10 20 10" "10 10 20 20"
test_sort "0 0 0 0" "0 0 0 0"

# Large list
test_sort "28 81 44 17 77 85 32 39 87 76 14 34 4 62 89 18 95 29 13 26 63 27 75 3 5 99 98 33 31 97 65 92 71 45 43 16 64 20 51 79 74 50 6 83 38 94 91 11 42 84 24 69 70 2 46 55 23 60 30 78 88 52 61 10 56 7 93 49 80 8 86 53 48 9 35 40 12 73 47 37 100 96 36 41 22 57 1 66 54 68 90 25 58 72 82 59 21 19 15 67" \
"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100"

# Invalid tests
test_sort "3 two 1" "fail"
test_sort "" "fail"
test_sort "5 3 4.5" "fail"
test_sort "1 2 -" "fail"
test_sort " " "fail"
test_sort "1e10 2e10" "fail"
test_sort "10, 20, 30" "fail"
test_sort "1 2 3 +" "fail"
test_sort "1 2 3 abc" "fail"

echo -e $CYAN"Tests completed. Results:"$NC
echo -e $GREEN"Tests passed: $passed"$NC
echo -e $RED"Tests failed: $failed"$NC
