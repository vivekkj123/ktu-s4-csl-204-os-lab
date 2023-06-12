echo "Enter the no. of numbers"
read n
for((i=0; i<=n; i++))
do 
((sum=sum+$i))
done
echo "Sum is: " $sum
