#!/usr/bin/env bash

KMOD_DIR=kmod
KMOD_DEV=mystery
KMOD_KO=mystery.ko

DEPS="gcc make gnuplot"

setup_kmod() {
    if ! [[ -f $KMOD_DIR/$KMOD_KO ]]; then
        echo "[-] kernel $KMOD_DIR/$KMOD_KO not found."
        exit 1
    fi

    if [[ -e /dev/$KMOD_DEV ]]; then
        echo "[!] kernel module already installed. I will automatically re-install the module."
        sudo rmmod $KMOD_DEV
        
    fi

    KERN_VER=$(uname -r)
    KMOD_VER=$(modinfo -F vermagic $KMOD_DIR/$KMOD_KO 2> /dev/null | sed -e 's/\(.*-generic\)\s.*/\1/g')

    KERN_VER=$(echo $KERN_VER | sed -e 's/\./-/g')
    KMOD_VER=$(echo $KMOD_VER | sed -e 's/\./-/g')

    if [[ $KERN_VER -ne $KMOD_VER ]]; then
        echo "[-] kernel version $KERN_VER doesn't match the module version $KMOD_VER."
        exit 1
    fi

    echo "[+] install kernel module $KMOD_DIR/$KMOD_KO."
    sudo insmod $KMOD_DIR/$KMOD_KO

    if [[ $? -ne 0 ]]; then
        echo "[-] failed to install $KMOD_DIR/$KMOD_KO."
    fi
}

install_deps() {
    sudo apt update
    sudo apt install -y $DEPS
}

main() {
    install_deps
    setup_kmod
}

main $*
