// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo ConvexHull 
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <fstream>   // Arquivo externo
#include <locale>    // Gramática Local
#include <time.h>    // Tempo/Datas
#include <cmath>     // Matemática
#include <vector>    // Para usar a classe vector

// Prefixos -> Namespaces
using namespace std;

// Variáveis globais
vector<double> x, y;     // Vetores pra coordenadas e parâmetros
int N=15;                // Tamanho da instância - Número de pontos
double a, b, c;          // Parâmetros da equação da reta

// Função para gerar vetores
vector<double> gerVec(double dt);

// Função para apresentar coordenadas de vetores
double showPos();

// Função para checar posição de pontos
int cheCk();

// Função para determinar pontos extremos
vector<int> extPts(); 

// Função para salvar dados em CSV
int saveCSV(vector<int> ps);

// Função principal
int main(){
    // Truncamento dos valores double em cout
    cout.precision(2);	
    // Acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    // Variável para armazenar resposta
    vector<int> pts;

    // Gerando os pontos no plano cartesiano
    x = gerVec(2.71);    // Coordenadas x dos n pontos no plano
    y = gerVec(3.14);    // Coordenadas y dos n pontos no plano
		
    // Apresentando o array de entrada - Pontos no Plano Cartesiano [0, L]
	showPos();

    // Determinando os pontos extremos
    pts = extPts();
	int L = pts.size();  // Tamanho do vetor pts
	cout << "Número de pontos extremos = " << L << endl;

    // Apresentando a resposta
    for (int k=0; k<L; k++){
        cout << pts[k] << endl;
    }

    // Salvando em CSV
    saveCSV(pts);

    return 0;
}

// Função para gerar vetores
vector<double> gerVec(double dt){
    srand(time(NULL)+dt);  // Semente randômica 
	int D=230;         // Denominador para limitar valores
	double L=12.3/D;   // Limite dos valores -> [0, L]
    vector<double> X;  // Vetor para armazenar os N valores
    //X.push_back(0);    // Primeiro termo -> (0,0) origem
    for (int i=0; i<N; i++){X.push_back(L*(rand()%D));} // Geração - O(N)
    return X;
}

// Função para apresentar posições dos pontos 
double showPos(){
   // Apresentando o array de entrada - Pontos no Plano Cartesiano [0, L]
   cout << "\nPontos no Plano Cartesiano:\n";
   for (int i=0; i<N; i++){  // Varredura por todos os n pontos           
       cout << "(" << x[i] << "," << y[i] << ") "; // Escrita - O(N)
       }
   cout << "\n" << endl;
   return 0;
}

// Função para checar posição de pontos
int cheCk(){
    double R;   // Valor dado pela equação da reta -> R = a.x + b*y - c
    int K=0;    // Contador de pontos dentro da casca -> R <= 0
	for (int i=0; i<N; i++){
        R = a*x[i] + b*y[i] - c;  // Expressão - O(N)
        if (R <= 0){   // Análise - O(N)
            K += 1;    // Contagem - O(N)
        } else {
            K -= 1;
        }
    }
	return abs(K);
}

// Função para determinar pontos extremos
vector<int> extPts(){
    // Parâmetros e variáveis
    double x1, y1, x2, y2;  // Coordenadas selecionadas 
    int r, k2;  // Resposta da checagem e contagem de pontos
    vector<int> pontos; // Vetor para salvar pontos
    // Se os pontos forem extremos, teremos que:
    k2 = N-2;  // Há 2 pontos na linha? -> k2 = N-2
	// Varrendo todos os pontos - O(N²)
	for (int i=0; i<(N-1); i++){
        for (int j=i+1; j<N; j++){
            x1 = x[i];   // O ponto i 
            y1 = y[i];
            x2 = x[j];   // O ponto j
            y2 = y[j];
            // Calculando os parâmetros
            a = y2 - y1;
            b = x1 - x2;
            c = ((x1*y2) - (x2*y1));
            // Checando se os pontos são extremos
            r = cheCk(); // -> O(N³)
            // Salvando os pontos extremos num vetor
            if (r >= k2){
                    pontos.push_back(i);
                    pontos.push_back(j);
            }
        }
    }
    return pontos;
}	

// Função para salvar dados em CSV
int saveCSV(vector<int> ps){
    // Criando os arquivos
    ofstream f1, f2;
    // Construindo o primeiro arquivo
    f1.open("pontos.csv");
	f1 << "X,Y" << endl;
    for (int i=0; i<N; i++){
        f1 << x[i] << "," << y[i] << endl; // O(N)
    }
    f1.close();
    // Construindo o segundo arquivo
	int S = ps.size();
    f2.open("extremos.csv");
	f2 << "PE" << endl;
    for (int i=0; i<S; i++){
        f2 << ps[i] << endl; // O(N)
    }
    f2.close();
    return 0;
}

//FIM
// Para compilar: g++ prog.cc -o saida
