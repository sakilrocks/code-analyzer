# code-analyzer

a lightweight C++ CLI tool that analyzes source code for unused variables and TODO/FIXME comments using regex based parsing. it scans `.cpp` and `.h` files to detect:
- Unused variables
- TODO/FIXME comments

it’s built entirely from scratch using C++ and regex, no external parsing libraries.

---

## Features

- Detects unused variables in source code  
- Highlights TODO and FIXME comments  
- Colour coded CLI output for readability  
- Works on any C++ source file  

---

## Project Structure

```
code-analyzer/
├── include/                
│   ├── analyzer.hpp        # performs code checks
│   ├── parser.hpp          # reads and extracts code info
│   └── utils.hpp           # util functions
├── src/                    
│   ├── main.cpp            # entry point
│   ├── analyzer.cpp        # implements the analyzer logic
│   ├── parser.cpp          # handles file reading and regex parsing
│   └── utils.cpp           # methods for color and I/O
├── Makefile                
└── README.md           

```

## How to Use

```
./bin/codeanalyzer path/to/file.cpp

```
