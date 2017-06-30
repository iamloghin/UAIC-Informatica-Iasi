# E1
t_test=function(esantion,miu0,alfa)
{
  n=length(esantion);
  sample_mean=mean(esantion);
  s=sd(esantion);
  se=s/sqrt(n);
  critical_t=qt(alfa,n-1);
  t_score=(sample_mean-miu0)/se;
  print(critical_t);
  print(t_score);
}

t_test(c(1.64,1.54,1.56,1.57,1.44,1.48,1.56),1.6,0.01)

# E4
z_test_means=function(n1,n2,sample_mean1,sample_mean2,sigma1,sigma2,alfa,miu0)
{
  combined_sigma=sqrt(sigma1^2/n1+sigma2^2/n2);
  critical_z=qnorm(1-alfa/2);
  z_score=(sample_mean1-sample_mean2-miu0)/combined_sigma;
  print(critical_z);
  print(z_score);
}

z_test_means(155,150,15,14.5,0.75,0.78,0.01,0)
z_test_means(155,150,15,14.5,0.75,0.78,0.05,0)

# E5
T_test_means=function(n1,n2,sample1_mean,sample2_mean,s1,s2,alfa,m0)
{
  critical_F_s=qf(alfa/2,n1-1,n2-1);
  critical_F_d=qf(1-alfa/2,n1-1,n2-1);
  F_score=s1^2/s2^2;
  if(F_score<critical_F_s|F_score>critical_F_d)
  {
    df=min(n1-1,n2-1);
    combined_s=sqrt(s1^2/n1+s2^2/n2);
  }
  else
  {
    df=n1+n2-2;
    combined_s=sqrt(((n1-1)*s1^2+(n2-1)*s2^2)/df)*sqrt(1/n1+1/n2);
  }
  critical_t=qt(1-alfa/2,df);
  t_score=(sample1_mean-sample2_mean-m0)/combined_s;
  print(critical_t);
  print(t_score);
}

T_test_means(66,68,21,20,1.2,1.1,0.05,0)
