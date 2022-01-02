// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema da Moeda Falsa - Não está otimizado, mas funciona!
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Set./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>  // Entradas/Saídas
#include <locale>    // Gramática Local
#include <time.h>    // Tempo para sementes randômicas
#include <vector>    // Vetores
#include <numeric>   // Funções numéricas -> iota()

// Prefixos -> Namespaces
using namespace std;

// Variáveis e parâmetros globais
int N=25;   // Tamanho da instância
vector<int> W(N, 2), I(N);  // Vetores: Peso(W) e Índices(I)

// Método para apresentar os elementos dos vetores
void ShowVector(vector<int> V, int NK);

// Método para determinar se é Par
bool IsEven(int P);

// Método para Dividir um conjunto Impar
vector<vector<int>> DivideOdd(vector<int> V, vector<int> U);

// Método para Dividir um conjunto Par
vector<vector<int>> DivideEven(vector<int> V, vector<int> U);

// Método para somar os elementos de um vetor
int SomaVi(vector<int> V);

// Métodos para transformar matrizes em vetores
vector<int> GetVN(vector<vector<int>> MA, int No);

// Método para determinar o conjunto solução
void setSolution();

// Função principal
int main(){
  // Acentos e caracteres especiais
  setlocale(LC_ALL, "portuguese");
  // Semente randômica
  srand(time(0));
  
  // Variáveis e parâmetros úteis 
  int K = rand()%N;  // Índice da moeda
 
  // Adicionando a moeda falsa - mais leve!
  W[K] = 1;

  // Preenchendo o vetor I com os valores dos índices
  iota(I.begin(), I.end(), 0);   // O(N)
  
  // Mostrando os vetores
  cout << "\nPonto de partida:\n";
  ShowVector(W, N);
  ShowVector(I, N);

  // Determinando o conjunto solução
  setSolution();

  // Resultado FINAL
  cout << "\nConjunto Resultado:" << endl;
  ShowVector(I, 1);
  cout << "Resultado exato = " << K << endl;
  
  // Pronto!
  return 0;
}

// Método para apresentar os elementos dos vetores
void ShowVector(vector<int> V, int NK) {
  cout << "( ";
  for (int i=0; i<NK; ++i){
    cout << V[i] << " ";  // Mostra os elementos do vetor
  }
  cout << ")" << endl;
}

// Método para determinar se é Par
bool IsEven(int P){
  if ( P%2 != 0 ){  // Condição de par
    return false;
  } else {
    return true;
  }
}

// Método para Dividir um conjunto Impar -> DivideOdd(W, I)
vector<vector<int>> DivideOdd(vector<int> V, vector<int> U){
  // Parâmetros para o loop de partição
  int L1 = V.size();  // Tamanho da instância
  int L2 = L1/2;      // Elemento médio
  int c = L2+1;       // Índice da varredura na parte superior
  // Vetores para armazenar as partes
  vector<int> V1, V2, I1, I2;
  // Particionamento dos vetores em duas partes: V1 < L2 < V2
  for (int i=0; i<L2; ++i) {
    V1.push_back(V[i]); // Pesos menores que o valor médio
    V2.push_back(V[c]); // Pesos maiores que o valor médio
    I1.push_back(I[i]); // Índices respectivos a V1
    I2.push_back(I[c]);	// Índices respectivos a V2
    c++;  // Novo índice superior
  }
  // Resultado
  vector<vector<int>> R { V1, V2, I1, I2 }; 
  return R;
}

// Método para Dividir um conjunto Par -> DivideEven(W, I)
vector<vector<int>> DivideEven(vector<int> V, vector<int> U){
  // Parâmetros para o loop de partição
  int L1 = V.size();  // Tamanho da instância
  int L2 = L1/2;      // Elemento médio
  int c = L2;         // Índice da varredura na parte superior
  // Vetores para armazenar as partes
  vector<int> V1, V2, I1, I2;
  // Particionamento dos vetores em duas partes: V1 < L2 < V2
  for (int i=0; i<L2; ++i) {
    V1.push_back(V[i]); // Pesos menores que o valor médio
    V2.push_back(V[c]); // Pesos maiores que o valor médio
    I1.push_back(I[i]); // Índices respectivos a V1
    I2.push_back(I[c]);	// Índices respectivos a V2
    c++;  // Novo índice superior
  }
  // Resultado
  vector<vector<int>> R { V1, V2, I1, I2 }; 
  return R;
}

