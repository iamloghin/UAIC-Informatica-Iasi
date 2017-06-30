# Stem and leaf (0.6 == 0 is stem & 6 is leaf || 13 == 1 is steam & 3 is leaf)

x = c(11,14,21,32,17,24,21,35,52,44,21,28,36,49,41,19,20,34,37,29)
stem(x)

# Histograme: hist() 

sample = scan("demo.txt")
min = min(sample)
max = max(sample)
min
max

interval = seq(0, 100, 1)
hist(sample, breaks = interval, right = F, freq = T)

a = 6
hist(sample, breaks = a, right = F, col = "green")

# Bar chart: barplot()

frecv = c(9, 8, 12, 3, 17, 41, 29, 35, 32, 40, 19, 8)
barplot(frecv, space = 0, col = "blue")

