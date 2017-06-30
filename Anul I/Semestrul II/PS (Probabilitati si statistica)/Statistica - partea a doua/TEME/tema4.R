# D3
test_proportion=function(alfa,n,succese,p0)
{
  p_prim=succese/n;
  z_score=(p_prim-p0)/sqrt(p0*(1-p0)/n);
  return (z_score);
}

scorz=test_proportion(0.01,112,14,0.1)
critz=qnorm(1-0.01,0,1)
scorz
critz

scorz=test_proportion(0.05,112,14,0.1)
critz=qnorm(1-0.05,0,1)
scorz
critz
