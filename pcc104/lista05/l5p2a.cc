// **************************************************************** //
// Programa para implementar o algoritmo PRIM com método guloso
// Davi Neves - Ouro Preto, MG, Brasil - DECOM/PPGCC - Dez./XXI 
// **************************************************************** //
// Importando bibliotecas
#include <iostream>

// Definindo os namespaces:
using namespace std;

// Parâmetro global -> N° de vértices  
const int V=5;

// Método para encontrar o vértice com a menor chave 
int min_Key(int key[], bool visited[]) { 
  int min=999, min_index;   // O 999 representa o infinito
	// Varredura por todos os vértices:
  for (int v=0; v<V; v++) { 
    // Condições que checa se um vértice foi visitado 
		// e se sua chave é a menor:
    if (visited[v] == false and key[v] < min) { 
      min = key[v];   // Atribuição ao valor mínimo
			min_index = v;  // Definindo o índice do valor mínimo 
    }
  } // Pronto, retorne o índice do mínimo:    
  return min_index;  
}  

// Método para apresentar a árvore mínima armazenada
void print_MST(int parent[], int cost[V][V]) {  
  // Parâmetro inicial
  int minCost = 0;
	// Introdução da saída
	cout << "Elo\tPeso\n";
  // Continuando a saída: Elos e Pesos da 
	// árvore de extensão mínima (MST):	
  for (int i=1; i<V; ++i) {
    cout << parent[i] << " - " << i << " \t" << cost[i][parent[i]] << " \n";  
		minCost += cost[i][parent[i]]; // Próxima etapa
  }
	cout << "Custo Total = " << minCost << endl;
}  

// Método para encontrar a árvore mínima usando a matriz de adjacência
void find_MST(int cost[V][V]) {
  // Variáveis do método	
  int parent[V], key[V];
  bool visited[V];
  // Iniciando os Arranjos:
  for (int i=0; i<V; i++) { 
    key[i] = 999;    // 999 = Infinito
    visited[i] = false;  // Não visitado
    parent[i] = -1;      // Parentesco nulo
  }    
  key[0] = 0;  // Primeiro vértice da MST, configurando key = 0  
  parent[0] = -1;  // Primeiro nó sempre é a Raiz  
  // A MST terá no máximo V-1 vértices  
  for (int x=0; x<V-1; x++) {  
    // Definindo o conjunto mínimo de vértices não inclusos 
    int u = min_Key(key, visited);  
    visited[u] = true;  // Adicione este vértice à MST  
    // Atualize as chaves dos parentes
    for (int v = 0; v < V; v++) {
    // cost[u][v] is non zero only for adjacent vertices of u  
    // visited[v] is false for vertices not yet included in MST  
    // key[] gets updated only if cost[u][v] is smaller than key[v]  
      if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v]) {  
        parent[v] = u;
        key[v] = cost[u][v];  
      }        
    }
  }
  // Apresenta a MST final:  
	print_MST(parent, cost);  
}  

// Método para mostrar a matriz de pesos/custos
void showM(int A[V][V]){
  for (int i=0; i<V; i++) {
    cout << "| ";
	  for(int j=0; j<V; j++) {
		  cout << A[i][j] << " ";
    }
    cout << "|\n";
  }			
}

// Função Principal
int main() {  
  // Variáveis do processo
  int cost[V][V];

	// Entradas da instância
	cout << "Digite os " << V*V << " elementos da matriz\n";
  cout << "de adjacência para um grafo com " << V << " nós.\n";
  for (int i=0; i<V; i++) {
	  for(int j=0; j<V; j++) {
      cout << "A[" << i+1 << "][" << j+1 << "]= "; 
      cin >> cost[i][j];
			cout << endl;
    }
  }
  
	// Realizando a busca proposta
	find_MST(cost);

  // Mostrando a matriz de adjacência
	cout << "Matriz de Adjacência: \n";
  showM(cost);	

	// Pronto!
  return 0;  
}  
// **************************************************************** //
// FIM
// Pra compilar: g++ prog.cc -o saida

// **************************************************************** //
// USE COMO EXEMPLO (construa o grafo):
// | 0 1 3 0 0 |
// | 1 0 0 2 0 |
// | 3 0 0 5 7 |
// | 0 2 5 0 3 |
// | 0 0 7 3 0 |
// **************************************************************** //
