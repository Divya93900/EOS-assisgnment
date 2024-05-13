echo -n "enter three numbers:"
read num1 num2 num3
max=0
if [ $num1 -gt $num2 -o $num1 -gt $num3 ]
then
	echo "num1 is greater"
	max=$num1
elif [ $num2 -gt $num3 -o $num2 -gt $num1 ]
then
	echo "num2 is greater"
	max=$num2
elif [ $num3 -gt $num1 -o $num3 -gt $num2 ]
then
	echo "num3 is greater"
	max=$num3
else 
	echo "all are equal"
	max=$num1
fi
echo "maximum value =$max"



