// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema de busca por largura em um grafo
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <locale>      // Gramática Local
#include <time.h>      // Tempo/Datas
#include <queue>       // Filas

// Prefixos -> Namespaces
using namespace std;

// Parâmetros e Variáveis globais
const int N=9;          // Tamanho da instância - Número de produtos
const int L=10;         // Parâmetro pra definir Limites randômicos 
int M[N][N];            // Matriz de adjacência

// Função para criar a matriz de adjacente
int makMat();

// Função para mostrar a matriz adjacente criada
int showMat();

// Função para realizar a busca por largura em todos os Nós
int buscaLargura();

// Função principal
int main(){
    // Truncamento dos valores em cout <<
    cout.precision(2);	
    // Acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");
	// Números Randômicos
	srand(unsigned(time(0)));

    // Criando a matriz de adjacência	
	makMat();
 
	// Mostrando a matriz criada
    cout << "\nMatriz Adjacente:\n" << endl;
    showMat();
   
    // Busca por largura no Grafo definido por M
    buscaLargura();

    // Conferindo M
    cout << "\nM esparsa:" << endl;
    showMat();

    return 0;
}

// Criando a matriz adjacente 
int makMat(){
    for (int i=0; i<N; ++i){
        for (int j=0; j<i; ++j){
            int R = rand()%2;
            M[i][j] = R;
            M[j][i] = R;
        }
    }
	for (int k=0; k<N; ++k){ M[k][k]=0; } 
    return 0;
}

// Função para mostrar a matriz adjacente
int showMat(){
	for (int i=0; i<N; ++i){
        cout << "| " ;
        for (int j=0; j<N; ++j){
            cout << M[i][j] << " ";
        }
		cout << "|" << endl;
    }
	cout << endl;
	return 0;
}

// Função para realizar a busca por largura em todos os Nós
int buscaLargura(){
    // Parâmetros e variáveis principais	
    int k=0;    // Índice para a coluna do nó
    int nv=1;   // Contador de nós visitados
    queue<int> kn; // Fila para armazenar os nós visitados
    // Visitando os nós por largura
    cout << "\nInciando pelo nó 1\n"; 
    while ( nv < N ) {   // Condição para varredura
        for (int i=1; i<N; ++i){  // Varredura da coluna k -> Vizinhos de k?
            if (M[i][k] != 0){    // Quando houver vértice: M[i,j]=1 
                cout << "Visitei o Nó " << i+1 << endl;   // Visite o Nó i
                for (int j=(N-1); j>0; --j) { M[i][j] = 0; } // Não visite +
                nv += 1;  // Contando o Nó visitado
                kn.push(i); // Fila de visitação
            } // Na L93 acima, zeramos a linha i referente ao Nó i vizinho de k  
        } // Agora atualizamos os parâmetros da busca
		k = kn.front(); // Nova coluna, referente ao Nó adjacente
		kn.pop();  // Retirando este Nó da fila 
        cout << "Agora no Nó " << k+1 << endl; // Indo para o respectivo Nó
    }
    return 0;
}

//FIM
// Para compilar: g++ prog.cc -o saida
