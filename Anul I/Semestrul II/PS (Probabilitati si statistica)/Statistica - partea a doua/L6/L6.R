## I.1

# I. Testul Z pentru media unei populatii cu dispersia cunoscuta

# Scrieti o functie (numita Z test) care sa calculeze si sa returneze valoareacritica si scorul 
# testului. Functia aceasta va fi utilizata apoi la rezolvarea  exercitiilor de mai jos.

med_pop_disp_cunosc <- function(alfa, population_mean, sample_mean, n, sigma)
{
  critical_z = qnorm(1-alfa)
  z_score = (sample_mean - population_mean)/(sigma/sqrt(n))
  if(population_mean < sample_mean)
  {
    print("Ipoteza este asimetrica la stanga !")
    if(z_score<critical_z)
      print("Ipoteza nula este respinsa !")
    else
      print("Ipoteza nula poate fi respinsa, se accepta ipoteza initiala !")
  }
  else
  {
    print("Ipoteza este asimetrica la stanga !")
    if(z_score>critical_z)
      print("Ipoteza nula este respinsa !")
    else
      print("Ipoteza nula poate fi respinsa, se accepta ipoteza initiala !")
  }
  print(critical_z)
  z_score
}

med_pop_disp_cunosc(0.05, 810, 816, 200, 50)

## I.2

# Dintr-o populatie normala cu dispersia sigma^2= 144 se selecteaza 49 de indivizi a caror medie
# este 88. Sa se testezeipoteza ca media populatiei este mai mica decat 90.

med_pop_disp_cunosc(0.05,90,88,49,sqrt(144))

## I.3

# Din experienta se stie ca rezultatele studentilor la un test de matematica urmeaza o lege
# normala cu media 75 si dispersia 17. Catedra de matematica doreste sa afle daca studentii
# din anul curent au un comportament atipic. Media rezultatelor unui grup de 36 studenti 
# este 85 de puncte. Cu 1% nivel de semnificatie se poate trage concluzia ca studentii 
# din anul curent sunt atipici?

med_pop_disp_cunosc(0.01,85,75,36,17)

## I.4

# Pe cutiile de un anumit tip de detergent este indicata o greutate de 21oz. O agentie de protectie
# a consumatorilor doreste sa testeze aceasta greutate cu 1% nivel de semnificatie.
# Pentru 100 de cutii gaseste o greutate medie de 20.5oz. Daca se stie ca deviatia standard
# a greutii este 2.5oz, agentia poate pretinde marirea cantitatii de detergent dintr-o cutie?

med_pop_disp_cunosc(0.01,21,20.5,100,2.5)

## II.1

# Testul t pentru media unei populatii cu dispersia necunoscuta

# Scrieti doua functii (de tipul t_test) care sa calculeze si sa returneze valoarea critica
# si scorul testului  t: una  dintre  functii  va  trebui  sa  citeasca  esantionul dintr-un  
# fisier, iar  cealalta va primi ca argumente tipul  ipotezei  alternative, media  de selectie, 
# deviatia standard a esantionului etc. Functiile acestea  vor fi utilizate, dupa caz pentru 
# rezolvarea exercitiilor de mai jos.

t_test1 = function(file)
{
  x = scan(file);
  return(x)
}

med_pop_disp_nec = function(alfa, n, population_mean, sample_mean, x, file)
{
  if(length(x) == 1)
    x = t_test1(file);
  s = sd(x);
  se = s/sqrt(n);
  t_score = (sample_mean - population_mean)/se;
  if(sample_mean<population_mean)
  {
    critical_t = qt(alfa, n - 1)
    if(t_score<critical_t)
      print("Ipoteza nula este respinsa")
    else
      print("Ipoteza nula nu poate fi respinsa!")
  }
  else if(sample_mean>population_mean)
  {
    critical_t = qt(1 - alfa, n - 1);
    if(t_score>critical_t)
      print("Ipoteza nula este respinsa")
    else
      print("Ipoteza nula nu poate fi respinsa!")
  }
  else
  {
    critical_t = qt(1-alfa/2, n-1)
    if(abs(t_score)>abs(critical_t))
      print("Ipoteza nula este respinsa")
    else
      print("Ipoteza nula nu poate fi respinsa!")
  }
}

## II.2

# Se masoara pentru un esantion provenit dintr-o  populatie normala urmatoarele valori:
# 36 32 28 33 41 28 31 26 29 34
# Cu 1% nivel de semnificatie sa se testeze ipoteza ca media are o valoare diferita de 34.

x = c(36, 32, 28, 33, 41, 28, 31, 26, 29, 34);
med_pop_disp_nec(0.01, length(x), 34, mean(x), x)

## II.4

# Media rezultatelor unui  test la istorie este  de 80 de puncte. Catedra de istorie doreste 
# sa afle daca studentii actuali au un comportament tipic la acest test. Pentru un esantion 
# aleator simplu rezultatele se gasesc in fisierul history.txt. Sa se formuleze si sa se testeze
# ipoteza alternativa corespunzatoare (cu 1% si 5% nivel de semnificatie).

