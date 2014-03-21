#!/bin/sh
# source: http://unix.stackexchange.com/questions/119243/bash-script-to-output-path-to-usb-flash-memory-stick

usb_drive_lookup () {
    # tested on ubuntu 12.10 i386
    for mtabline in `cat /etc/mtab`; do 
        device="`echo $mtabline | cut -f 1 -d ' '`"
        udevline="`udevadm info -q path -n $device 2>&1 |grep usb`"
        if [ $? -eq 0 ] ; then
            devpath=`echo $mtabline | cut -f 2 -d ' '`
            echo "devpath: $devpath"
            show_usb_mounted_path "$devpath"
            if [ $? -eq 0 ]; then
                return 1
            fi
        fi
    done 
    return 0
}

show_usb_mounted_path () {
    # update my part
    devinfo=`df | grep "$1" | grep -v grep`
    if [ ! -n "$devinfo" ]; then
        return 1
    fi
    echo "$devinfo" | cut -d "%" -f2 | sed -e "s/^[ ]*//g"
    return 0
}

usb_drive_lookup
if [ $? -eq 0 ]; then
    echo "usb drive not found";
    exit 1
fi
exit 0
