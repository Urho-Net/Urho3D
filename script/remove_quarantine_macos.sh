#!/bin/bash
# Remove macOS quarantine attribute from downloaded libraries
# This allows the ad-hoc signed libraries to run without security warnings

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
DOTNET_LIBS_DIR="${SCRIPT_DIR}/../DotNet/libs"

if [ ! -d "$DOTNET_LIBS_DIR" ]; then
    echo "Error: DotNet/libs directory not found at: $DOTNET_LIBS_DIR"
    echo "Usage: Run this script from the repository root or script directory"
    exit 1
fi

echo "Removing quarantine attributes from libraries..."
xattr -dr com.apple.quarantine "$DOTNET_LIBS_DIR"

if [ $? -eq 0 ]; then
    echo "✓ Quarantine attributes removed successfully"
    echo "Libraries in $DOTNET_LIBS_DIR are now ready to use"
else
    echo "✗ Failed to remove quarantine attributes"
    exit 1
fi
