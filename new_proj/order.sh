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
    if [ ! -d "./build-Ninja/" ];then
    mkdir ./build-Ninja
    else
    echo "build-Ninja is already exist"
    fi
    cd ./build-Ninja
    cmake .. -G Ninja
    ninja -v
    ./new_proj.exe
    ;;
  *)        
  echo "unknown: $OSTYPE" ;;
esac

# cd ./win_build
# cmake -G "Unix Makefiles" ../
# make
# ./new_proj.exe