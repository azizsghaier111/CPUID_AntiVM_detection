#!/bin/bash
if [[ -f "main_extracted/main.pyc" ]]; then
    echo "Decompiling main_extracted/main.pyc..."
    pycdc main_extracted/main.pyc > /app/decompiled.py
else
    echo "Error: main_extracted/main.pyc not found. Exiting."
    exit 1

fi

