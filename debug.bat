#! /bin/bash

CONFIGURE_SCRIPT="./configure.bat"
BUILD_SCRIPT="./build.bat"
GEA_EXECUTABLE="./build/GEA"

"$CONFIGURE_SCRIPT" && "$BUILD_SCRIPT" && cgdb "$GEA_EXECUTABLE"