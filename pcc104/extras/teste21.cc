/********************************************************************/
// Programa para calcular o N-ésimo N° de Fibonacci Recursivamente
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM DEPRO
/********************************************************************/
// Bibliotecas
#include <iostream>

using namespace std;
  
// Método para calcular o número de Fibonacci Recursivamente
int numFibo(long int K){
  if ( K == 1 or K == 2 ){
    return 1;         // Condição para os dois primeiros N°s
  } else {
    return numFibo(K-1) + numFibo(K-2);	 // Fórmula recursiva
  } 
}

int main(){
  // Parâmetros e variaveis  
  long int N, F;

  // Entrada de dados
  cout << "Determine o índice do N° de Fibonacci: ";
  cin >> N;

  // Cálculo do número de Fibonacci Recursivamente
  F = numFibo(N);

  // Resposta - N-ésimo número de Fibonacci
  cout << "O " << N << "° número de Fibonacci = " << F << endl;

  return 0;
}
/********************************************************************/
// FIM - Para compilar digite: g++ teste21.cc -o saida
