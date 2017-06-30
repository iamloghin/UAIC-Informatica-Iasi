#!/bin/bash

function Y()
{
	if [ $1 -eq 1 ]
	then
		echo $2
	elif [ $1 -eq 2 ]
	then
		let rez=$2*2
		echo $rez
	else
		let term_1=$1-1
		let term_2=$1-2
		let Y1=`Y $term_1 $2`
		let Y2=`Y $term_2 $2`
		let rez=$Y1*$Y1+$Y2*$Y2
		echo $rez
	fi
}

if [ $# -lt 1 ] 
then
	echo "Dati n:"
	read n
else
	n=$1
fi

if [ $# -lt 2 ] 
then
	echo "Dati x:"
	read x
else
	x=$2
fi

echo -n "Y[$n]="
Y $n $x
