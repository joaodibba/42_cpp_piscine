#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

passed=0
failed=0

test_sort() {
    local input="$1"
    local expected="$2"
    echo -e "${CYAN}Testing input: ${input}${NC}"

    result=$(./PmergeMe $input 2>&1)
    exit_code=$?

    if [[ "$expected" == "fail" && $exit_code -ne 0 ]]; then
        echo -e "${GREEN}Test passed! Properly failed with message: $result${NC}"
        ((passed++))

    elif [[ "$expected" != "fail" && $exit_code -eq 0 ]]; then
        actual_sorted=$(echo "$result" | sed -n 's/^After:\s*\(.*\)/\1/p' | xargs)

        if [[ "$actual_sorted" == "$expected" ]]; then
            echo -e "${GREEN}Test passed! Output is correctly sorted: $actual_sorted${NC}"
            ((passed++))
        else
            echo -e "${RED}Test failed! Expected: $expected, Got: $actual_sorted${NC}"
            ((failed++))
        fi
    else
        echo -e "${RED}Test failed! Unexpected result or exit code ($exit_code).${NC}"
        echo -e "${RED}Output was: $result${NC}"
        ((failed++))
    fi
    echo
}

echo "Running tests on ./PmergeMe"

# -------------------
# VALID TESTS
# -------------------
test_sort "3 2 1" "1 2 3"
test_sort "10 9 8 7 6 5" "5 6 7 8 9 10"
test_sort "1" "1"
test_sort "5 3 8 1 2 9 4" "1 2 3 4 5 8 9"
test_sort "20 10 20 10" "10 10 20 20"

# -------------------
# INVALID TESTS
# -------------------
test_sort "10 9 8 7 -1 2" "fail"
test_sort "100 50 0" "fail"
test_sort "0 0 0 0" "fail"
test_sort "10 9 8 7 -1" "fail"
test_sort "3 two 1" "fail"
test_sort "" "fail"
test_sort "5 3 4.5" "fail"
test_sort "1 2 -" "fail"
test_sort " " "fail"
test_sort "1e10 2e10" "fail"
test_sort "10, 20, 30" "fail"
test_sort "1 2 3 +" "fail"
test_sort "1 2 3 abc" "fail"

# -------------------
# SUMMARY
# -------------------
echo -e "${CYAN}Tests completed. Results:${NC}"
echo -e "${GREEN}Tests passed: $passed${NC}"
echo -e "${RED}Tests failed: $failed${NC}"
