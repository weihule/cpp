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
    cd ./build
    cmake -G "Unix Makefiles" ../
    make
    ./new_proj.exe
    ;;
  *)        echo "unknown: $OSTYPE" ;;
esac

# cd ./win_build
# cmake -G "Unix Makefiles" ../
# make
# ./new_proj.exe