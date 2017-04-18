# !/bin/bash

vari=$(ps -C Xvfb --no-headers );
if [[ "$vari" != "" ]];
then
    killall Xvfb 2> /dev/null > null
    sleep 1
fi

Xvfb :8 &
sleep 2
DISPLAY=":8" cacafire &
DISPLAY=":8" cacademo &
DISPLAY=":8" xterm &



