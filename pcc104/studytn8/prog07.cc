/********************************************************************/
// Programa para trocar o valor de duas variáves: A <-> B. Sem 3ª
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO & DECOM
/********************************************************************/
// Bibliotecas
#include <iostream>   // Biblioteca para realizar in e out

// Prefixos
using namespace std;

// Função principal
int main(){
  // Variáveis
  double A, B;

  // Entrada dos valores
  cout << "Digite o valor de A: ";
  cin >> A;
  cout << "Digite o valor de B: ";
  cin >> B;

  // Trocando os valores
  cout << "Trocando os valores..." << endl;
  A = A*B;  // Exemplo: (A)5 * (B)4 = 20
  B = A/B;  // B = 20/4 = 5(A anterior)
  A = A/B;  // A = 20/5 = 4(B anterior)

  // Resposta
  cout << "Depois da troca:\n A = " << A << "\n B = " << B << endl;
  
  return 0;
}
/********************************************************************/
// FIM - Pra compilar, vide prog01.cc
