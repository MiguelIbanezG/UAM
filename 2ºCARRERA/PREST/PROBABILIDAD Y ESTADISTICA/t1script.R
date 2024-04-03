# Define a working directory

###########
# Page 14 #
###########
# Text file called "Machine.dat" with Tabs as field separator and
# points as decimal-point character
Machine<-read.table("Machine.dat", header=TRUE, sep="\t", na.strings
                    ="NA", dec=".", strip.white=TRUE)
# Text file called "msoftware.txt" with commas as decimal-point
# character and space as field separator
msoftware<-read.table("msoftware.txt",header=TRUE, sep=" ",
                      na.strings="NA", dec=",", strip.white=TRUE)
# Text file called "transistor.txt" with commas as decimal-point
# character and Tabs as field separator
transistor<-read.table("transistor.txt",header=TRUE, sep="\t",
                       na.strings="NA", dec=",", strip.white=TRUE)
# Text file called "cpus.dat" with dots as decimal-point characters
# and tab as field separator
CPU<-read.table("cpus.dat",header=TRUE, sep="\t", na.strings="NA",
                dec=".", strip.white=TRUE)
###########
# Page 16 #
###########
install.packages("foreign")
library(foreign)
Fibre <- read.spss("fibre.sav", rownames=FALSE,stringsAsFactors=TRUE
                   , tolower=FALSE)
