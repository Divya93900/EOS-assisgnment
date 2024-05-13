#!/bin/bush
echo -n "enter the year :"
read y
expr if [ (($y % 100)) -eq 0 ]
then
	if [  (($y % 4)) -eq 0 ]
	then
	echo " lear year "
	fi
elif [ (($y % 4)) -eq 0 ]
then
	echo "leap year"
else 
	echo "non leap year"
fi
