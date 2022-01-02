// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema de busca por profundidade em um grafo
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <locale>      // Gramática Local
#include <time.h>      // Tempo/Datas
#include <vector>      // Vetores -> Vide ref. C++
#include <queue>       // Filas -> Vide ref. C++

// Prefixos -> Namespaces
using namespace std;

// Parâmetros e Variáveis globais
const int N=6;          // Tamanho da instância - Número de produtos
const int L=10;         // Parâmetro pra definir Limites randômicos 
int M[N][N];            // Matriz de adjacência

// Função para criar a matriz de adjacente
int makMat();

// Função para mostrar a matriz adjacente criada
int showMat();

// Função para realizar a busca por profundidade no Grafo
int buscaProfunda();

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
   
    // Busca por profundidade no Grafo definido por M
    buscaProfunda();

    // Conferindo M
    cout << "\nM de Zeros:" << endl;
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

// Função para realizar a busca por profundidade em todos os Nós
int buscaProfunda(){
    // Parâmetros e variáveis principais	
    int k=0;    // Índice para a coluna do nó
    int nv=1;   // Contador de nós visitados
	int gn[N]={};  // Lista para os graus dos Nós
	int nk[N]={};  // Lista para armazenar os Nós
    queue<int> kn; // Fila pra mostrar os Nós visitados
	queue<int> kc; // Fila pra gerir os Nós visitados
	// Primeiro nó visitado - Nó inicial
	kn.push(1);
    // Visitando os nós por profundidade
    cout << "\nInciando pelo nó 1\n";
    for (int m=0; m<N; ++m){ M[0][m]=0; }	
    while ( nv < N ) {   // Condição para varredura
        int ni=0;
        for (int i=1; i<N; ++i){  
            if (M[i][k] != 0){     
                for (int j=(N-1); j>-1; --j) { M[i][j] = 0; }
                nv += 1;  // Contando o Nó visitado
                kn.push(i+1);
                kc.push(i);
                cout << "Nó " << i+1 << endl;
				ni += 1;
            }
        }
		gn[k]=ni;
		k = kc.front();
        kc.pop();
    }
    
	for (int i=0; i<N; ++i){ 
        cout << kn.front() << " "; 
        nk[i]= kn.front();
        kn.pop();
    }
    cout << endl;
    for (int i=0; i<N; ++i) { cout << gn[i] << " "; }
	cout << endl;
    for (int i=0; i<N; ++i) { cout << nk[i] << " "; }
	cout << endl; 
   
	int cc=0;
    for (int i=0; i<N; ++i) { if (gn[i] == 0) { cc += 1; } }
	cout << "Número de ramos = " << cc << endl;

	int N1=N-1;
    int MR[cc][N+1];
  
	for (int i=0; i<cc; ++i){
        for (int j=0; j<=N; j++){
            MR[i][j] = 0;
		}
	}
    
	for (int i=0; i<cc; ++i) { 
			MR[i][0] = 1;
		    MR[i][N] = nk[N1-i];	
	}

	int grn;
    for (int l=1; l<N; l++){
        grn = gn[l];
		for (int i=0; i<grn; i++){
            MR[i][l] = l+1;
		}
	}

	cout << "\nResposta: \n";
	for (int i=0; i<cc; ++i){
        for (int j=0; j<=N; j++){
            cout << MR[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}

//FIM
// Para compilar: g++ prog.cc -o saida
