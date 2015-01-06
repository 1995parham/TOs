#!/bin/bash

qemu-system-i386 -monitor stdio -name TOs -soundhw all -fda floppy.img
