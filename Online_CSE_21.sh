#!/bin/bash
check_capital() {
    if [[ $c =~ [a-z] ]]; then
        echo 0
    else
        echo 1
    fi
}
stored_string=""
flag=0
while true; do
    read user_input
    if [[ $user_input =~ [a-z] ]]; then
        echo "No Capital letter "
        flag=1
        break
    elif [ "$user_input" != "0" ]; then
        stored_string+="$user_input"
        sorted_string=$(echo "$stored_string" | tr A-Z | sort -u)

    else
        break
    fi
done
if [ $flag -ne 1 ]; then
    echo -ne " First character: ${sorted_string:0:1} "
    echo "Last character: ${sorted_string: -1} "
fi
