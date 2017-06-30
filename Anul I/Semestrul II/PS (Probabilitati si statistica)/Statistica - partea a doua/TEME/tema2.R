## B1

QuickSort=function(S)
{
  if(length(S)<=1)
    return(S);
  
  random = sample(1:length(S),1)
  pivot = S[random]
  right = length(S)
  left = 1
  
  while(left<right)
  {
    while(S[left] < pivot)
      left = left + 1
    while(S[right] > pivot)
      right = right - 1
    if(left <= right)
    {
      aux = S[left]
      S[left] = S[right]
      S[right] = aux
      left = left + 1
      right = right - 1
    }
  }
  
  return(c(QuickSort(S[S<pivot]),pivot,QuickSort(S[S>pivot])))
}

sir=c(15,-3,9,8,5,2,-7,1,6,0)
QuickSort(sir)

## B2

RandMinCut=function(G)
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

list=c(0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0)
Matrice=matrix(list,6,6)
RandMinCut(Matrice)