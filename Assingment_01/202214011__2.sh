#!/bin/bash

to_lowercase() {
    echo "$1" | tr '[:upper:]' '[:lower:]'
}

fruits="apple pineapple mango orange jackfruit exit"

while true; do
    echo "Select an fruit:"
    echo "1) Apple"
    echo "2) Pineapple"
    echo "3) Mango"
    echo "4) Orange"
    echo "5) Jackfruit"
    echo "6) Exit"
    echo "Enter Fruit name or Exit: " 
    read fruitm
    fruit=$(to_lowercase "$fruitm")
  case $fruit in
    apple)
      echo "Apple a day keeps doctor away"
      ;;
    pineapple)
      echo "Pizzas with pineapple!"
      ;;
    mango)
      echo "Mangoes are sweet."
      ;;
    orange)
      echo "Oranges are orange"
      ;;
    jackfruit)
      echo "Jackfruit is our national fruit"
      ;;
    exit)
      echo "Exitting!"
      break
      ;;
    *)
      echo "ERROR!!!!Please select a fruit from the list."
      ;;
  esac
done
