# !/bin/bash

# this script server run the X server.

vari=$(ps -C xpra --no-headers );
if [ "$vari" != "" ];
then
    echo "___KILL_SERVER___"
    killall xpra 2> /dev/null > null
    sleep 1
fi

echo "___SERVER_START___"
xpra start :99
sleep 1

echo "___cacafire___"
DISPLAY=":99" cacafire 2> /dev/null > /dev/null &

echo "___cacademo___"
DISPLAY=":99" cacademo  2> /dev/null > /dev/null &

echo "___XTERM___"
DISPLAY=":99" xterm  2> /dev/null > /dev/null &
