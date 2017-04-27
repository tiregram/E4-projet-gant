# !/bin/bash

# this script server stop the X server.

vari=$(ps -C xpra --no-headers );
if [ "$vari" != "" ];
then
    echo "___KILL_SERVER___"
    killall xpra 2> /dev/null > null

fi
