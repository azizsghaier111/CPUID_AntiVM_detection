#!/bin/bash

# Step 1: Run pyinstxtractor to extract the PyInstaller binary
python3 pyinstxtractor.py dist/main

# Step 2: Check if the Docker image `my-python-app` exists
if [[ "$(docker images -q my-python-app 2> /dev/null)" == "" ]]; then
    echo "Docker image 'my-python-app' does not exist. Building it now..."
    docker build -t my-python-app .
else
    echo "Docker image 'my-python-app' already exists. Skipping build."
fi

# Step 3: Run Docker container with `my-python-app`
docker run -it -v "$(pwd)":/app my-python-app

# Step 4: Use pycdc to decompile the extracted .pyc file into a readable .py file
# This assumes the extracted file path is `main_extracted/main.pyc`
