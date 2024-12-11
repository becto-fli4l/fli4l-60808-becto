#!/bin/sh

echo "Unloading watchdog kernel modules"
modprobe -r softdog

echo "Attempting to load watchdog"
modprobe softdog nowayout=1 soft_margin=600

sleep 10

if [ -e /dev/watchdog ]; then
    echo "Starting watchdog timer"   
    echo >> /dev/watchdog
    echo >> /dev/watchdog0
    echo "... -> waiting 25 seconds"
    sleep 25
    echo "... -> reboot"
    reboot
fi
