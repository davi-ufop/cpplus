######################################################################
### Programa para plotar os resultados da questão 07 - lista 02
### Davi das Chagas Neves - UFOP/DECOM/PPGCC - Ouro Preto, 2021
######################################################################
### Importando biblioteca
library(ggplot2)
### Importando primeiros dados
df1 <- read.csv("cidades.csv")
### Ajustando dados
x1 <- df1$X
y1 <- df1$Y
N1 <- length(x1)
cits <- LETTERS[1:N1]
### Plotando as cidades
png("Cidades.png", width=780, heigh=640)
plot(x1, y1, pch=20, col='blue', main="Cidades", xlab="X", ylab="Y")
text(x1+1, y1+1, labels=cits)
dev.off()

### Importando os segundos dados
df2 <- read.csv("rotacurta.csv")
### Ajustando dados
x2 <- df2$X
y2 <- df2$Y
### Plotando a rota - tipo Uber
p2 <- qplot(x2, y2, xlab="X", ylab="Y", main="Rota Curta") + geom_step()
png("RotaCurta.png", width=780, heigh=640)
print(p2)
dev.off()
