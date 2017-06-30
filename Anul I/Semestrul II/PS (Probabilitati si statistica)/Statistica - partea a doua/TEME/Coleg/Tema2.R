# B1
quicksort=function(S)
{
  if(length(S)>1)
  {
    x=sample(1:length(S),1);
    pivot=S[x];
    li=1;
    ls=length(S);
    while(li<=ls)
    {
      while(S[li]<pivot)
        li=li+1;
      while(S[ls]>pivot)
        ls=ls-1;
      if(li<=ls)
      {
        aux=S[li];
        S[li]=S[ls];
        S[ls]=aux;
        li=li+1;
        ls=ls-1;
      }
    }
    return (c(quicksort(S[S<pivot]),pivot,quicksort(S[S>pivot])));
  }
  return (S);
}

x=c(10,5,-8,2,12,20,1,-3)
quicksort(x)

# B2

Rand_Min_Cut=function(G)
{
  while(nrow(G)>2)
  {
    e=sample(1:nrow(G),2,replace=T);
    while(G[e[1],e[2]]==0)
    {
      e=sample(1:nrow(G),2,replace=T);
    }
    for(j in 1:ncol(G))
    {
      if(G[e[2],j]>0&j!=e[1])
      {
        G[e[1],j]=G[e[1],j]+G[e[2],j];
        G[j,e[1]]=G[e[1],j];
      }
    }
    G=G[-e[2],];
    G=G[,-e[2]];
  }
  return (G);
}

y=c(0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0)
M=matrix(y,6,6)
Rand_Min_Cut(M)