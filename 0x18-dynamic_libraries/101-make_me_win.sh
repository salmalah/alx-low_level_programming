#!/bin/bash
gcc -fPIC -c random.c
gcc -shared -o 101-make_me_win.so random.c
