#!/bin/bash

# Function to run command with timeout and measure duration
run_with_timeout() {
    local timeout=$1
    shift
    { time ($@) >/dev/null 2>&1; } &
    local pid=$!
    sleep $timeout
    if ps -p $pid > /dev/null; then
        kill $pid >/dev/null 2>&1
        wait $pid >/dev/null 2>&1
    fi
}

# Record start time
start_time=$SECONDS

cd ../  # Move up to the parent directory where executables are located

EXECS="0_1 0_2 0_3 0_4 1_0"  # List of executables
echo "Executable | PID | Quick Check | Leaked Bytes | Duration"

for exec in $EXECS; do
    # Start the executable with /bin/ls as a parameter using custom timeout function
    { run_with_timeout 5 ./$exec /bin/ls -l; } 2>&1
    exec_pid=$!

    # Check if the process terminated or was killed due to timeout
    if ps -p $exec_pid > /dev/null; then
        leaked_bytes="Process terminated (timeout)"
    else
        # Check for memory leaks
        leak_info=$(leaks $exec_pid 2>/dev/null | grep 'leaks for')
        if [ -n "$leak_info" ]; then
            leaked_bytes=$(echo $leak_info | awk '{print $4 " leaked bytes"}')
        else
            leaked_bytes="No memory leaks found"
        fi
    fi

    # Get execution duration
    duration=$((SECONDS - start_time))

    # Output in tabular format
    printf "%-12s | %-5d | %-15s | %-12s | %-8s\n" $exec $exec_pid "Command sent" "$leaked_bytes" "$duration"
done

cd -  # Return to the original directory (tests/)
