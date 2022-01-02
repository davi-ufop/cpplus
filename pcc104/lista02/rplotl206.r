######################################################################
### Programa para plotar os resultados da questão 06 - lista 02
### Davi das Chagas Neves - UFOP/ DECOM/PPGCC - Ouro Preto, 2021
######################################################################
### Importando os dados
df1 <- read.csv("pontos.csv")
df2 <- read.csv("extremos.csv")
### Construindo os vetores
X <- df1$X
Y <- df1$Y
P <- df2$PE+1
### Definindo as cores
cores <- rep('blue',length(X))
for (i in P){
    cores[i] <- 'red'}
### Plotando os pontos com os extremos em vermelho
png(file="l2p06.png", width=780, height=780)
plot(X, Y, col=cores, pch=20, main="Pontos Extremos - Vermelhos")
dev.off()
######################################################################
