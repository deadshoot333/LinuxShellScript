#!/bin/bash

addition() {
    echo $(($1 + $2))
}

subtraction() {
    echo $(($1 - $2))
}

multiplication() {
    echo $(($1 * $2))
}

division() {
    if [ $2 == 0 ]; then
        echo "Can't divide by zero"
    else
        echo $(($1 / $2))
    fi
}

while true; do
    echo "Enter the first number: " 
    read num1
    echo "Enter the second number: " 
    read num2
    
    echo "Select an operation:"
    echo "1) Addition"
    echo "2) Subtraction"
    echo "3) Multiplication"
    echo "4) Division"
    echo "5) Exit"
    echo "Enter your choice: "
    read choice

    case $choice in
        1)
            result=$(addition $num1 $num2)
            echo "Result: $num1 + $num2 = $result"
            ;;
        2)
            result=$(subtraction $num1 $num2)
            echo "Result: $num1 - $num2 = $result"
            ;;
        3)
            result=$(multiplication $num1 $num2)
            echo "Result: $num1 * $num2 = $result"
            ;;
        4)
            result=$(division $num1 $num2)
            echo "Result: $num1 / $num2 = $result"
            ;;
        5)
            echo "Exiting...."
            break
            ;;
        *)
            echo "Invalid choice."
            ;;
    esac
done
