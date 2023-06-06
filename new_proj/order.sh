#!/bin/bash

case "$OSTYPE" in
  solaris*) echo "SOLARIS" ;;
  darwin*)  echo "OSX" ;; 
  linux*)   
    echo "LINUX"
    cd ./linux_build
    cmake ../
    make
    ./new_proj
    ;;
  bsd*)     echo "BSD" ;;
  msys*)    
    echo "WINDOWS"
    cd ./cmake-build-debug
    cmake -G Ninja -DCMAKE_BUILD_TYPE=Release "-DCMAKE_MAKE_PROGRAM=D:/ProgramFiles/JetBrains/CLion 2022.3.1/bin/ninja/win/ninja.exe"../
    make
    ./new_proj.exe
    ;;
  *)        echo "unknown: $OSTYPE" ;;
esac

# cd ./win_build
# cmake -G "Unix Makefiles" ../
# make
# ./new_proj.exe