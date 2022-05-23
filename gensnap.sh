#!/bin/bash

#DEPENDS:

#Remove snap
rm -f *.snap 2>/dev/null

# Compile and copy the snap
#CROSS_COMPILE_ARGS="--target-arch=arm64 --enable-experimental-target-arch"
SNAP_OUT_DIR=$(pwd)/../../../out/
snapcraft $CROSS_COMPILE_ARGS --destructive-mode

mkdir -p $SNAP_OUT_DIR
cp -rf *.snap $SNAP_OUT_DIR/
