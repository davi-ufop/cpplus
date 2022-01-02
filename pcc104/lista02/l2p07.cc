// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema do Caixeiro Viajante -> 7 cidades
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <fstream>   // Arquivo externo
#include <locale>    // Gramática Local
#include <time.h>    // Tempo/Datas
#include <cmath>     // Matemática
#include <vector>    // Para usar a classe vector
#include <algorithm> // Para permutação

// Prefixos -> Namespaces
using namespace std;

// Variáveis globais
vector<double> x, y;     // Vetores pra coordenadas e parâmetros
int N=7;                 // Tamanho da instância - Número de cidades

// Função para gerar vetores - Coordenadas da cidades
vector<double> gerVec(double dt);

// Função para apresentar coordenadas de vetores
double showPos();

// Função para determinar distâncias entre cidades p e q
double distCit(int p, int q);

// Função para determinar a próxima cidade mais próxima
vector<int> citRota(); 

// Função para salvar dados em CSV
int saveCSV(vector<int> LR);

// Função principal
int main(){
    // Truncamento dos valores double em cout
    cout.precision(2);	
    // Acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    // Variável do problema:
    vector<int> RC;          // Vetor para registrar a rota mais curta

    // Gerando os pontos no plano cartesiano
    x = gerVec(2.71);    // Coordenadas x dos n pontos no plano
    y = gerVec(3.14);    // Coordenadas y dos n pontos no plano

    // Apresentando o array de entrada - Pontos no Plano Cartesiano [0, L]
	showPos();
    
    // Determinando a rota mais curta
    RC = citRota();

    // Apresentando o resultado
    cout << "ROTA MAIS CURTA:\n";
    for (int cr: RC){ cout << cr << " -> "; }
	cout << "Circuito de Hamilton" << endl;
    
    // Salvando em CSV
    saveCSV(RC);

    return 0;
}

// Função para gerar vetores
vector<double> gerVec(double dt){
    srand(time(NULL)+dt);  // Semente randômica 
	int D=230;         // Denominador para limitar valores
	double L=97.5/D;   // Limite dos valores -> [0, L]
    vector<double> X;  // Vetor para armazenar os N valores
    //X.push_back(0);    // Primeiro termo -> (0,0) origem
    for (int i=0; i<N; i++){X.push_back(L*(rand()%D));} // Geração - O(N)
    return X;
}

// Função para apresentar posições dos pontos 
double showPos(){
   // Apresentando o array de entrada - Pontos no Plano Cartesiano [0, L]
   cout << "\nCoordenadas das Cidades:\n";
   for (int i=0; i<N; i++){  // Varredura por todos os n pontos           
       cout << "(" << x[i] << "," << y[i] << ") "; // Escrita - O(N)
       }
   cout << "\n" << endl;
   return 0;
}

// Função para determinar a distância entre as cidades m e n
double distCit(int p, int q){
    double R;   // Valor da Reta entre m e n
    double dx = x[p]-x[q]; 
    double dy = y[p]-y[q];
    R = hypot(dx, dy);  // hypot(x,y) = sqrt(x² + y²)
    return R;
}

// Função para determinar a rota mais curta
vector<int> citRota(){   // O(N!)
    // Parâmetros respectivos ao problema
    int ip, iq;              // Índices para as cidades p e q
    int N1 = N-1;            // Quantidade de cidades intermediárias
    int IC[N1];              // Array para armazenar os índices das cidades
    double DC, DK=INFINITY;  // Variáveis para as distâncias das cidades
	vector<int> LC;          // Vetor para a lista do caminho + curto
    // Construindo o vetor para os índices das cidades	
    for (int i=0; i<N1; i++){ IC[i] = (i+1); }
    // Realizando o embaralhamento dos índices
    sort (IC, IC+N1);  // O(N!)
    // Varrendo as permutações no conjunto das cidades
    do {
        //cout << IC[0] << ' ' << IC[1] << ' ' << IC[2] << '\n';  // N<4
        DC = distCit(0, IC[0]);         // Distância da cidade A -> B
        for (int k=0; k<(N1-1); k++){   // Cidades intermediárias
            ip = IC[k];                 // Cidade P
            iq = IC[k+1];               // Cidade Q
            DC = DC + distCit(ip, iq);  // Agregando a distância P -> Q
        }
        DC = DC + distCit(iq, 0);       // Agregando a última distância -> A
		//cout << "Distância = " << DC << endl;   // N<4
        if (DC < DK){      // Checando se o caminho da rota é menor que DK
            DK = DC;       // Novo DK, caso DC seja menor
			LC.clear();    // Limpando o vetor do caminho mais curto
            LC.push_back(0);   // Primeira cidade: A
            for (int j=0; j<N1; j++){ LC.push_back(IC[j]); } // Intermediárias
			LC.push_back(0);   // Última cidade: A
        } else {
            DK = DK;   // Se não for, deixa quieto
        }
    } while ( next_permutation(IC, IC+N1) );  // Final da varredura
    // A varredura por todas as permutações, até que a next seja a first 
	return LC; // Retorna a lista das cidades da rota mais curta
}	

// Função para salvar dados em CSV
int saveCSV(vector<int> LR){
    // Criando os arquivos
    ofstream f1, f2;
    // Construindo o primeiro arquivo
    f1.open("cidades.csv");
    f1 << "X,Y" << endl;
    for (int i=0; i<N; i++){
        f1 << x[i] << "," << y[i] << endl; // O(N)
    }
    f1.close();
    // Construindo o segundo arquivo
    f2.open("rotacurta.csv");
    f2 << "X,Y" << endl;
    for (int i: LR){
        f2 << x[i] << "," << y[i] << endl; // O(N)
    }
    f2.close();
    return 0;
}

//FIM
// Para compilar: g++ prog.cc -o saida
