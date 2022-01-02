// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo ConvexHull 
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <locale>    // Gramática Local
#include <time.h>    // Tempo/Datas
#include <cmath>     // Matemática
#include <vector>    // Para usar a classe vector

// Prefixos -> Namespaces
using namespace std;

// Função para gerar vetores
vector<double> gerVec(int N, double dt);

// Função para apresentar coordenadas de vetores
double showPos(vector<double> u, vector<double> v, int m);

// Função para determinar a distância dos pares
vector<double> distPar(vector<double> u, vector<double> v, int m);

// Função principal
int main(){
    // Truncamento dos valores double em cout
	cout.precision(2);	
    // Acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    // Parâmetros e variáveis
    int n=30;        // Tamanho da instância - Número de pontos
    vector<double> x, y;     // Vetores das coordenadas
    double dm;               // Distâncias
    int qi, pj;              // Pontos mais próximos
    vector<double> w;        // Vetor para salvar resultados

    // Gerando os pontos no plano cartesiano
    x = gerVec(n, 3.14);    // Coordenadas x dos n pontos no plano
    y = gerVec(n, 2.71);    // Coordenadas y dos n pontos no plano
		
    // Apresentando o array de entrada - Pontos no Plano Cartesiano [0, L]
    showPos(x, y, n);

    // Determinando a menor distância entre dois pontos
    w = distPar(x, y, n);
    dm = w[0];     // Distância Mínima
	qi = w[1];     // Ponto i mais próximo
	pj = w[2];     // Ponto j mais próximo

    // Resultado - Par Mais Próximo - Closest Pair - LEIAME
    cout << "Os pontos mais próximos são: " << qi << " e " << pj << endl;
    cout << "Ponto " << qi << " = (" << x[qi] << ","  << y[qi] << ")\n";
    cout << "Ponto " << pj << " = (" << x[pj] << ","  << y[pj] << ")\n";
    cout << "A distância entre estes pontos = " << dm << endl;
     
    return 0;
}

// Função para gerar vetores
vector<double> gerVec(int N, double dt){
    srand(time(NULL)+dt);  // Semente randômica 
	int D=230;         // Denominador para limitar valores
	double L=12.3/D;   // Limite dos valores -> [0, L]
    vector<double> X;  // Vetor para armazenar os N valores
    for (int i=0; i<N; i++){X.push_back(L*(rand()%D));} // Geração
    return X;
}

// Função para apresentar posições de vetores 
double showPos(vector<double> u, vector<double> v, int m){
    // Apresentando o array de entrada - Pontos no Plano Cartesiano [0, L]
    cout << "\nPontos no Plano Cartesiano:\n";
    for (int i=0; i<m; i++){  // Varredura por todos os n pontos           
        cout << "(" << u[i] << "," << v[i] << ")  ";
    }
    cout << "\n" << endl;
    return 0;
}

// Função para determinar a distância dos pares
vector<double> distPar(vector<double> u, vector<double> v, int m){
    // Variáveis internas
    double d, dmin;     // Distâncias usadas nos cálculos
	double pi, qj;      // Pontos mais próximos
    
	// Determinando o Par de pontos Mais Próximos - Algoritmo ClosestPair
    dmin = INFINITY;    // Valor inicial da distância
    for (int i=0; i<m; i++){               // Varredura por todos os
        for (int j=(i+1); j<=m; j++){  // pontos do plano cartesiano
            double du = u[i]-u[j];   // Diferença das coordenadas X
            double dv = v[i]-v[j];   // Diferença das coordenadas Y
            d = sqrt((du*du) + (dv*dv));   // Distância Euclidiana
            if (d < dmin){        // Busca pela menor distância
                dmin = d;         // Salvando a menor distância 
                pi = (double) i;  // Ponto i do Par mais próximo 
				qj = (double) j;  // Ponto j do Par mais próximo
            }
        }
    }
	vector<double> Vi;
	Vi.push_back(dmin);
	Vi.push_back(pi);
	Vi.push_back(qj);
    return Vi;
}

// FIM
// Para compilar: g++ prog.cc -o saida
