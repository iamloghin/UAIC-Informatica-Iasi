############################################## I.1

sfera_area = function(N)
{
  M_C = 0;
  for(i in 1:N)
  {
    x = runif(1, -1, 1);
    y = runif(1, -1, 1);
    z = runif(1, -1, 1);
    if(x*x + y*y + z*z <= 1)
      M_C = M_C + 1;
  }
  return(8*M_C/N);
}

pi = 3.14159265358;
volum_sferei_unitate = 4 * pi / 3; 

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_
  print(value_MC);
  print(value_actual);
  print(eroare_abs);
  print(eroare_rel);
}

erori_calc(sfera_area(50000),volum_sferei_unitate)

############################################## I.2

aria_eclipsa = 2*pi;

elipse_area = function(N)
{
  M_C = 0
  for(i in 1:N)
  {
    x=runif(1,-2,2);
    y=runif(1,-1,1);
    if(x*x+4*y*y<=4)
      M_C = M_C+1;
  }
  return (8*M_C/N);
}

erori_calc(elipse_area(50000),aria_eclipsa)

############################################## II.1

MC_II_1_a = function(N)
{
  sum = 0;
  for(i in 1:N)
  {
    u = runif(1,0,pi);
    c = cos(u);
    sum = sum + c*c;
  }
  return (pi * sum / N);
}

MC_II_1_c = function(N)
{
  sum = 0;
  for(i in 1:N)
  {
    u = runif(1,0,3);
    sum = sum + exp(u);
  }
  return (3 * sum / N);
}

############################################## II.2

MC_II_2_a = function(N)
{
  sum = 0;
  for(i in 1:N)
  {
    u = runif(1,0,100);
    sum = sum + 1 / (u*u + 1);
  }
  return (100 * sum / N);
}

MC_II_2_b = function(N)
{
  sum = 0;
  for(i in 1:N)
  {
    u = runif(1,2,100);
    sum = sum + 1 / (u*U - 1);
  }
  return (sum / N);
}

erori_calc(MC_II_2_a,pi/2)
erori_calc(MC_II_2_b,log(2, base = exp(10))/2)

############################################## III.1

Nr_days = function()
{
  nr_days = 1;
  last_errors = c(11, 16, 18);
  nr_errors = 11;
  while(nr_errors > 0)
  {
    lambda = sum(last_errors)/3;
    nr_errors = rpois(1, lambda);
    last_errors = c(nr_errors, last_errors[1]) ;
    nr_days = nr_days + 1;
  }
  return(nr_days);
}

MC_nr_days = function(N)
{
  s = 0;
  for(i in 1:N)
    s = s + Nr_days();
  aux = s/N;
  print(sprintf("In %.2f saptamani toate erorile vor fi gasite.", aux/7));
  print(sprintf("Returneaza: %f", s/N));
}

MC_nr_days(10000)

