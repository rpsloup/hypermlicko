#!/bin/bash

PROJECT_NAME="hypermlicko"
COMPILER="g++"
SOURCE_FOLDER="src"
BUILD_FOLDER="build"
CLASS_FOLDER="Classes"
HEADER_FOLDER="Headers"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system -lconfig++"

if [ $1 = "run" ]
then
  ./$BUILD_FOLDER/$PROJECT_NAME
  exit 0
fi

$COMPILER -c $SOURCE_FOLDER/Main.cpp $SOURCE_FOLDER/$CLASS_FOLDER/*.cpp
mkdir -p $BUILD_FOLDER
$COMPILER *.o -o $BUILD_FOLDER/$PROJECT_NAME -I $SOURCE_FOLDER/$HEADER_FOLDER $LIBRARIES
rm *.o
