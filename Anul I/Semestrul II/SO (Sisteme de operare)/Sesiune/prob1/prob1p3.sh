#!/bin/bash

####################################################################################################
# Enunt a treia problema:
#
# Sa se scrie un script bash care primeste ca parametri doua valori numerice 
# strict pozitive n si x si calculeaza in mod RECURSIV termenul Y[n] al sirului 
# {Y[m]}m>=1, definit prin:
#	Y[1]=x, Y[2]=2*x, Y[m]= Y[m-1]^2 + Y[m-2]^2,
# pentru orice m>=3.
#
# La final se va afisa valoarea termenului cerut, Y[n].
#
# Valorile parametrilor n si x se vor da ca argumente la linia de comanda, 
# in caz contrar se vor citi de la tastatura utilizand comanda read.
#
# OBSERVATIE: Y[m-1]^2 este notatia pentru Y[m-1] ridicat la puterea a doua.
#
# EXEMPLU: pentru n=4 si x=5, Y[n] = 15725
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
####################################################################################################

echo "Introdu n= "
read num
n=$num
echo "Introdu x= "
read num
x=$num
y1=x
y2=$((y1*y1))
while((n>=0))
do
	putere=$((y1*y1+y2*y2))
	y1=$((y1*y1))
	y2=$((y1*y1))
	let n--
done
echo "Y[ $n ]= $putere"
