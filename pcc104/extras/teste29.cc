/********************************************************************/
// Programa para criar um GRAFO simples usando classes em C++
// Davi C. Neves - UFOP, DECOM, DEPRO - Novembro de XXI
/********************************************************************/
// Bibliotecas usadas
#include <iostream>
#include <list>

// Prefixos
using namespace std;

// Classe para o objeto GRAFO
class graph{
  public:
    list<int> *listAdj;
    int n;
	// Construtor das instâncias
    graph(int v){
        n = v;
        listAdj = new list<int> [v];
    }
	//  Método para adicionar os elos
    void addElo(int u, int v, bool bi){
        listAdj[u].push_back(v);
        if(bi){
            listAdj[v].push_back(u);
        }
    }
    // Método para apresentar o bagulho
    void mostreG(){
        for(int i=0; i<n; i++){
            cout << i << "-->";
            for(auto it:listAdj[i]){
                cout << it << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

// Função Principal
int main() {
    // Criando o Grafo		
    graph g(5);

	// Adicionando os Elos
    g.addElo(1, 2, true);
    g.addElo(4, 2, true);
    g.addElo(1, 3, true);
    g.addElo(4, 3, true);
    g.addElo(1, 4, true);

	// Mostrando o resultado
	cout << "\nResultado: " << endl;
    g.mostreG();

	return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste29.cc -o saida
