#!/bin/bash
set -e

# Ensure xmake is in PATH
export PATH="/root/.local/bin:${PATH}"
export XMAKE_ROOT=y

# Get version from git or use default
VERSION=$(git describe --tags --long 2>/dev/null || echo "1.0-dev")
export ACCELERATORCS2_VERSION="$VERSION"
echo "Setting version to \"$ACCELERATORCS2_VERSION\""

# Configure & build native plugin
xmake f -y -p linux -a x86_64 --mode=debug
xmake -y

# Prepare folders
mkdir -p build/package/addons/metamod
mkdir -p build/package/addons/AcceleratorCS2
mkdir -p build/package/addons/AcceleratorCS2/bin/linuxsteamrt64

# Copy configs
cp configs/addons/metamod/AcceleratorCS2.vdf build/package/addons/metamod
cp configs/addons/AcceleratorCS2/config.json build/package/addons/AcceleratorCS2
cp build/linux/x86_64/debug/libAcceleratorCS2.so \
   build/package/addons/AcceleratorCS2/bin/linuxsteamrt64/AcceleratorCS2.so