n=20
x=seq(0,n,1)
p=0.4
frecv=dbinom(x,n,p)
barplot(frecv,space=0)
frecv2=dpois(x,12)
barplot(frecv2,space=0)
frecv3=dgeom(x,0.4)
barplot(frecv3,space=0)
studenti=c(82,72,82,78,76,84,84,82,87,80,81,69,73,79,79,75,68,80,74,68,77,80,78,81,76,75,70,76,78,82,72,78,86,79,91,70,84,73,69,70,83,76,47,67,76)
medie=mean(studenti)
devstd=sd(studenti)
q1=as.vector(quantile(studenti))[2]
q3=as.vector(quantile(studenti))[4]
median=as.vector(quantile(studenti))[3]
iqr=q3-q1
studenti2=vector()
k=0;
for(i in 1:length(studenti))
{
  if(studenti[i]<q1-1.5*iqr | studenti[i]>q3+1.5*iqr)
  {
    k=k+1
    studenti2[k]=studenti[i]
  }
}

print(studenti2)
