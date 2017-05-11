# !/bin/bash

# this script server run the X server.

vari=$(ps -C Xvfb --no-headers );
if [ "$vari" != "" ];
then
    echo "___KILL_SERVER___"
    killall Xvfb 2> /dev/null > null
    sleep 1
fi

echo "___SERVER_START___"

#xpra start :99
#xpra start :99 --pulseaudio=no --mdns=no --use-display

Xvfb :99 -listen tcp -ac > log/log_xvfb.log &
sleep 1
DISPLAY=:99 evilwm > log/log_evilwm.log &

echo "___cacafire___"
DISPLAY=":99" cacafire 2> /dev/null > /dev/null &

echo "___cacademo___"
DISPLAY=":99" cacademo  2> /dev/null > /dev/null &

echo "___XTERM___"
DISPLAY=":99" xterm  2> /dev/null > /dev/null &
