// **************************************************************** //
// Programa elaborado pra implementar o Algoritmo respectivo ao
// problema da coleta de moedas com programação dinâmica
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Nov./XXI
// **************************************************************** //
// Importando as bibliotecas
#include <iostream>    // Entradas/Saídas
#include <vector>      // Vector pra armazenar dados
#include <ctime>       // Tempo para semente randômica

// Prefixos -> Namespaces
using namespace std;

// Variável Global - Contador de operações
int C = 0;

// Classe dos cofres pra coletar moedas
class cofreMoedas{
  public:
  // Método pra coletar moedas conforme sugerido por Anany
  int coletaMax(vector<int> M){  // A entrada deve ser as Moedas (M)
    int n = M.size();    // Número de moedas 
    vector<int> V(n+1);  // Vetor (tabela) pra armazenar as somas
    V[0] = 0;       // Primeiro valor armazenado = ZERO
    V[1] = M[0];    // Segundo valor armazenado = Primeira Moeda
    for (int i=2; i<=n; ++i){    // Divide a recorrência
      C++;   // Contando as operações básicas a seguir
      int VP = V[i-2] + M[i-1];  // Soma das moedas pares (0,2,...)
	    int VI = V[i-1];           // Soma das moedas impares (1,3,...)
	    if (VP < VI){  // Seleção do maior | a referência acima para 
        V[i] = VI;   // Atribui o maior  | pares e impares se alterna     
			} else {       // que será VI ou VP
        V[i] = VP;   // <- neste caso aqui! 
			}		
    }
    // Resultado do método acima
    cout << "Soma = [";
    for (int i=0; i<n; ++i){
      cout << V[i] << ", ";
		}
		cout << V[n] << "]\n";
		// Retorna o maior valor, último item das somas armazenada.
		return V[n];
	}
};

// Função principal
int main(){
  // Semente randômica	
  srand(time(0));
  // Variáveis e parâmetros do processo	
  int N, Valor;   
  cofreMoedas Sacola;
	vector<int> Moedas;
	// Determine a quantidade inicial de moedas
	cout << "Digite a quantidade de moedas: ";
	cin >> N;
	// Gerando os valores aleatórios das moedas [0,30]
	cout << "Moedas = (";
	for (int i=0; i<N; ++i){
    Moedas.push_back(1 + rand()%30);  // Randomizado
		cout << " " << Moedas[i];   // Mostrando as moedas
	}
	cout << " )\n";
	// Determinando o valor máximo de moedas coletadas
	Valor = Sacola.coletaMax(Moedas);
	// Resultado do problemas proposto
	cout << "Valor máximo coletado = " << Valor << endl;
	cout << "Número de operações básicas = " << C << endl;
  // Pronto!	
  return 0;
}
// **************************************************************** //
// FIM
// Para compilar: g++ prog.cc -o saida
