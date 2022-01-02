/********************************************************************/
// Biblioteca para gerar e manipular arvores e grafos - Dados NSQL
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM
// USADA NOS PROGRAMAS: 4 e 5
/********************************************************************/
// Importando bibliotecas
#include <iostream>
#include <vector>
#include <list>
#include <set>

// Prefixos respectivos a pacotes
using namespace std;

class NodeTree{
  public:
    char id;
    int chave;
    set<char> caminho;
    list<char> folhasD;
    list<char> folhasE;
};

// Método para definir as Chaves e IDs de cada nó:
vector<NodeTree> chavesIDs(char VJ[], vector<int> VK, vector<NodeTree> VM){
  const int NJ = VK.size();
  for (int j=0; j<NJ; ++j){
    VM[j].id = VJ[j];
    VM[j].chave = VK[j];
  }
  return VM;
}

// Método para mostrar as Chaves e IDs
void showKIDs(vector<NodeTree> VM){
  const int NK = VM.size();
  for(int k=0; k<NK; ++k){
    cout << "A chave de "<< VM[k].id << " = " << VM[k].chave << endl;
  }
}

// Método para encontrar o índice do próximo maior que K
int buscaIMaior(int ik, const int K, const int KI, vector<int> VK){
  int ic=ik;
  while (VK[ic] < K and ic < KI){ ic++; }
  return ic;
}

// Método para encontrar o índice do próximo menor que K
int buscaIMenor(int ik, const int K, const int KI, vector<int> VK){
  int ic=ik;
  while (VK[ic] > K and ic < KI){ ic++; }
  return ic;
}

// Método para adicionar os nós na árvore
vector<NodeTree> insereNos(vector<NodeTree> VM, vector<int> VK){
  // Parâmetros do processo
  const int NI = VM.size();

  // Configurando o nó raiz
  NodeTree Raiz = VM[0];
  int i = 1, k = 0;
  while(k < 2){
	k = Raiz.folhasD.size() + Raiz.folhasE.size();
    if (VM[i].chave > Raiz.chave){
      Raiz.folhasD.push_back(VM[i].id);
	  i = buscaIMenor(i, Raiz.chave, NI, VK);
    } else {
      Raiz.folhasE.push_back(VM[i].id);
	  i = buscaIMaior(i, Raiz.chave, NI, VK);
    }
  }
  VM[0] = Raiz;

  // Configurando os galhos à esquerda da raiz
  int ie=0;
  while (Raiz.folhasE.front() != VM[ie].id){ ++ie; }
  cout << "GalhoE = " << ie << endl;

  // Configurando os galhos à direita da raiz
  int id=0;
  while (Raiz.folhasD.front() != VM[id].id){ ++id; }
  cout << "GalhoD = " << id << endl;
  
  return VM;
}
