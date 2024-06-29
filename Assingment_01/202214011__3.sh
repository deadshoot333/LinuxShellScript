#!/bin/bash

factorial() {
    local num=$1
    if [[ $num == 1 ]]; then
        echo 1
    else
        local temp=$(( num - 1 ))
        local result=$(factorial $temp)
        echo $(( num * result ))
    fi
}

echo "Enter a number:" 
read number

result=$(factorial $number)

echo "The factorial of $number is: $result"
