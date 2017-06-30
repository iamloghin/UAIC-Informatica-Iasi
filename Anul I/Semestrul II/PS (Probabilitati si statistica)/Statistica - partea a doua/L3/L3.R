# functia A   F:R->R
#  P(A(x)=F(x))>= 1/2

z=matrix(c(1,2,3,4,5,6,0.15,0.3,0.15,0.1,0.25,0.05), nrow= 2, ncol= 6, byrow=T)


var_aleatoare=function(f)
{
  u=runif(1,0,1)
  aux=0;
  i=0;
  while(u>=aux & u<(aux+f[2,i+1]) & i<ncol(f))
  {
    i=i+1;
    aux=aux+f[2,i];
  }
  return (f[1,i]);
}

var_aleatoare(z)

