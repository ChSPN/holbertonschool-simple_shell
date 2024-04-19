#!/bin/bash

# Read the value from /proc/sys/kernel/pid_max
pid_max=$(cat /proc/sys/kernel/pid_max)

# Print the maximum PID value
echo "Maximum PID value: $pid_max"
