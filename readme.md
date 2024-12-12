# InMemoryDB Library

## Overview
The `InMemoryDB` library provides a simple in-memory database with basic transaction support. It allows you to:
- Store key-value pairs.
- Manage transactions, including commit and rollback operations.

This README provides setup instructions and details on how to run the code and tests.

## Prerequisites
Before using this library, ensure the following tools are installed:

- **Compiler**: A C++ compiler with C++17 support (e.g., `g++` version 7 or higher).
- **Build System**: `make` (for using the provided makefile).
- **Operating System**: Linux or macOS. It should also work on Windows with appropriate setup (e.g., MinGW or WSL).

## Setup Instructions
1. Clone or download this repository.

2. Ensure the following files are present:
   - `InMemoryDB.h` (header file for the library)
   - `InMemoryDB.cpp` (implementation file for the library)
   - `test.cpp` (test file for the library)
   - `makefile` (build instructions)
   - `run.sh` (shell script that automates everything)

3. Navigate to the directory containing these files.

## Automated Building and Testing of Library
On a Unix based system run:
```bash
sudo chmod +x run.sh
```

Then
```bash
./run.sh
```

That command will automatically build and run everything.

## Manually Building the Library
To build the library and test executable:

1. Open a terminal and navigate to the project directory.
   ```bash
   cd libInMemoryDB
   ```

2. Run the following command:
   ```bash
   make
   ```
   This will:
   - Compile the `InMemoryDB` library.

## Manually Running the Tests
To execute the test suite:

1. Build the test:
   ```bash
   g++ -std=c++17 -o test.out test.cpp -L ./libInMemoryDB -lInMemoryDB
   ```

2. Run the following command:
   ```bash
   ./test.out
   ```

3. If all tests pass, the output will be:
   ```
   test_get_and_put_without_transaction passed.
   test_transaction_commit passed.
   test_transaction_rollback passed.
   test_nested_transactions passed.
   All tests passed successfully!
   ```

##

## Official Assignment
I feel like a good way to turn this into a full assignment is to make the students create a library.
Not only that but also create a full fledged testing suite using whatever language they want.
Or making them use some test suite like google test for  example, and  to use shell scripts as well.
I think that would be a pretty conprehensive assignment and give the students some experience building and compiling stuff.
Which definitely will come ion handy for future courses and actual work once they graduate.
During my internship I've have to use or make shell scripts, getting exposure in school would've been convenient.



