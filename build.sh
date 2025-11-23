#!/bin/bash

mkdir -p build
clang -Wall -Werror -lstdc++ \
    main.cpp linenoise/linenoise.c \
    -o build/plex
