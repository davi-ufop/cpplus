/********************************************************************/
// Programa para determinar se um número é positivo ou negativo.
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO & DECOM
/********************************************************************/
// Bibliotecas
#include <iostream>   // Biblioteca para realizar in e out

// Prefixos
using namespace std;

// Função para determinar se um número é positivo (true)
template <typename tipo>   // Generalização
bool PosNeg( tipo N ){     // Argumento da função
  return (N > 0) ? true: false;   // Análise -> O(1)
}

// Função principal
int main(){
  // Variável para armazenar o dado
  int P;      // Número inteiro
  double Q;   // Número real
  
  // Entrada do número
  cout << "Digite um número inteiro não nulo: ";
  cin >> P;
  cout << "Digite um número real não nulo: ";
  cin >> Q;
  
  // Analisando o sinal dos números P e Q
  bool R = PosNeg(P);
  bool S = PosNeg(Q);

  cout << "\n\tRespostas:\n";
  // Resposta ajustada
  if (R == 1){ // Se R for true: 1 -> false: 0
    cout << "O número inteiro digitado é positivo!\n";
  } else {
    cout << "O número inteiro digitado é negativo!\n";
  }
  if (S == 1){ // Se S for true: 1 -> false: 0
    cout << "O número real digitado é positivo!\n";
  } else {
    cout << "O número real digitado é negativo!\n";
  }

  return 0;
}
// FIM -> Para compilar: g++ prog.cc -o saida
