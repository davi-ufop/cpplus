// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo BFStringMatch 
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
		int N=150;       // Tamanho da instância - Tamanho do DNA
		int M=6;         // Tamanho do gene que vamos procurar
        int L=4;         // Quantidade de letras no alfabeto -> DNA = 4
		char C[L] = {'A','T','C','G'}; // Adenina, Timina, Citosina e Guanina
		char T[N];       // Array de entrada - código do DNA selecionado 
		char G[M];       // Chave de busca -> Gene com M bases nucleicas
		int vi;          // Valor do índice de busca

		// Apresentando o array de entrada - Código do DNA
		cout << "\nInstância de entrada - DNA:\n";
		for (int i=0; i<N; i++){          // Valores aleatórios
				int k = rand()%L;         // Definindo k de C{L}
				T[i] = C[k];              // Selecionando as bases {A,T,C,G}
		}
		cout << T << endl;
     
		// Definindo o valor de busca - CHAVE (GENE):
		cout << "\nDigite as " << M << " bases {ATCG} do Gene:\n";
        cin >> G;     // Digite M letras maísculas -> {A, T, C, G}
		cout << "\n.:. G = " << G << endl;  // Conferindo

		// Buscando a primeira ocorrencia do GENE no código do DNA
		for (int i=0; i<(N-(M-1)); i++){  // Varrendo todo o código DNA
				int j = 0;                // Índice do GENE
				// Comparando o GENE com partes do DNA
				while (j < M && G[j] == T[i+j]){ // Cada parte igual
						j += 1;           // remete a esta soma
				}
				if (j == M){    // Se a soma for M, para tudo!!!
						vi = i;  // Encontramos a base i do nosso GENE
						break;   // PRONTO!
				} else {         // Se não, a busca não obteve exito
						vi = -1; // Valor do fracasso!
				}
		}
		
		// Apresentando o resultado ... LEIAME!
		if (vi == -1){
				cout << "\nNão encontramos o GENE neste DNA!\n";
		} else {
				cout << "\nEncontramos nosso GENE neste DNA!\n";
				cout << "A primeira ocorrência foi na base " << vi+1 << endl;
				cout << ".:. DNA[" << vi+1 << "]:\t";
				for (int k=vi; k<(vi+M); k++){ cout << T[k]; }
				cout << "\nLembrando que o nosso GENE = " << G << endl;
		}	

		return 0;
}//FIM
// Para compilar: g++ prog.cc -o saida
