/********************************************************************/
// Inserindo elemento K em uma lista encadeada ordenada - POINTER
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DEPRO - DECOM 
/********************************************************************/
// Biblioteca
#include <iostream>

// Prefixos
using namespace std;

// Definindo o objeto: Elemento(chave, endereço do próximo elemento)
struct Elemento{
  int chave;          // Valor chave
  Elemento *poste;    // Endereço hexadecimal na RAM - Posterior
  Elemento *antes;    // Endereço hexadecimal na RAM - Anterior
};

// Método para inserir os N elementos da lista
Elemento* constroE(Elemento *E, int N){
  Elemento *NE = new Elemento;  // Evita falha de segmento
  // Começando com a cabeça da lista
  for (int i=0; i<N; ++i){  // Método iterativo
    cout << "Chave do " << i+1 << "° elemento = ";
	cin >> NE->chave;      // Entrada da chave
	E->antes = E->poste;   // Salvando a posição anterior
    E += i;                // Próxima posição na RAM
	// SWAP - Troca de endereços
    NE->poste = E;  // Ponteiro poste de NE aponta para E       
    E->poste = NE;  // Ponteiro poste de E aponta para NE 
    E = E->poste;   // Ponteiro E aponta para seu poste -> NE
	// Verificação
    cout << "Chave = " << E->chave << endl;
    cout << "Antes = " << E->antes << endl;
    cout << "Poste = " << E->poste << endl;
    cout << endl;
  }
  return E;  // Retorna a calda da lista
}

// Função principal
int main(){
  // Parâmetros e variáveis
  int L, k, p=0;  		

  // Definindo o ponteiro HEAD de elementos:
  Elemento *A = new Elemento;
  A->chave = 2;
  A->poste = NULL;

  // Construindo a lista com um ponteiro
  cout << "\n\tLISTA ENCADEADA" << endl;
  cout << "Qual é o número de elementos da lista?" << endl;
  cin >> L; 
  // Chamando o método de construção
  A = constroE(A, L);

  // Conferindo
  cout << "A->poste = " << A->poste << endl;
  cout << "A->antes = " << A->antes << endl;
  
  cout << "\nFIM\n\n"; 
  return 0;
}
/********************************************************************/
// FIM - Para compilar: g++ teste17.cc -o saida
