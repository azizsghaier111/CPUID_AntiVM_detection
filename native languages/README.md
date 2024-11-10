# README

## Overview

This project demonstrates the use of the native `CPUID` instruction in C to detect a hypervisor or virtualized environment. The `CPUID` instruction is often used in anti-VM techniques to check if the code is running within a virtual machine. This project involves compiling and running a C program (`mainc.c`) on different platforms and using a Ghidra script (`alert.py`) to detect the presence of `CPUID` instructions in binaries.

## Steps

### 1. Compile the C Program

First, compile the `mainc.c` file to create an executable that utilizes the `CPUID` instruction.

```bash
gcc -o mainc mainc.c
```
run the program 
```bash 
./mainc
```
## 2. Alerting the usage of CPUID 
To identify the use of the CPUID instruction within a binary, use the Ghidra script alert.py. This script scans the binary in Ghidra and flags any instances of the CPUID instruction, alerting the analyst to potential anti-VM techniques.

Steps to Run the Ghidra Script:
1. Open Ghidra and import the binary you want to analyze.
2. Load the alert.py script in Ghidra.
3. Run the script to identify and flag CPUID instructions.