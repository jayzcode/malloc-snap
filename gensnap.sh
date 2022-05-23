#!/bin/bash

#Remove snap
rm -f *.snap 2>/dev/null

# Compile and copy the snap
#CROSS_COMPILE_ARGS="--target-arch=arm64 --enable-experimental-target-arch"
snapcraft $CROSS_COMPILE_ARGS --destructive-mode
