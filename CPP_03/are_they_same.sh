#!/bin/bash

check_and_diff() {
    local file=$1
    shift
    local paths=("$@")
    local diff_paths=()

    for path in "${paths[@]}"; do
        if [[ ! -f "$path/$file" ]]; then
            echo "File not found: $path/$file"
            return
        fi
        diff_paths+=("$path/$file")
    done

    case ${#diff_paths[@]} in
        2)
            diff "${diff_paths[@]}"
            ;;
        3)
            diff3 "${diff_paths[@]}"
            ;;
        *)
            echo "Invalid number of files for comparison. Found ${#diff_paths[@]} files."
            ;;
    esac
}

files=(
    "ClapTrap.cpp"
    "ScavTrap.cpp"
    "ClapTrap.hpp"
    "ScavTrap.hpp"
)

paths_ex00=("ex00" "ex01" "ex02")
paths_ex01=("ex01" "ex02")

for file in "${files[@]}"; do
    if [[ $file == "ClapTrap.cpp" || $file == "ClapTrap.hpp" ]]; then
        check_and_diff "$file" "${paths_ex00[@]}"
    else
        check_and_diff "$file" "${paths_ex01[@]}"
    fi
done
