#!/usr/bin/env bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

# echo "WARNING: This will delete build folders inside:"
# echo "$PROJECT_ROOT"
# echo

# read -p "Do you want to continue? (y/n): " userInput
# if [[ "$userInput" != [Yy] ]]; then
#     exit 0
# fi

rm -rfv "$PROJECT_ROOT/bin" "$PROJECT_ROOT/build"
find "$PROJECT_ROOT" -name "Makefile" -print -delete

if [[ "$1" != "nopause" ]]; then
    echo "Press any key to continue . . . "
    read -n 1 -s
fi
