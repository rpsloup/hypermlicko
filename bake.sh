#!/bin/bash

COMPILER='g++'
SOURCE_FOLDER='src'
BUILD_FOLDER='build'
PROJECT_NAME='hypermlicko'

$COMPILER -c $SOURCE_FOLDER/Main.cpp
mkdir -p $BUILD_FOLDER
$COMPILER *.o -o $BUILD_FOLDER/$PROJECT_NAME
rm *.o
