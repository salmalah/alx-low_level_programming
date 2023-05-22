#!/bin/bash
gcc -shared -fPIC -o 101-make_me_win.so random.c
LD_PRELOAD=$WPD/101-make_me_win.so
