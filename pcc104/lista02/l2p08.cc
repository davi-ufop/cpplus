// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema da Mochila -> 8 produtos, com seus pesos e valores
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <locale>      // Gramática Local
#include <time.h>      // Tempo/Datas
#include <vector>      // Para usar a classe vector
#include <algorithm>   // Para permutação
#include <numeric>     // Produto Interno

// Prefixos -> Namespaces
using namespace std;

// Parâmetros e Variáveis globais
const int N=8;                 // Tamanho da instância - Número de produtos
const int N1=N-1;              // Parâmetro para auxiliar varreduras
const int LV=250;              // Limite para os valores (R$)
const int LW=15;               // Limite para os pesos (kg)
const double Wmax=(N1*LW-10);  // Peso máximo para a mochila (kg)
vector<int> w(N), v(N);        // Vetores para os parâmetros: pesos e valores

// Funções para gerar números inteiros aleatórios -> [0, L]
int RandomNumber1() { return (rand()%LV); }      // [0,LV]
int RandomNumber2() { return (10+rand()%LW); }   // [0,LW]+10

// Função para apresentar os parâmetros: pesos e valores
double showPar();

// Função para calcular a resposta do problema
vector<int> calcResp(vector<int> pd);

// Função principal
int main(){
    // Truncamento dos valores double em cout
    cout.precision(3);	
    // Acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");
	// Números Randômicos
	srand(unsigned(time(0)));

	// Peso máximo da mochila
    cout << "Peso máximo = " << Wmax << endl;

    // Variáveis do problema:
    vector<int> p(N,0);    // Vetor para ponderar -> {0, 0, ..}
	vector<int> S;         // Vetor para armazenar respostas

    // Gerando os parâmetros do problema: pesos (kg) e valores (R$)
    generate(v.begin(), v.end(), RandomNumber1);  // Valores
    generate(w.begin(), w.end(), RandomNumber2);  // Pesos

    // Apresentando o array de entrada - Parâmetros: Pesos e Valores
	showPar();
    
    // Calculando os resultados do problema
    S = calcResp(p);

    // Apresentando os resultados
	cout << "Produtos na mochila: \n";
    for (int j=0; j<N; ++j){ cout << S[j] << " "; }
    cout << endl;
	cout << "Valor total na mochila = " << S[N] << endl;

    return 0;
}

// Função para apresentar os parâmetros: pesos e valores
double showPar(){
   // Apresentando o array de entrada - Pontos no Plano Cartesiano [0, L]
   cout << "\nPesos(kg), Valores(R$):\n";
   for (int i=0; i<N; ++i){  // Varredura por todos os n pontos           
       cout << "(" << w[i] << "," << v[i] << ") "; // Escrita - O(N)
       }
   cout << "\n" << endl;
   return 0;
}

// Função para calcular a resposta do problema
vector<int> calcResp(vector<int> pd){
    vector<int> R;         // Vetor para armazenar a resposta do problema
	double vp=0;           // Valor ótimo dos produtos na mochila
    for (int k=0; k<N; ++k){  // Varrendo todos (sub)conjuntos constituintes
        pd[N1-k]=1;           // Criando os vetores (0,0,1)->(0,1,1)->(1,1,1)
        sort(pd.begin(), pd.begin()+N);    // Permutando os vetores acima
        do{                                // varrendo assim os conjuntos
            // Determinando o peso dos produtos que constituem o conjunto k:	
            int pw = inner_product(w.begin(), w.end(), pd.begin(), 0);
            if (pw <= Wmax){   // Condição limitadora da mochila
			    // Determinando o valor dos produtos do conjunto k na mochila:
                int pv = inner_product(v.begin(), v.end(), pd.begin(), 0);
                if (pv > vp){
                    vp = pv;  // Atribuição do maior valor na mochila
                    R = pd;   // Salvando o conjunto k ótimo
                }
            }   // Condição de permutação:
        } while ( next_permutation(pd.begin(), pd.begin()+N) );
    }  // Agregando o valor dos produtos na mochila ao resultado:
    R.push_back(vp);
    return R;
}

//FIM
// Para compilar: g++ prog.cc -o saida
