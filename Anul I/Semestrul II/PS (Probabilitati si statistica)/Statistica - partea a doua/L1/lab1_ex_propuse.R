# I. 1
ex1 = function(nume){
  b= scan(nume)
  max = b[1]
  min = b[1]
  total = 0
  luniGrele = 0
  luniUsoare = 0
  for (i in 1:length(b))
  {
    if(b[i]>max) max = b[i]
    if(b[i]<min) min = b[i]
    total = total + b[i]
    if(b[i]>40) luniGrele = luniGrele + 1
    if(b[i]<35) luniUsoare = luniUsoare +1
  }
  print(max)
  print(min)
  print(total)
  print(luniGrele)
  print(luniUsoare)
}
ex1("vector.txt")

# I. 2
ex2 = function(nume)
{
  x= scan(nume)
  a = vector(mode="double")
  b = vector(mode="double")
  for(i in 1:length(x))
  {
    a[i] = log(x[i])
    b[i] = (x[i] - max(x))/min(x)
  }
  print(a)
  print(b)
}
ex2("vector.txt")

# I. 4
ex4 = function(n,p)
{
  x=seq(1,n,1)
  y=dbinom(x,n,p)
  barplot(y,space = 0, main = "Densitatea repartieiei binomiale",xlab = "X", ylab = "Y")
}
ex4(25, 0.3)
ex4(50, 0.7)
ex4(35, 0.5)


# I. 5
ex5 = function(n,p)
{
  return (max(dbinom(0:n,n,p)))
}
print(ex5(50, 0.7))

# I. 6
ex6 = function(n,lambda)
{
  x=seq(0,n,1)
  y=dpois(x,lambda)
  return(y)
}
ex6(5,10)

# I. 7 
ex7 = function(text)
{
  x=read.table(text, header= T)
  a = x[['AA']]
  b = x[['BB']]
  plot(a,b)
}
ex7("text.txt")