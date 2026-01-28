#!/usr/bin/env bash
# Determine OS
if   [[ "$OSTYPE" == "linux"* ]];  then OS="Linux"
elif [[ "$OSTYPE" == "darwin"* ]]; then OS="macOS"
elif [[ "$OSTYPE" == "cygwin" ]];  then OS="Windows"
elif [[ "$OSTYPE" == "msys" ]];    then OS="Windows"
else OS="Windows"
fi

# Compile program
if [[ "$OS" == "Linux" ]]; then
  clang main.c -fopenmp -lGL -lGLU -lX11    ## libGL, libGLU and libX11 may be required
elif [[ "$OS" == "Windows" ]]; then
  clang main.c -fopenmp -lopengl32 -lgdi32  ## libopengl32 and libgdi32 may be required
elif [[ "$OS" == "macOS" ]]; then
  clang main.c -fopenmp -framework OpenGL -framework Cocoa
fi

# Run program
if [[ "$OS" == "Windows" ]]; then ./a.exe "$@"
else ./a.out "$@"
fi
