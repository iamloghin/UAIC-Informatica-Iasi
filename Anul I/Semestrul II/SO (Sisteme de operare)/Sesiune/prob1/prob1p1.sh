 #!/bin/bash

#######################################################################################################
# Enunt prima problema:
#
# a) Cum se numeste comanda folosita pentru a afisa primele linii ale unui fisier
#    si care este optiunea ce controleaza numarul de linii care sa fie afisate?
# b) Sa se scrie linia de comanda pentru a afisa tot continutul fisierului '/etc/passwd',
#    mai putin ultimele 21 linii.
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
#######################################################################################################

a) head -n (default comanda afiseaza primele 10 linii) si  cut -f -d:

b) head --lines=-21 /etc/passwd 
