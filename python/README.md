# Hypervisor Detection Project (python)

## Overview

This project is designed to detect the presence of a hypervisor (virtualized environment) using a Python script (`main.py`) in different platforms. The script checks specific CPU flags and characteristics to determine if it is running within a virtual machine. The process involves:

1. Detecting the hypervisor through the Python script.
2. Converting the Python script into a standalone binary.
3. Reverse engineering the binary.
4. Using a YARA rule to identify specific anti-VM techniques.

## Usage Instructions

### 1. Detecting the Hypervisor

The core detection code is located in `main.py`, which identifies the hypervisor by analyzing CPU flags and brand information.

To run the script and detect a hypervisor:

```bash
python3 main.py
```
### 2. Convert Python Script to a Binary
o enhance the analysis and detect anti-VM techniques, convert main.py into a standalone binary using PyInstaller. This packages the Python code and its dependencies into a single executable.

To bundle `main.py` into a binary:
```bash
pyinstaller --onefile main.py

```

This will create an executable file in the dist directory.

## 3. Reverse Engineering Process
Step 1: Extract the Bytecode
Start reverse engineering by extracting the .pyc bytecode files from the binary created with PyInstaller.
To bundle `main.py` into a binary:
```bash
./bytecode.sh

```

This script will place you in a Docker container with the necessary tools for reverse engineering.

Step 2: Navigate to the App Directory
Once inside the Docker container, navigate to the /app directory:

```bash
cd /app

```

Step 3: Decompile the Bytecode
To decompile the .pyc bytecode back into Python code, use the decompile.sh script:
```bash 
./decompile.sh
exit 
```
Finally, use a YARA rule to detect specific anti-VM techniques in the decompiled code. The YARA rule searches for patterns indicating hypervisor detection techniques.
```bash
yara detect.yara decompiled.py

```

This will alert you if the code uses certain techniques for detecting the virtual machine environment.

