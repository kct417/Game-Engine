#!/usr/bin/env bash

./GenerateMakefile.sh nopause

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

cmake --build "$PROJECT_ROOT/build"

if [[ "$1" != "nopause" ]]; then
    echo "Press any key to continue . . . "
    read -n 1 -s
fi
