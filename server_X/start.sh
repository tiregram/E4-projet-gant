# !/bin/bash

# this script server run the X server.

vari=$(ps -C xpra --no-headers );
if [[ "$vari" != "" ]];
then
    echo "___KILL_SERVER___"
    killall xpra 2> /dev/null > null

fi

echo "___SERVER_START___"
xpra start :99
sleep 0.5

echo "___cacafire___"
DISPLAY=":99" cacafire &

echo "___cacademo___"
DISPLAY=":99" cacademo &

echo "___XTERM___"
DISPLAY=":99" xterm &
