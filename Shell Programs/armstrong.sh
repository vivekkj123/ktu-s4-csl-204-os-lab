echo "Enter a number: "
read num
copy=num
sum=0
n=0
while((copy != 0))
do ((n=$n+1))
((copy=copy/10))
done
copy=$num
while((num != 0))
do 
((rem=$num%10))
((sum=$sum+($rem**$n)))
((num=($num/10)))
done
if (($copy==$sum))
then
echo "Armstrong Number"
else
echo "Not a Armstrong Number"
fi
