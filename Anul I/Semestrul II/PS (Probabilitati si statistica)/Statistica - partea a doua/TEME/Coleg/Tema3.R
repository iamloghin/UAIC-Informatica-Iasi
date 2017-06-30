# C1
elipsoid_de_revolutie_volume=function(N)
{
  N_C=0;
  for(i in 1:N)
  {
    x=runif(1,-2,2);
    y=runif(1,-3,3);
    z=runif(1,-4,4);
    if((x*x/4)+(y*y/9)+(z*z/16)<=1)
      N_C=N_C+1;
  }
  return (8*6*4*N_C/N);
}

err=function(value_MC,value_actual)
{
  err_abs=abs(value_MC-value_actual);
  err_rel=err_abs/abs(value_actual);
  print(value_actual);
  print(value_MC);
  print(err_abs);
  print(err_rel);
}

volum_elipsoid_de_revolutie=3.14159265358*24*4/3;

err(elipsoid_de_revolutie_volume(10000),volum_elipsoid_de_revolutie);
err(elipsoid_de_revolutie_volume(20000),volum_elipsoid_de_revolutie);
err(elipsoid_de_revolutie_volume(50000),volum_elipsoid_de_revolutie);

# C3
#(a)
MC_integration_aC3=function(N)
{
  s=0;
  for(i in 1:N)
  {
    u=runif(1,0,1);
    si=sin(20*u);
    co=cos(50*u);
    s=s+(co+si)*(co+si);
  }
  return (s/N);
}
#(b)
MC_integration_bC3=function(N)
{
  s=0;
  for(i in 1:N)
  {
    x=runif(1,0,3);
    s=s+(x^3)/(x^4+1);
  }
  return (3*s/N);
}

# C4
MC_retea=function(N)
{
  s=0;
  for(i in 1:N)
  {
    x=rexp(1,1);
    g1=rgamma(1,shape=5,scale=3);
    g2=rgamma(1,shape=7,scale=5);
    g3=rgamma(1,shape=5,scale=2);
    u=runif(1,0,1);
    if(u<=0.5)
    {
      s=s+g1;
    }
    else
    {
      if(u>0.8)
      {
        s=s+g3;
      }
      else
      {
        s=s+g2;
      }
    }
    s=s+x;
  }
  return (s/N);
}

# C7
conturi=function()
{
  nr_days=1;
  p=0.25;
  nr=19;
  nr=nr-rbinom(1,19,0.25);
  print(nr);
  while(nr>0&nr<20)
  {
    nr_days=nr_days+1;
    p=1-0.75^(20-nr);
    c=rbinom(1,nr,p);
    nr=nr-c+5;
  }
  return (nr);
}

MC_toateconturile=function(N)
{
  sum=0;
  for(i in 1:N)
  {
    if(conturi()>=20)
      sum=sum+1;
  }
  return (sum/N);
}

estimated_error_probability=function(p,pr,epsilon)
{
  alfa=1-pr;
  z=qnorm(alfa/2);
  N_min=(1-p)*p*(z/epsilon)^2;
  print(N_min);
}