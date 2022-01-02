// **************************************************************** //
// Programa elaborado para implementar o Algoritmo Selection Sort 
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>     // Entradas/Saídas
#include <locale>       // Gramática Local
#include <time.h>       // Tempo/Datas

// Prefixos -> Namespaces
using namespace std;

// Função principal
int main(){
        // Acentos e caracteres especiais
        setlocale(LC_ALL, "portuguese");

        // Parâmetros e variáveis
		srand(time(0));  // Semente randômica 
		int N=15;        // Tamanho da instância
		double A[N];     // Array de entrada A
        int D=150;       // Denominador para geração de A
        double L=4.5;    // Limite para valores de A = [0, L] 

		// Apresentando o array de entrada
		cout << "\nInstância de entrada:\n( ";
		for (int i=0; i<N; i++){          // Valores aleatórios
				A[i] = (L/D)*(rand()%D);  // Definindo -> [0, L]
				cout << A[i] << ", ";     // Apresentando
		}
		cout << " )" << endl;

		// Realizando a ordenação por seleção - Algoritmo SelectionSort
		for (int i=0; i<(N-1); i++){  // Varredura sobre N-1 valores
				int min = i;          // Índice para o menor valor
				for (int j=(i+1); j<N; j++){ // Varredura nos adjacentes
						if (A[j] < A[min]){  // Pesquisando o menor valor 
								min = j;     // Índice do menor valor
						}
				}
			    double S = A[i];   // Salvando o valor de troca
			    A[i] = A[min];   // Realizando a troca
			    A[min] = S;      // que remete a ordenação
		}

		// Apresentando o vetor ordenado
		cout << "\nValores ordenados:\n( ";
		for (int i=0; i<N; i++){
				cout << A[i] << ", ";   // Resultado
		}
		cout << " )" << endl;

        return 0;
}//FIM
// Para compilar: g++ prog.cc -o saida