x = t_test1("history.txt")
med_pop_disp_nec(0.01, length(x), 80, mean(x), x)

## III.1

# Testul Z pentru diferenta mediilor unor populatii cu dispersii cunoscute

# Scrieti o functie  (numita de exemplu, z_test_means) care sa  calculeze si  sa  returneze 
# valoarea  critica si scorul testului Z pentru diferenta mediilor. Functia aceasta va fi 
# utilizata, pentru rezolvarea exercitiilor de mai jos.

diferenta_mediilor_disp_cunosc = function(alfa, sample1_mean, sample2_mean, n1, n2, sigma1, sigma2)
{
  m0=0
  combined_sigma = sqrt(sigma1^2/n1 + sigma2^2/n2)
  score_z = (sample1_mean-sample2_mean-m0)/combined_sigma
  if(sample1_mean-sample2_mean<m0)
  {
    print("Avem: Ipoteza asimetrica la stanga!")
    critical_z = qnorm(alfa, 0, 1);
    if(score_z<critical_z)
      print("Ipoteza nula este respinsa!")
    else
      print("Ipoteza nula este acceptata!")
  }
  else if(sample1_mean-sample2_mean>m0)
  {
    print("Avem: Ipoteza asimetrica la dreapta!")
    critical_z = qnorm(1-alfa, 0, 1);
    if(score_z>critical_z)
      print("Ipoteza nula este respinsa!")
    else
      print("Ipoteza nula este acceptata!")
  }
  else
  {
    print("Avem: Ipoteza simetrica!")
    critical_z = qnorm(1-alfa/2, 0, 1);
    if(abs(score_z)>abs(critical_z))
      print("Ipoteza nula este respinsa!")
    else
      print("Ipoteza nula este acceptata!")
  }
}

diferenta_mediilor_disp_cunosc(0.05, 48, 47, 100, 100, 4, 3)

## III.2

# 80 dintre angajatii alesi aleator ai unei firme foarte mari au un salariu  mediu saptamanal 
# de 160$ (deviatia standard a intregii populatii fiind 3.24$). 70 dintre angajatii unei alte 
# firme au in medie 155$ salariu pe saptamana (deviatia standard a intregii populatii fiind 
# 2.25$). Sa se testeze daca salariul  mediu saptamanal la cele doua firme difera semnificativ 
# (1% nivel de semnificatie).

diferenta_mediilor_disp_cunosc(0.01, 160, 155, 80, 70, 3.24, 2.25)

## III.3

# Un raport recent arata ca absolventii de universitate fara diploma se casatoresc mai repede 
# decat cei cu  diploma.  Sunt alesi cate 100 de indivizi  din  cele doua populatii;
# pentru aceste doua esantioane absolventii fara diploma se casatoresc in medie la 22.8 ani 
# (deviatia standerd cunoscuta populatiei fiind sigma1 = 1.3 ani) iar cei cu diploma la 23.3 ani 
# (deviatia cunoscuta a populatiei este sigma2  = 1.9 ani). Cu 1% nivel de semnificatie se poate
# trage concluzia ca raportul este corect?

diferenta_mediilor_disp_cunosc(0.01, 22.8, 23.3, 100, 100, 1.3, 1.9)

## IV.1

# Inferenta asupra dispersiilor a doua populatii - Testul F

# Scrieti o functie (numita F_test) care sa calculeze si sa returneze valoarile critice si 
# scorul testului  F. Functia aceasta  va fi utilizata apoi la rezolvarea  exercitiilor care urmeaza.

#            x1 = read.table(”program.txt”, header  = TRUE)[[’A’]]
#            x2 = read.table(”program.txt”, header  = TRUE)[[’B’]]
#            n1 = length(x1)
#            s1 = sd(x1)

Inferenta_asupra_disp = function(alfa, n1, n2, s1, s2)
{
  critical_F_s = qf(alfa/2, n1-1, n2-1)
  critical_F_d = qf(1-alfa/2, n1-2, n2-1)
  score_F = sqrt(s1)/sqrt(s2)
  if(score_F<critical_F_s || score_F>critical_F_d)
    print("Ipoteza nula este respinsa!")
  else
    print("Nu exista suficiente dovezi pentru a respinge ipoteza nula!")
}

Inferenta_asupra_disp(0.01, 120, 135, 5.05, 5.44)

## IV.2

# Un profesor crede ca un anumit program  de lectura  imbunatateste  abilitatile si dorinta 
# copiilor de a citi. Pentru aceasta  el alege doua grupuri de elevi: unulde 22 de elevi care 
# urmeaza [rogramul  prescris (A) si unul de 22 de elevi care nu urmeaza acest program (B). 
# Rezultatele sunt date in fisierul program.txt.
# Sa se decida cu 1% si 5% nivel de semnificatie daca dispersiile celor doua populatii sunt diferite. 

x1 = read.table("program.txt", header=T)[['A']]
x2 = read.table("program.txt", header=T)[['B']]

