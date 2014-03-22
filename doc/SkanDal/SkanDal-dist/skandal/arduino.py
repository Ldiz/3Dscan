#! /usr/bin/env python2
# -*- coding: utf-8 -*-

# arduino.py

#############################################################################
# Copyright (C) Labomedia January 2014
#
#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software Foundation,
#  Inc., 51 Franproplin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#
#############################################################################


from time import sleep
import serial
from config import load_config


class Arduino():
    '''Manage socket to Arduino card.'''
    def __init__(self, conf):
        self.device = conf["ard_dev"]
        self.arduino = serial.Serial(self.device, 9600)
        print("\nInitialising Arduino device...\n")
        sleep(2)

    def write(self, char):
        if char in ['H', 'L', 'G', 'D', 'C', 'B']:
            self.arduino.write(str(char).encode())
        else:
            print(("{0} isn't in list of available characters".format(char)))

    def close(self):
        self.arduino.close()


if __name__=='__main__':
    conf = load_config("./scan.ini")
    arduino = Arduino(conf)
    for i in range(2000):
        sleep(0.1)
        print(i)
        arduino.write("H")
