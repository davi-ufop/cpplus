// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo SequentialSearch 
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <locale>    // Gramática Local
#include <time.h>    // Tempo/Datas

// Prefixos -> Namespaces
using namespace std;

// Função principal
int main(){
        // Acentos e caracteres especiais
        setlocale(LC_ALL, "portuguese");

        // Parâmetros e variáveis
		srand(time(0));  // Semente randômica 
		int N=15;        // Tamanho da instância
		int A[N];        // Array de entrada A
        int L=150;       // Denominador para geração de A = [0, L]
		int K;           // Valor chave de busca (K -> key)
		int vi;          // Valor do índice de busca

		// Apresentando o array de entrada
		cout << "\nInstância de entrada:\n( ";
		for (int i=0; i<N; i++){          // Valores aleatórios
				A[i] = rand()%L;          // Definindo: Ai -> [0, L]
				cout << A[i] << ", ";     // Apresentando
		}
		cout << " )" << endl;
     
		// Definindo o valor de busca - CHAVE:
		cout << "\nDigite o valor da chave: K = ";
        cin >> K;

		// Adicionando a chave como último termo do array
		A[N] = K;

		// Pesquisando pelo primeiro termo de A 
		// que é igual a K  - Algoritmo SequentialSearch2
		int i = 0;   // Índice de busca
        while (A[i] != K){   // Pesquisando o termo chave
				i += 1;      // Enquanto for diferente, some
		}	
	    if (i < N){  // Se tiver encontrado
			vi = i;  // vi recebe o valor do índice -> A[i]=K
		} else {     // Se não tiver encontrado
			vi = N;  // DIFERENTE DO LIVRO - vide resultado
		}

		// Apresentando o resultado - CONFORME O QUE FOI ELABORADO
		cout << "Índice do termo igual a chave = " << vi << ".\n";
		cout << "Então temos que:\nA[" << vi << "] = " << A[vi] << endl;
		cout << "Conforme definimos anteriormente:\nK = " << K << endl;
        
		return 0;
}//FIM
// Para compilar: g++ prog.cc -o saida
