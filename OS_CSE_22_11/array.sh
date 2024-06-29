#!/bin/bash
# we cannot use sh and ./ both . only one of these have to use for specific pcs
#array is 0 indexed in shell scripting
#creation of indexed array
id_array=(51 45 303)

#creation of associative array
declare -A aso_array
aso_array[0]=5
aso_array[1]=2

echo "Enter you desired index"
read i
echo "Indexed array value Before = ${id_array[$i]}"
echo "Associative array value Before = ${aso_array[$i]}"

# id_array[$i]=15;
# aso_array[$i]=100;

# echo "Indexed array value After = ${id_array[$i]}"
# echo "Associative array value After = ${aso_array[$i]}"

id_array+=(19)
aso_array[2]=16
echo "All elements from indexed array = ${id_array[@]}"
echo "All elements form asssociative array = ${aso_array[@]}"

#removing element from array
unset id_array[1]
echo ${id_array[@]}

unset aso_array[1]
echo ${aso_array[@]}

echo " Index Array print using for loop"
for value in "${id_array[@]}";do
    echo $value
done
 
echo "Associative array print using for loop"
for key in "${!aso_array[@]}";do
echo "Key:$key,Value:${aso_array[$key]}"
done