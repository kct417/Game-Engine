# Practice-C-Plus-Plus-Game-Engine

## Credit

Code adapted from YouTube tutorials by The Cherno and sudocpp:

-   The Cherno
    -   https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT
-   sudocpp
    -   https://www.youtube.com/playlist?list=PLsCsQorDHC9Wism5Xlp8ZKtKeGBeCJJ72

# System Requirements

-   `Windows-x86_64`
-   `Linux` and `MacOS` are currently unsupported, please ignore any instructions for these systems

# Git Submodules

```
git submodule update --init --recursive
```

# Build Instructions

## CMake

```
cmake -B build
```

```
cmake --build build
```

## Premake

-   Windows `Solution`

    -   inside `scripts` folder

    1.  Run `GenerateSolution.bat`
    2.  Run `BuildSolution.bat`

-   Linux/Mac `Makefile` (Unsupported)

    -   inside `scripts` folder

    1.  Run `GenerateMakefile.sh`
    2.  Run `BuildMakefile.sh`

# Notes

-   Targets will be stored in `bin` directory
-   Intermediates will be stored in `bin-build` directory for `Premake`
-   Intermediates will be stored in `build` directory for `CMake`