Inferenta_asupra_disp(0.01, length(x1), length(x2), sd(x1), sd(x2))
Inferenta_asupra_disp(0.05, length(x1), length(x2), sd(x1), sd(x2))

## IV.3

# Cercetatorii studiaza amplitudinea miscarii obtinuta prin stimularea nervoasa a soarecilor.
# Pentru soarecii drogati se obtin urmatoarele date:
# 12.512 12.869 19.098 15.350 13.297 15.589
# Pentru soarecii normali se obtin urmatoarele date:
# 11.074 9.686 12.164 8.351 12.182 11.489
# Influenta drogurilor este semnificativa in ceea ce priveste cele doua dispersii (5% nivel de semnificatie)?

drogati = c(12.512, 12.869, 19.098, 15.350, 13.297, 15.589)
normali = c(11.074, 9.686, 12.164, 8.351, 12.182, 11.489)

Inferenta_asupra_disp(0.05, length(drogati), length(normali), sd(drogati), sd(normali))

## V.1

# Testul T pentru diferenta mediilor unor populatii cu dispersii necunoscute

# Scrieti o functie  (numita,  de exemplu, T_test_ means) care sa calculeze si sa returneze 
# valoarea  critica si scorul testului T pentru diferenta mediilor; aceasta functie va include 
# si testul  F simetric.  Functia aceasta va fi utilizata pentru rezolvarea  exercitiilor care 
# urmeaza.

Dif_mediilor_dips_nec = function(alfa, sample1_mean, sample2_mean, n1, n2, s1, s2)
{
  m0=0
  critical_F_s= qf(alfa/2, n1 - 1, n2 - 1) # testul F
  critical_F_d= qf(1 - alfa/2, n1 - 1, n2 - 1)
  F_score = s1^2/ s2^2
  if(F_score<critical_F_s | F_score>critical_F_d)
  {
    df = min(n1 - 1, n2 - 1);
    combined_s = sqrt(s1^2/n1 + s2^2/n2);
  }
  else
  {
    df = n1 + n2 - 2;
    combined_s = sqrt(((n1 - 1)*s1^2 + (n2 - 1)*s2^2)/df)*sqrt(1/n1+1/n2);
  }
  critical_t = qt(1 - alfa/2, df)
  t_score = (sample1_mean - sample2_mean - m0)/combined_s
  if(sample1_mean-sample2_mean<m0)
  {
    print("Ipoteza asimetrica la stanga!")
    if(t_score<critical_t)
      print("Ipoteza nula este respinsa!")
    else
      print("Nu exista suficiente dovezi pentru a respinge ipoteza nula!")
  }
  else if(sample1_mean-sample2_mean>m0)
  {
    print("Ipoteza asimetrica la dreapta!")
    if(t_score>critical_t)
      print("Ipoteza nula este respinsa!")
    else
      print("Nu exista suficiente dovezi pentru a respinge ipoteza nula!")
  }
  else
  {
    print("Ipoteza simetrica!")
    if(abs(t_score)>abs(critical_t))
      print("Ipoteza nula este respinsa!")
    else
      print("Nu exista suficiente dovezi pentru a respinge ipoteza nula!")
  }
  print(critical_t)
  t_score
}

## V.2

# Un profesor crede ca un  anumit  program  de lectura  imbunatateste  abilitatile  si  dorinta 
# copiilor de a citi. Pentru aceasta el alege doua grupuri de elevi: unul de 22 de elevi care 
# urmeaza programul  prescris (A) si unul de 22 de elevi care nu urmeaza acest program  (B). 
# Rezultatele sunt date in fisierul program.txt.
# Sa  se decida  cu 1% si 5% nivel de semnificatie  daca  mediile celor doua  populatii difer semnificativ.

x1 = read.table("program.txt", header=T)[['A']]
x2 = read.table("program.txt", header=T)[['B']]

Dif_mediilor_dips_nec(0.01, mean(x1), mean(x2), length(x1), length(x2), sd(x1), sd(x2))
Dif_mediilor_dips_nec(0.05, mean(x1), mean(x2), length(x1), length(x2), sd(x1), sd(x2))

## V.3

# Cercetatorii studiaza amplitudinea miscarii obtinuta prin stimularea nervoasa a soarecilor.
# Pentru soarecii drogati se obtin urmatoarele date:
# 12.512 12.869 19.098 15.350 13.297 15.589
# Pentru soarecii obisnuiti se obtin urmatoarele date:
# 11.074 9.686 12.164 8.351 12.182 11.489
# Influenta drogurilor este semnificativa in ceea ce priveste cele doua  medii (1% nivel de semnificatie)? 
  
drogati = c(12.512, 12.869, 19.098, 15.350, 13.297, 15.589)
normali = c(11.074, 9.686, 12.164, 8.351, 12.182, 11.489)

Dif_mediilor_dips_nec(0.01, mean(drogati), mean(normali), length(drogati), length(normali), sd(drogati), sd(normali))

