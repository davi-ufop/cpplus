/********************************************************************/
// Programa para calcular o fatorial de um número arbitrário
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO & DECOM
/********************************************************************/
// Bibliotecas
#include <iostream>   // Biblioteca para realizar in e out

// Prefixos
using namespace std;

// Método pra calcular o valor fatorial
int CalcFat(int M){
  int R=1; // Fatorial de 1
  for (int m=2; m<=M; ++m)  // Loop até M
    R *= m;  // Produtório -> Operação realizada M vezes
  return R;  // Fatorial   
}

// Função principal
int main(){
  // Variável
  int N;

  // Entrada do dado
  cout << "Digite um número natural: ";
  cin >> N;

  // Calculando o fatorial de N
  int F = CalcFat(N);

  // Resposta
  cout << "O valor fatorial de " << N << " = " << F << endl;

 return 0;
}
/********************************************************************/
// Observe que a operação fatorial apresenta complexidade O(N)
/********************************************************************/
// FIM - Pra compilar, vide prog01.cc
