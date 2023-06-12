echo "Enter the length of array: "
read n
for((i=0; i<n; i++))
do read a[$i]
done
largest=${a[0]}
for((i=0; i<n; i++))
do
if((${a[$i]} > $largest))
then largest=${a[$i]}
fi
done
echo "Largest is" $largest
