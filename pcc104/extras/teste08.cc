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
  // Parâmetros
  int N;
  cout << "Digite o número de elementos do vetor X: ";
  cin >> N;
  cout << endl;

  // Variáveis
  int X[N];  // Variável pra armazenar um vetor de inteiros
  int *P;    // Ponteiros para apontar pra X

  // Entrada de dados
  for (int i=0; i<N; ++i){
    cout << "Digite o " << i+1 << "° valor inteiro de X: ";
    cin >> X[i];
  }
  cout << "Pronto!\n\n";

  // Apontando para X e Y
  P = &X[0];

  // Resultado
  for (int i=0; i<N; ++i){
    cout << "Endereço do " << i+1 << "° de X: " << P << endl;
    cout << "Valor de X[" << i+1 << "]= " << *P << endl;
    cout << "Conferindo: X[" << i+1 << "] = " << X[i] << endl;
	P++;
  }
  
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste08.cc -o saida
