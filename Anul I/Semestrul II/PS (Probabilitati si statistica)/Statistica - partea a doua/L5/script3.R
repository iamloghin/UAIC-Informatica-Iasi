zconfidence_interval <- function(niv_inc, medie_sel, esan, disp) {
  alfa = niv_inc
  selection_mean = medie_sel
  n = esan
  sigma = sqrt(disp)
  critical_z = qnorm(1-alfa/2, mean = 0, sd = 1)
  a = selection_mean - critical_z * sigma / sqrt(n)
  b = selection_mean + critical_z * sigma / sqrt(n)
  interval = c(a,b)
  interval
}