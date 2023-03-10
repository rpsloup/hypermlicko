#!/bin/bash

PROJECT_NAME='hypermlicko'
COMPILER='g++'
SOURCE_FOLDER='src'
BUILD_FOLDER='build'
LIBRARIES='-lsfml-graphics -lsfml-window -lsfml-system'

$COMPILER -c $SOURCE_FOLDER/Main.cpp
mkdir -p $BUILD_FOLDER
$COMPILER *.o -o $BUILD_FOLDER/$PROJECT_NAME $LIBRARIES
rm *.o
