// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema do troco (change-making) com programação dinâmica
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

// Denominações das nossas moedas
const vector<int> D = {1, 5, 10, 25, 50, 100};
// Quantidade de denominações: 6 -> {1,5,10,25,50,100}
const int QD = D.size();

// Método para determinar o número (a quantidade)
// mínimo (mínima) de moedas para um troco de valor V
int QM(int V){
  // Vetor para armazenar os dados -> Programação Dinâmica
  vector<int> F;
  // Inserindo o primeiro valor: F[0]=0  
	F.push_back(0);
	// Construção dos dados usando a recorrência - Vide Anany
	for (int i=1; i<=V; ++i) {
    int Temp = V*10;    // Valor temporário, para a contagem
    int j = 0;          // Índice pra denominação das moedas
	  while (j < QD and i >= D[j]){  // Varredura de contagem
	    // Fórmula de recorrência - Vide Anany -> Operação Básica:
      (F[i-D[j]] < Temp) ? Temp=F[i-D[j]] : Temp=Temp; 
			C++;  // Contando as operações básicas
		  j++;  // Próximo passo d a contagem
	  }
		F[i] = Temp + 1; // Atribuição ao valor adjacente
		//cout << "F[" << i << "] = " << F[i] << endl;
	}
	return F[V];  // Resposta -> Quantidade de moedas pra totalizar V
}

// Função Principal
int main(){
  // Variável do processo
  int VT;
  // Entrada de dados
  cout << "Digite o valor (em centavos) do troco: ";
	cin >> VT;
	// Determinando a resposta -> Resultado, vide acima!
  int RS = QM(VT);
	// Resultado:
  cout << "Pra pagarmos " << VT << " centavos de troco,\n";
  cout << "usaremos " << RS << " moedas!\n";
	cout << "Este algoritmo usou " << C << " operações básicas!\n";
	// Pronto!
  return 0;
}
// **************************************************************** //
// FIM
// Para compilar: g++ prog.cc -o saida
