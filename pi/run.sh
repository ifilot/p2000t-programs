#!/bin/bash

#
# Launch a program using the M2000 emulator of Marcel de Kogel
#

# Set location of M2000 executable. To acquire a copy of the emulator,
# go to https://github.com/p2000t/software
LOC=/d/PROGRAMMING/P2000T/p2000t-software/emulators/m2000-win64

# copying files
cp -v $LOC/p2000rom.bin .
cp -v main.rom BASIC.BIN
cp -v $LOC/Default.fnt .

# running program
$LOC/m2000.exe

# cleaning up
rm -v ./BASIC.BIN
rm -v ./p2000rom.bin
rm -v ./Default.fnt
rm -vf P2000.cas