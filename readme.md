# Insurance Reserve Calculator

## Overview

The **Insurance Reserve Calculator** is a C++ application designed to calculate the reserve values for an insurance policy based on a set of assumptions. It reads the assumptions from a CSV file, performs calculations, and outputs the result to both the console and a text file. The program supports multiple versions with different assumptions, which can be selected by the user.

## Features
- Reads assumptions from a CSV file.
- Performs a reserve calculation based on input assumptions.
- Supports multiple versions of assumptions (Program 1, Program 2, Program 3).
- Allows custom assumption files to be uploaded.
- Outputs the calculated reserve to the console and saves it to a text file.

## Requirements

- A C++ compiler (e.g., **GCC** or **MSVC**).
- A valid CSV file with insurance assumptions.

## Files

1. **ReserveCalculator.cpp** - Main C++ source code file for the calculator.
2. **Assumptions.csv** - Example CSV file containing the assumptions for the reserve calculation.
3. **Reserve_Output.txt** - Output file where the calculated reserve is saved.
4. **Program1**, **Program2**, **Program3** folders - Each contains pre-configured assumptions CSV files for different calculation scenarios.

## Setup Instructions

### Step 1: Prepare Assumptions File

1. **Convert Assumptions.xlsx to CSV:** Convert the `Assumptions.xlsx` (Excel file) to a CSV file (e.g., `Assumptions.csv`), ensuring that the column order matches the structure defined in the program.

### Step 2: Compile the Code

1. Install a C++ compiler like **GCC** or **MSVC**.
2. Compile the program using the following command:
   ```bash
   g++ -o ReserveCalculator ReserveCalculator.cpp
   ```

### Step 3: Run the Program

1. Place the `Assumptions.csv` file in the same directory as the executable.
2. Execute the program by running:
   ```bash
   ./ReserveCalculator
   ```

### Step 4: View Outputs

- The calculated reserve value will be displayed in the terminal.
- The result will also be saved in a file named `Reserve_Output.txt`.

## Example Usage

Assuming that you have an `Assumptions.csv` file with the correct format, you can run the program like this:

```bash
./ReserveCalculator
```

This will calculate the reserve value using the assumptions defined in the `Assumptions.csv` file and output the result to the terminal and the `Reserve_Output.txt` file.

## File Structure

```
InsuranceReserveCalculator/
├── Assumptions1/
│   └── Assumptions.csv
├── Assumptions2/
│   └── Assumptions.csv
├── Assumptions3/
│   └── Assumptions.csv
├── MortalityRates1/
├── MortalityRates2/
├── MortalityRates3/
├── Program1/
│   └── ReserveCalculator.exe
├── Program2/
│   └── ReserveCalculator.exe
├── Program3/
│   └── ReserveCalculator.exe
└── ReserveCalculator.cpp
```
