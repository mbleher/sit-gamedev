# Rationale

This project is achieved as part of a Stevens Institute of Technology course, Introduction to Game Development (CS 585).

# Tools

- Language:   C++11
- Building:   CMake v2.8.12.2
- Compiling:  g++ v4.8.2
- Testing:    Google Test & Travis CI

# Build and Run Instructions

## Build
To build the application, run the following commands at the top level
- `cmake .`
- `make`

In order to keep top level clean, you can alternatively run the following commands
- `mkdir _builds`
- `cd _builds`
- `cmake ..`
- `make`
- `mv Game ../`

## Run
Once the application has been successfully built, run the following command at the top level
- `./Game`

# Coding Standard

The coding standard used for this project can be found [here](CodingStandard.md).