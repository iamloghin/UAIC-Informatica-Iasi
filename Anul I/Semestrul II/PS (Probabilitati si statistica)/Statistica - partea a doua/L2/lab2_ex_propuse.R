# I.1 Stem-and-leaf

x = scan("sample1.txt")
stem(x)

# I.2 Histograma (2 coloane "country" si "rate")
# (0; 4], (4; 6], (6; 8], (8; 10], (10; 12], (12; 14], (14; 300]
  
tablou = read.csv("unemploy2012.csv", header = T, sep = ';')
rate = tablou[['rate']]

interval = c(0, 4, 6, 8, 10, 12, 14, 30)
hist(rate, breaks = interval, right = T, freq = F, col = "green")

# I.3 

tablou = read.csv("life_expect.csv", header = T, sep = ",")
life_man = tablou[['male']]
life_female = tablou[['female']]

hist(life_man, breaks = 7, right = F, freq = F, col = "blue")
hist(life_female, breaks = 7, right = F, freq = F, col = "orange")


# II. 1

temp = scan("sample1.txt")
mean(temp)    # media
median(temp)  # mediana


# II. 2

tablou = read.csv("life_expect.csv", header = T, sep = ",")
life_man = tablou[['male']]
life_female = tablou[['female']]

mean(life_man)    # media MAN
median(life_man)  # mediana MAN

mean(life_female)    # media FEMALE
median(life_female)  # mediana FEMALE

# II. 3

module = function(esantion)
{
  a=rle(sort(esantion))
  maxim=max(a$lengths) # print(a$lengths)
  aux=vector()   # sir modular
  k=0
  for(i in 1:length(a$values))
  {
    if(a$lengths[i]==maxim)
    {
      k=k+1
      aux[k]=a$values[i]
    }
  }
  return (aux)
}

exemplu3 = c(6,6,6,5,3,8,5,3,3,7)
module(exemplu3)

# III. 1
outliers_mean = function(esantion)
{
  medie = mean(esantion)
  derivatiaStandard = sd(esantion)
  aux = vector()
  j = 0
  for( i in 1 : length(esantion))
  {
    if(esantion[i] <= medie - 2 * derivatiaStandard & esantion[i] >= medie + 2 * derivatiaStandard)
    {
      j = j + 1
      aux[j]=esantion[i]
    }
  }
  aux
}

sample = c(1, 91, 38, 72, 13, 27, 11, 19, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17)
outliers_mean(sample)

# III. 2
outliers_iqr = function(esantion)
{
  quantila = quantile(esantion)
  aux = vector()
  j = 0
  for( i in 1 : length(esantion))
  {
    if(esantion[i] <= as.vector(quantila)[2] - 1.5 * (as.vector(quantila)[4] - as.vector(quantila)[2]) & esantion[i] >= as.vector(quantila)[4] + 1.5 * (as.vector(quantila)[4] - as.vector(quantila)[2]))
    {
      j = j + 1
      aux[j]=esantion[i]
    }
  }
  aux
}

sample = c(1, 91, 38, 72, 13, 27, 11, 19, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17)
outliers_iqr(sample)

# III. 3

ex3= function(esantion)
{
  summary(esantion)
}

sample = scan("sample2.txt")
ex3(sample)