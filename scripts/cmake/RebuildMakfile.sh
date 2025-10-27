#!/usr/bin/env bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

"$SCRIPT_DIR/CleanMakefile.sh" nopause
"$SCRIPT_DIR/BuildMakefile.sh"
