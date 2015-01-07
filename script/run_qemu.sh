#!/bin/bash

qemu-system-i386 -d int,pcall,cpu_reset,guest_errors -monitor stdio \
	-name TOs -soundhw all -fda floppy.img 2> \
	logs/$(date +"%F_%H:%m:%S").log