###########
# Page 24 #
###########
# Calcular frequencias absolutas, relativas y porcentuales
absfreq1 <- table(msoftware$virus)
relfreq1 <- absfreq1 / sum(absfreq1)
percfreq1 <- relfreq1 * 100
cbind(absfreq1, relfreq1, percfreq1)
table(Fibre$machine)
###########
# Page 25 #
###########
pie(table(Fibre$machine))
pie(table(msoftware$virus))
###########
# Page 26 #
###########
barplot(table(msoftware$virus),cex.names=0.65)
###########
# Page 30 #
###########
absfreq<-c(3,11,9,20,5,2)
relfreq<-absfreq/sum(absfreq)
cumabsfreq<-cumsum(absfreq)
cumrelfreq<-cumsum(relfreq)
t<-round(cbind(absfreq,relfreq,cumabsfreq,cumrelfreq),4)
nans<-0:5
tfreq<-cbind(nans,t)
barplot(absfreq,xlab="Number correct answers",names.arg=nans,ylab="
Absolute frequency")
###########
# Page 32 #
###########
hist(CPU$eff,freq=FALSE,xlab="CPU efficiency",main="")
hist(log(CPU$eff),freq=FALSE,xlab="log(CPU efficiency)",main="")
###########
# Page 37 #
###########
h<-hist(log(CPU$eff),freq=FALSE,xlab="log(CPU efficiency)",main="")
h$breaks # Vector giving the breakpoints between histogram cells
layout(matrix(1:3,1,3))
# 1st histogram: default number of bins
hist(log(CPU$eff),freq=FALSE,xlab="log(CPU efficiency)",main="")
# 2nd histogram: with a greater number of bins
hist(log(CPU$eff),breaks=seq(1.5,7.5,by=0.25),freq=FALSE,xlab="log(
CPU efficiency)",main="")
# 3rd histogram: with less bins
hist(log(CPU$eff),breaks=seq(1.5,7.75,by=1.25),freq=FALSE,xlab="log(
CPU efficiency)",main="")
layout(matrix(1))
###########
# Page 44 #
###########
nans<-0:5
absfreq2<-c(3,11,9,20,5,2)
numer2<-sum(absfreq2*nans)
denom2<-sum(absfreq2)
numer2/denom2
# Sample median
s2<-sort(rep(nans,absfreq2))
n2<-length(s2)
mean(c(s2[n2/2],s2[n2/2+1]))
median(s2)
###########
# Page 56 #
###########
# Range
range(CPU$eff)
range(CPU$eff)[2]-range(CPU$eff)[1]
# Quasi-variance
var(CPU$eff)
# Quasi-standard deviation
sd(CPU$eff)
# Sample size
n4<-length(CPU$eff)
# Variance
(n4-1)/n4*var(CPU$eff)
# Standard deviation
sqrt((n4-1)/n4)*sd(CPU$eff)
###########
# Page 57 #
###########
sd(CPU$eff)/abs(mean(CPU$eff))
###########
# Page 63 #
###########
# Quartiles
quantile(CPU$eff, probs = seq(0, 1, by=0.25))
# 35th percentile
quantile(CPU$eff, probs = 0.35)
# Quantile of order 0.125
quantile(CPU$eff, probs = 0.125)
###########
# Page 66 #
###########
boxplot(CPU$eff)
###########
# Page 68 #
###########
par(mfrow = c(1, 2))
boxplot(CPU$eff,main="CPU efficiency")
boxplot(log(CPU$eff),main="log(CPU efficiency)")
layout(1)
###########
# Page 80 #
###########
x9 = transistor$x
y9 = transistor$y
plot(x9,y9,xlab="voltaje de tierra a fuente",ylab="coriente de
drenaje",pch =16)
###########
# Page 83 #
###########
# install.packages("car") # Only need to install it once
library(car)
scatterplot(resistance~diameter | machine, regLine=FALSE, smooth=
              FALSE, boxplots=FALSE, by.groups=TRUE, data=Fibre,
            xlab=" Diameter", ylab="Resistance", pch=c(16,16,16))
###########
# Page 84 #
###########
scatterplotMatrix(~eff+x1+x2+x3, regLine=FALSE, smooth=FALSE,
                  diagonal=list(method="histogram"), data=CPU)
scatterplotMatrix(~log(CPU$eff)+log(CPU$x1)+log(CPU$x2)+log(CPU$x3),
                  regLine=FALSE, smooth=FALSE, diagonal=list(method=
                                                               "histogram"))
###########
# Page 90 #
###########
x9 = transistor$x
y9 = transistor$y
# Sample quasi-covariance
cov(x9,y9)
n9<-length(x9)
sum((x9-mean(x9))*(y9-mean(y9)))/(n9-1)
# Sample covariance
(n9-1)/n9*cov(x9,y9)
sum((x9-mean(x9))*(y9-mean(y9)))/n9
# Correlation coefficient
cor(x9,y9)
cov(x9,y9)/(sd(x9)*sd(y9))
############
# Page 102 #
############
RegModel.9<-lm(y9~x9)
RegModel.9<-lm(y~x,data=transistor) #Alternative
summary(RegModel.9)
############
# Page 103 #
############
scatterplot(y9~x9, regLine=TRUE, smooth=FALSE, boxplots=FALSE,
            pch=16, xlab="ground-to-source voltage", ylab="drain current")
scatterplot(y~x, regLine=TRUE, smooth=FALSE, boxplots=FALSE, pch=16,
            xlab="ground-to-source voltage", ylab="drain current", data=
              transistor)
############
# Page 113 #
############
library(RcmdrMisc)
numSummary(Machine[,"resist", drop=FALSE], groups=Machine$machine,
           statistics=c("mean","sd","IQR","quantiles","cv"),
           quantiles=c
           (0,.25,.5,.75,1))
# Plotting three histograms in the same window
layout(matrix(1:3,1,3))
hist(Machine$resist[Machine$machine=="A"],freq=FALSE,xlab="Machine A",main="")
hist(Machine$resist[Machine$machine=="B"],freq=FALSE,xlab="Machine B",main="")
hist(Machine$resist[Machine$machine=="C"],freq=FALSE,xlab="Machine C",main="")
layout(matrix(1))
############
# Page 115 #
############
# Plotting three box-plots in the same graph
boxplot(resist~machine, data=Machine, ylab="Resistance",xlab="Machine")
# Plot of means
with(Machine, plotMeans(resist, machine, error.bars="se",
                        connect= TRUE,ylab="Resistance mean",xlab="Machine"))
