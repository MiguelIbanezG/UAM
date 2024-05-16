#muestras de datos
den <- c(5.50, 5.61, 4.88, 5.07, 5.26, 5.55, 5.36, 5.29, 5.58, 5.65, 5.57, 5.53, 5.62, 5.29, 5.44, 5.34, 5.79, 5.10, 5.27, 5.39, 5.42, 5.47, 5.63, 5.34, 5.46, 5.30, 5.75, 5.68, 5.85)

#Calcular la media
mean(den)

#Calcular la mediana
median(den)

#Hallar el mínimio
min(den) 

#Hallar máximo
max(den)

#Rango
rango_den <- max(den) - min(den)

#Quartiles
quantile(den, probs = seq(0, 1, by=0.25))
Q1=5.30
Q3=5.61
Q3-Q1

#Rango interquartil
RI_den <- Q3 - Q1

