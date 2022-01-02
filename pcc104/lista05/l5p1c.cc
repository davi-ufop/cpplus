// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema do número de Fibonacci com programação dinâmica
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Nov./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <vector>      // Vector pra armazenar dados

// Prefixos -> Namespaces
using namespace std;

// Variável Global - Contador de operações
int C = 0;

// Classe para números de Fibonacci
class numFibo{  // Construção + elegante e assim + eficiente
  public:
  // Método usando programação dinâmica - Divide->Tabela->Solução
  int fibo(int n){
    vector<int> VN(n+2);   // Vetor(tabela) pra armazenar 
    VN[0] = 0;             // Resultados Parciais (divide)
    VN[1] = 1;             // Como estas condições iniciais 0 e 1
		// Armazenando as partes que associadas geram a solução final
		for (int i=2; i<=n; ++i){
      C++;    // Contando a Operação Básica a seguir:
      VN[i] = VN[i-2] + VN[i-1];  // Fórmula recursiva
		}
    return VN[n];  // Solução Final
  }
};

// Função Principal
int main(){
  // Variáveis do processo
  numFibo fn;
	int N, FN;
	// Entrada do dado - Tamanho da instância
	cout << "Digite o valor (natural) de N: ";
	cin >> N;
	// Cálculo do N-ésimo número de Fibonacci
	FN = fn.fibo(N);
	// Resultados
	cout << "O " << N+1 << "° número de Fibonacci = " << FN << endl;
  cout << "Foram realizadas " << C << " operações.\n";
	// Pronto!
  return 0;
}
// **************************************************************** //
// FIM
// Para compilar: g++ prog.cc -o saida
