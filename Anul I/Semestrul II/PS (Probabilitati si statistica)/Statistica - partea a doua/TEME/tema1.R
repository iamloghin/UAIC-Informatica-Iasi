su## A.1

n=20
k=seq(0,n,1)
p=0.4
barplot(dbinom(k,n,p),space=0.1)
barplot(dpois(k,12),space=0.1)
barplot(dgeom(k,0.4),space=0.1)

## A.2

mase_studenti = c(82, 72, 82, 78, 76, 84, 84, 82, 87, 80, 81, 69, 73, 79, 79, 75, 68, 80, 74, 68, 77, 80, 78, 81, 76, 75, 70, 76, 78, 82, 72, 78, 86, 79, 91, 70, 84, 73, 69, 70, 83, 76, 47, 67, 76)

mean(mase_studenti)  #media
median(mase_studenti) #mediana
sd(mase_studenti)  #deviatia standard
min(mase_studenti) #minim
max(mase_studenti) #maxim
summary(mase_studenti) #quantile
as.vector(quantile(mase_studenti))[2] #Q1
as.vector(quantile(mase_studenti))[4] #Q3

valori_aberante = function(x)
{
  m = mean(x);
  s = sd(x);
  v = vector();
  j = 0;
  stanga = m - 2*s;
  dreapta = m + 2*s;
  for(i in 1:length(x))
  {
    if(x[i] < stanga | x[i] > dreapta)
    {
      j = j + 1;
      v[j]=x[i];
    }
  }
  print(v);
}

valori_aberante(mase_studenti)