/********************************************************************/
// Programa para demonstrar a utilização de ponteiros *P: P -> &X
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM && DEPRO
/********************************************************************/
// Biblioteca
#include <iostream>

// Prefixos
using namespace std;

// Função principal
int main(){
  int X;    // Variável para armazenar inteiro
  int *P;   // Ponteiros para apontar pra X

  // Entrada de dados
  cout << "Digite o valor inteiro de X: ";
  cin >> X;

  // Apontando para X e Y
  P = &X;

  // Primeiro resultado
  cout << "Endereço de X: " << P << endl;
  cout << "Valor de X: " << *P << endl;
  cout << "Conferindo: X = " << X << endl;
  
  // Alterando o valor de X
  cout << "\nApontando X para o valor 8\n";
  *P = 8;
  
  // Segundo resultado
  cout << "Novo endereço de X: " << P << endl;
  cout << "Novo valor de X: " << *P << endl;
  cout << "Conferindo: X = " << X << endl;

  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste07.cc -o saida
