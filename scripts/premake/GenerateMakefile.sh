#!/usr/bin/env bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

"$PROJECT_ROOT/vendor/premake/bin/premake5" gmake --file="$PROJECT_ROOT/premake5.lua"

if [[ "$1" != "nopause" ]]; then
    echo "Press any key to continue . . . "
    read -n 1 -s
fi
