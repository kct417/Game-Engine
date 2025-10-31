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

# Usage

-   Clone the repository with submodules:

```
git clone --recursive -j4 https://github.com/kct417/Game-Engine.git
```

# Git Submodules

-   If you already cloned the repository without `--recursive`, initialize the submodules with:

```
git submodule update --init --recursive
```

# Build Instructions

## CMake

-   From the root directory

```
cmake -B build
```

```
cmake --build build
```

-   Inside `scripts/cmake` folder

-   Windows `Solution`

    -   Run `BuildSolution.bat`

-   Linux/Mac `Makefile` (Unsupported)

    -   Run `BuildMakefile.sh`

## Premake

-   Inside `scripts/premake` folder

-   Windows `Solution`

    -   Run `BuildSolution.bat`

-   Linux/Mac `Makefile` (Unsupported)

    -   Run `BuildMakefile.sh`
