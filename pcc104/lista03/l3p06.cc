// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema de interpolação - Não é bem a busca proposta!
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Set./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <locale>    // Gramática Local
#include <cmath>     // Funções matemáticas

// Prefixos -> Namespaces
using namespace std;

// Variáveis e parâmetros globais
double LQ[10] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
double LR[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Busca do limite superior
double BuscaSup( double K );

// Busca do limite inferior
double BuscaInf( double K );

// Busca o valor de base
double BuscaBase( double K );

// Calculo da Raiz Quadrada
double Raiz(double b, double q, double u, double d);

// Função principal
int main() {
  // Acentos e caracteres especiais
  setlocale(LC_ALL, "portuguese");
  // Variáveis e parâmetros úteis 
  double R, B, Q, U, D;
  // Entrada de dado:
  cout << "Digite um número inteiro < 100:" << endl;
  cin >> Q;
  // Busca dos limites para interpolação
  U = BuscaSup(Q);
  cout << "Limite Superior = " << U << endl;
  D = BuscaInf(Q);
  cout << "Limite Inferior = " << D << endl;
  // Buscando o valor Base
  B = BuscaBase(Q);
  // Calcula da Raiz
  R = Raiz(B, Q, U, D);
  // Resultado
  cout << "Raiz aprox. de " << Q << " = " << R << endl; 
  cout << "Raiz exata de " << Q << " = " << sqrt(Q) << endl; 
  // Erro do Cálculo
  cout << "Erro = " << 100*abs((R-sqrt(Q))/sqrt(Q)) << " %" << endl;
  // Pronto!
  return 0;
}

// Busca do limite superior
double BuscaSup( double K ){
  int c = 0;
  while ( K > LQ[c] ){ c++; }
  return LQ[c];
}

// Busca do limite inferior
double BuscaInf( double K ){
  int c = sizeof(LQ)/sizeof(LQ[0]) - 1;
  while ( K < LQ[c] ){ c--; }
  return LQ[c];
}

// Busca do valor Base
double BuscaBase( double K ){
  int c = sizeof(LQ)/sizeof(LQ[0]) - 1;
  while ( K < LQ[c] ){ c--; }
  return LR[c];
}

// Cálculo da Raiz Quadrada
double Raiz(double b, double q, double u, double d){
  double r;
  r = b + (q-d)/(u-d);
  return r;
}
//FIM
// Para compilar: g++ prog.cc -o saida