// Método para somar os elementos de um vetor
int SomaVi(vector<int> V){
  // Parâmetros e variáveis do método
  int L1 = V.size();  // Tamanho do vetor
  int Soma = 0;  // Variável para armazenar o resultado
  // Operação de soma
  for (int i=0; i<L1; ++i){
    Soma += V[i]; 
  } 
  return Soma;
}

// Métodos para transformar uma matriz em vetores
vector<int> GetVN(vector<vector<int>> MA, int No){
  int Lo = MA[No].size();  // Comprimento do vetor de saída
  vector<int> Vo;   // Vetor de saída (out)
  for (int i=0; i<Lo; ++i){
    Vo.push_back(MA[No][i]);  // Associando elementos
  }	
  return Vo;
}

// Método para determinar o conjunto solução
void setSolution(){
  // Variáveis do método
  int Peso = 2*N;    // Peso do pacote de moedas
  vector<vector<int>> M;  // Matriz usada para divisão
  // Determinando o índice da moeda falsa
  while ( Peso >= 2 ){
    int Lc = W.size();  // Tamanho do conjunto
	cout << "\nTamanho do conjunto = " << Lc << "\nÍndices:\n";
	ShowVector(I, Lc);  // Mostrando os índices
	cout << "Pesos:" << endl;
	ShowVector(W, Lc);  // Mostrando os pesos
	bool PoI = IsEven(Lc); // Tamanho do conjunto é Par?
	if ( PoI == 1 ){ // Se Lc for Par, segue os comandos:
      M = DivideEven(W, I);  // Divisão das moedas em dois pacotes
      vector<int> V1 = GetVN(M, 0);  // Vetor peso do pacote 1
      vector<int> V2 = GetVN(M, 1);  // Vetor peso do pacote 2
      int S1 = SomaVi(V1);  // Peso do pacote 1
      int S2 = SomaVi(V2);  // Peso do pacote 2
      if ( S1 < S2 ){  // Se S1<S2, a moeda estará no pacote 1, mais leve!
        W = GetVN(M, 0); // Novos pesos - truncados
        I = GetVN(M, 2); // Novos índices - truncados
        Peso = S1; // Peso de controle
      } else {  // Senão, a moeda estará no pacote 2, mais leve!
        W = GetVN(M, 1); // Novos pesos - truncados
        I = GetVN(M, 3); // Novos índices - truncados
        Peso = S2; // Peso de controle
      }
    } else {  // Se Lc for Impar, segue os comandos:
      M = DivideOdd(W, I);  // Divisão das moedas em dois pacotes
      vector<int> V1 = GetVN(M, 0); // Vetor peso do pacote 1
      vector<int> V2 = GetVN(M, 1); // Vetor peso do pacote 2
      int S1 = SomaVi(V1); // Peso do pacote 1
      int S2 = SomaVi(V2); // Peso do pacote 2
      if ( S1 < S2 ){  // Se S1<S2, a moeda estará no pacote 1, mais leve!
        W = GetVN(M, 0); // Novos pesos - truncados
        I = GetVN(M, 2); // Novos índices - truncados
        Peso = S1; // Peso de controle
      } else if ( S1 > S2 ) { // Se S1>S2, a moeda estará no pacote 2!
        W = GetVN(M, 1); // Novos pesos - truncados
        I = GetVN(M, 3); // Novos índices - truncados
        Peso = S2; // Peso de controle
      } else { // Se S1=S2, a moeda é o elemento médio!
        I = { I[Lc/2] }; // Índice do elemento médio
        Peso = 1; // Peso da moeda falsa
	  }
    }
  }
}

//FIM
// Para compilar: g++ prog.cc -o saida
