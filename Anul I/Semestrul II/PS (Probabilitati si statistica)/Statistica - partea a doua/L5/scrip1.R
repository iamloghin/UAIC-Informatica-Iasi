normal_rule_density <- function(limit, micro, sigma) {
  t = seq(-limit, limit, length = 400)
  f =(1/(sigma/2)*sqrt(2*pi))*exp(-(t-micro)^2/(2*sigma))
  plot(t, f, type = "l", lwd = 1)
}

normal_rule_density(6, 0, 1) 