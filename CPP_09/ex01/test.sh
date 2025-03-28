#!/bin/bash
# color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
CYAN='\033[0;36m'

# Initialize counters
passed=0
failed=0

# Function to test an RPN expression with expected result or failure
test_rpn() {
    local expression=$1
    local expected_result=$2
    echo -e $CYAN"Testing expression: $expression"$NC

    # Run the RPN program with the expression
    result=$(./RPN "$expression" 2>&1)
    exit_code=$?

    # Check if the exit code matches the expected outcome
    if [[ "$expected_result" == "fail" && $exit_code -ne 0 ]]; then
        echo -e $GREEN"Test passed! Result: $result"$NC
        ((passed++))
    elif [[ "$expected_result" != "fail" && $exit_code -eq 0 ]]; then
        if [[ "$result" == "$expected_result" ]]; then
            echo -e $GREEN"Test passed! Result: $result"$NC
            ((passed++))
        else
            echo -e $RED"Test failed! Expected: $expected_result, got: $result"$NC
            ((failed++))
        fi
    else
        echo -e $RED"Test failed! Expected: $expected_result, got: $result"$NC
        ((failed++))
    fi
    echo
}

echo "Running tests on ./RPN"

test_rpn "3 4 +" "7"
test_rpn "2 3 4 + *" "14"
test_rpn "8 2 /" "4"
test_rpn "5 1 2 + 4 * + 3 -" "14"
test_rpn "3 +" "fail"
test_rpn "+ 2 3" "fail"
test_rpn "3 5 / +" "fail"
test_rpn "2 3 + *" "fail"
test_rpn "" "fail"
test_rpn "9" "9"
test_rpn "10 0 /" "fail"
test_rpn "-5 2 +" "-3"
test_rpn "5 -2 +" "3"
test_rpn "1000000 2000000 +" "3e+06"
test_rpn "1000000000 1000000000 /" "1"
test_rpn "3 4 + 2 * 7 / 3 - 10 +" "9"
test_rpn "-10 5 + -3 2 / *" "7.5"
test_rpn "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +" "45"
test_rpn "1000000000 1000000000 *" "1e+18" 
test_rpn "3 4 +   " "7"
test_rpn " 2 3 4 + * " "14"
test_rpn "3 5 + 2 * 4 / 2 +" "6"
test_rpn "3 4 + 5 *" "35"
test_rpn "0.0001 0.0002 +" "0.0003"
test_rpn "0.0000001 10000000 *" "1"
test_rpn "-10 2 /" "-5"
test_rpn "3 2 + 3 + 3 + 3 +" "14"
test_rpn "3 9 - 5 - +" "fail"
test_rpn "5 2 /" "2.5"
test_rpn "3 5 abc +" "fail"
test_rpn "1e100 1e100 +" "inf"
test_rpn "1e-100 1e-100 +" "0"
test_rpn "+" "fail"
test_rpn "5 1 2 + 4 * + 3 -" "14"
test_rpn "    5 5 +" "10"
test_rpn "5 3 + 2" "fail"
test_rpn "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 9 +" "54"

echo -e $CYAN"Tests completed. Results:"$NC
echo -e $GREEN"Tests passed: $passed"$NC
echo -e $RED"Tests failed: $failed"$NC
