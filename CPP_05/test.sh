#!/bin/bash

# Base directory
BASE_DIR="$PWD"

# Loop through ex0* directories
for dir in "$BASE_DIR"/ex0*; do
    if [ -d "$dir" ]; then
        echo "Entering directory: $dir"
        cd "$dir" || exit

        # Run make
        if [ -f "Makefile" ]; then
            echo "Running make in $dir..."
            make clean
            make
            if [ $? -ne 0 ]; then
                echo "Make failed in $dir. Skipping."
                cd - >/dev/null || exit
                continue
            fi

            # Find the executable (assume it has no extension and is in the current directory)
            executable=$(find . -maxdepth 1 -type f -executable | grep -vE '\.o$|\.cpp$|\.hpp$|Makefile')
            if [ -n "$executable" ]; then
                echo "Running $executable with valgrind..."
                valgrind --leak-check=full --show-leak-kinds=all "$executable"
            else
                echo "No executable found in $dir."
            fi

			# Clean up
			make fclean
        else
            echo "No Makefile found in $dir."
        fi

        # Return to base directory
        cd - >/dev/null || exit
    else
        echo "$dir is not a directory. Skipping."
    fi
done
