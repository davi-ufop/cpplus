// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema do número de Fibonacci sem programação dinâmica
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Nov./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas

// Prefixos -> Namespaces
using namespace std;

// Variável Global
int C = 0;   // Contador de operações

// Método para relação recursiva
int fibo(int n){
  if (n > 1){   // Fórmula recursiva
		C++;        // Contando cada operação
    return fibo(n-2) + fibo(n-1);  // Operação básica
	} else {      // Resultado para n = 0 ou 1
		return n;
	}
}

// Função Principal
int main(){
  // Variável de entrada - Tamanho da instância
  int N;
	// Entrada do dado, arbitrário
  cout << "Digite o valor (natural) de N: ";
	cin >> N;
	// Cálculo do N-ésimo número de Fibonacci
	int FN = fibo(N);
	// Resultados
	cout << "O " << N+1 << "° número de Fibonacci = " << FN << endl;
	cout << "Foram realizadas " << C << " operações.\n";
	// Pronto!
  return 0;
}
// **************************************************************** //
// FIM
// Para compilar: g++ prog.cc -o saida
