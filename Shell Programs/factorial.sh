echo "Enter the no."
read n
fact=1
for((i=n; i>0; i--))
do ((fact=fact*i))
done
echo "Factorial is: " $fact
