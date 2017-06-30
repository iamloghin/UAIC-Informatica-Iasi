## I.1

# dispersia = sigma
# media = micro
# valoarea critica = Z*
# nivelul de incredere = alfa

# Scrieti o functie care sa reprezinte grafic densitatea legii normale
# N(micro,sigma^2)
# N(0,1) = normala standard.

normal_rule_density <- function(limit, micro, sigma) {
  t = seq(-limit, limit, length = 400)
  f =(1/(sigma/2)*sqrt(2*pi))*exp(-(t-micro)^2/(2*sigma))
  plot(t, f, type = "l", lwd = 1)
}

normal_rule_density(6, 0, 1) 

## II.1

# Scrieti intr-un script functia descrisa mai sus si aplicati-o fisierului

det_selection_mean <- function(filename) {
  x = scan(filename)
  med = mean(x)
  med
}

det_selection_mean("history.txt")

## III.1

# Scrieti o functie care sa calculeze intervalul de incredere

zconfidence_interval <- function(niv_inc, medie_sel, esan, disp) {
  alfa = niv_inc
  selection_mean = medie_sel
  n = esan
  sigma = sqrt(disp)
  critical_z = qnorm(1-alfa/2, mean = 0, sd = 1)
  a = selection_mean - critical_z * sigma / sqrt(n)
  b = selection_mean + critical_z * sigma / sqrt(n)
  interval = c(a,b)
  interval
}

zconfidence_interval(0.1, 20, 100, 9)

## III.2

# Se cauta un interval  de incredere de 90% pentru media unei populatii normale 
# cu dispersia cunoscuta σ2  = 100. Pentru aceasta  se utilizeaza un  esantion
# aleator simplu  de 25 de indivizi a carui medie de selectie (calculata) 
# este 67.53.

zconfidence_interval(0.1, 67.53, 25, 100)

## III.4

# Intr-o ıncercare  disperata  de a concura  General  Electric,
# compania  ACME  introduce  un nou tip  de becuri.   ACME  fabrica  initial 
# 100 de becuri a caror  medie de viata  masurata este 1280 de ore 
# (deviatia standard a populatiei este 140 de ore). 
# Sa se gaseasca un interval de incredere de 99% pentru media de viata a becurilor.

zconfidence_interval(0.01, 1280, 100, 140^2)

## IV.1

# Scrieti intr-un script o functie  care sa calculeze intervalul de in credere 
# Functia aceasta  va fi utilizata la rezolvarea  exercitiilor de mai jos.

t_conf_interval <- function(niv_inc, medie_sel, esan, deviatie) {
  alfa = niv_inc
  selection_mean = medie_sel
  n = esan
  s = deviatie
  se = s/sqrt(n)
  critical_t = qt(1-alfa/2, n-1)
  a = selection_mean - critical_t * se
  b = selection_mean + critical_t * se
  interval = c(a,b)
  interval
}

t_conf_interval(0.05, 3.3, 60, 0.4)

## IV.2

# 196 de studenti alesi aleator  au fost intrebati cat de multi bani
# au investit in cumparaturi online saptamana trecuta. Media a fost 
# calculata la 44.65$, cu o dispersie (a esantionului) egala  cu s^2= 2.25.
# Calculati  un  interval  de incredere  de 99% pentru  media  populatiei.
# se presupune ca urmeaza o lege normala.

t_conf_interval(0.01, 44.65, 196, sqrt(2.25))

## IV.5

# Pentru un esantion aleator simplu dintr-o  populatie normala cu dispersia
# necunoscuta se masoara urmatoarele valori:
# 12 11 12 10 11 12 13 12 11 11 13 14 10
# Sa se determine, utilizand aceste date,  intervalele  de incredere de 90%,
# 95% si 99% pentru media populatiei.

x=c(12,11,12,10,11,12,13,12,11,11,13,14,10)
t_conf_interval( 0.1, mean(x), length(x), sd(x))
t_conf_interval(0.05, mean(x), length(x), sd(x))
t_conf_interval(0.01, mean(x), length(x), sd(x))

## V.1

# Scrieti intr-un script  o functie care sa calculeze si sa returneze valoarea
# critica si scorul testului  proportiilor. 

test_proportion <- function(alfa, n, succese, p0)
{
  p_prim = succese/n
  if(p_prim>p0)
    print("Ipoteza asimetrica la dreapta")
  else
    print("Ipoteza asimetrica la stanga")
  z_score = (p_prim - p0) / sqrt(p0*(1-p0)/n)
  z_critical = qnorm(1 - alfa, 0, 1)
  print(z_score)
  print(z_critical)
  if(z_score<z_critical)
    print("Scorul testului este mai mic decat valoarea critica")
  else
    print("Scorul testului este mai mare decat valoarea critica")
  if(z_score<z_critical)
  {
    if(p_prim<p0)
      print("! Ipoteza nula este respinsa !")
    else
      print("! nu exista suficiente dovezi pentru a respinge ipoteza nula !")
  }
  if(z_score>z_critical)
  {
    if(p_prim>p0)
      print("! Ipoteza nula este respinsa !")
    else
      print("! nu exista suficiente dovezi pentru a respinge ipoteza nula !")
  }
}

test_proportion(0.01, 100, 63, 0.6)

## V.2

# Se presupune ca dintr-un numar  mare de componente,  10% sunt defecte.
# Se testeaza daca procentul  defectelor a crescut.
# Se testeaza in acest sens 150 de componente si se determina ca 20 dintre ele
# sunt defecte. Se poateafirma cu nivel de semnificatie de 5% ca procentul 
# componentelor defecte este mai mare decat 10%?

test_proportion(0.05,150,20,0.1)

## V.3

# Sa se testeze o ipoteza adecvata pentru datele de mai jos.
# Proportia este numarulde purici inlaturati (killed fleas) supra numarul total
# de purici (fleas).

test_proportion(0.01,42,17,0.25)
