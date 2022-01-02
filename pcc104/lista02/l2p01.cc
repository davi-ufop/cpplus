// **************************************************************** //
// Programa elaborado para implementar o Algoritmo Bubble Sort 
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>     // Entrada/Saídas 
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

		// Realizando a ordenação por bolha - Algoritmo BubbleSort
		for (int i=0; i<(N-1); i++){          // Varredura de
				for (int j=0; j<(N-1); j++){  // Ordenação
						if (A[j+1] < A[j]){   // Compara para a troca
								double S = A[j];  // Salvando valor de troca
								A[j] = A[j+1];    // Primeira troca
								A[j+1] = S;       // Segunda troca
						}
				}
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
