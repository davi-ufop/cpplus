// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema da coleta de moedas sem programação dinâmica
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Nov./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <vector>      // Vector pra armazenar dados
#include <ctime>       // Tempo para semente randômica

// Prefixos -> Namespaces
using namespace std;

// Variável Global - Contador de operações
int C = 0;

// Determina o valor máximo de uma dupla de inteiros
int maxValor(int A, int B){
  if (A > B){   // Comparação entre A e B
    return A;   // Retorno para TRUE
  } else {     
    return B;   // Retorno para FALSE
  }
}  // Há formas de otimizar isso, use o operador ?

// Método para executar a fórmula de recorrência usando 
// como entrada a quantidade n de moedas seus valores
int somaMoedas(int n, vector<int> M){  
  if (n>1) {  // Se tivermos duas ou mais moedas -> Recorrência:
      C++;    // Contando a operação básica a seguir. 
      return maxValor(somaMoedas(n-2, M)+M[n-1], somaMoedas(n-1, M));
	} else if (n == 1){ // Se tivermos apenas uma moeda (n=1):
	  return M[0];      // Retorne o valor dela
	} else {            // Se não tivermos nenhuma moeda (n=0):
    return 0;         // Retorne o valor NULO
	}
}

// Função Principal
int main(){
  // Semente randômica
  srand(time(0));
  // Variáveis e parâmetros do processo
	// vector<int> Moedas = {5, 1, 2, 10, 6, 2};   // Instância do livro
  vector<int> Moedas;
	int N, S;
  // Tamanho da instância - Número de moedas
  cout << "Digite o número de moedas: ";
  cin >> N;
  // Gerando as moedas aleatórias:
  for (int i=0; i<N; ++i){
	  Moedas.push_back(1 + rand()%30);  // Randomizado
	}
  // Apresentando as moedas
  cout << "Moedas = (";
  for (int i=0; i<N-1; ++i){
    cout << Moedas[i] << " ";
  }
	cout << Moedas[N-1] << ")\n";
	// Determinando a soma máxima das moedas coletadas
	S = somaMoedas(N, Moedas);
	// Resultados
	cout << "Valor máximo coletado = " << S << endl;
	cout << "Número de operações básicas = " << C << endl;
  // Pronto!
  return 0;
}
// **************************************************************** //
// FIM
// Para compilar: g++ prog.cc -o saida
