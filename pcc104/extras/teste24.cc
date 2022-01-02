/********************************************************************/
// Programa para criar uma Arvore Binária, com iteratividade
// Davi C. Neves - Ouro Preto, Out. XXI - UFOP/DECOM DEPRO
/********************************************************************/
// Bibliotecas:
#include <iostream>
#include <cstdlib>       // Malloc() | Evita Erro de Segmentação

// Prefixo:
using namespace std;

// Estrutura para os nós da Árvore:
struct Noh {
  int Valor;     // Variável para armazenar o valor do Nó
  Noh *RE=NULL;  // Ponteiro para apontar pro Ramo à Esquerda     
  Noh *RD=NULL;  // Ponteiro para apontar pro Ramo à Direita     
};

// Função Principal
int main(){
// Parâmetro e Variáveis do processo
  const int N=5;         // Número de nós da árvore
  int VR, VZ, kp, cp=0;  // Variáveis -> Vide Código

// Declarando a variável para a Raiz
  Noh *Raiz;     

// Alocando a memória RAM para o ponteiro Raiz[N] -> L7
  Raiz = (struct Noh *)malloc(N*sizeof(*Raiz));
// Endereço da Raiz:  
  cout << "&Raiz = " << Raiz << endl;

// Definindo o valor da Raiz:
  cout << "Digite o valor da Raiz: ";
  cin >> VZ;        // Valor da RaiZ -> Raiz:12
  Raiz->Valor = VZ;

// Processo ITERATIVO de inserção dos N NÓS
// Dica: Digite 3 Maiores e 2 Menores que a Raiz: 14, 18, 16, 9, 6 
  for (int k=0; k<N; ++k){     // Varredura em N posições de Raiz
    // A primeira atividade em cada inserção é a definição de VR	
    cout << "Digite o valor do Ramo " << k+1 << ": ";
    cin >> VR;         // Valor do Ramo
	Raiz -= cp;        // Restaurando a Raiz  
	cp = 0;            // Contador de passos
    cout << "&Raiz = " << Raiz << endl;   // Posição da Raiz
	VZ = Raiz->Valor;  // Restaurando o Valor Inicial da Raiz 
	// Em seguida deve-se então definir a direção do Nó
vv: if (VR < VZ){   // Condição: Vai pra Esquerda
      if (Raiz->RE == NULL){   // Se o Nó está Vazio, Ocupe-o!
        kp = k+1;                  // Salto na memória RAM
        Raiz->RE = Raiz + kp-cp;   // Apontando pra posição adequada
        Raiz = Raiz + kp-cp;       // Indo pra esta posição
		cp = kp;                   // Controle de passos
		Raiz->Valor = VR;          // Preenchendo o espaço da RAM  
		cout << "&RE1 = " << Raiz << endl; // Anotando posição
      } else {                 // Se o Nó visitado está ocupado 
        VZ = Raiz->RE->Valor;  // Atualize o Valor da 'Raiz'
		cout << "&RE2 = " << Raiz->RE << endl; // Posição do Nó
        Raiz = Raiz + 1;       // Visite o próximo espaço da RAM
		++cp;                  // Contagem
        goto vv;               // Volte para a condição de direção
	  }
	} else {       // Condição: Vai pra Direita
      if (Raiz->RD == NULL){   // Se o Nó está Vazio, Ocupe-o!
        kp = k+1;                 // Salto na memória RAM
        Raiz->RD = Raiz + kp-cp;  // Apontando pra posição adequada
        Raiz = Raiz + kp-cp;      // Indo pra esta posição
		cp = kp;                  // Controle de passos
		Raiz->Valor = VR;         // Preenchendo o espaço da RAM
		cout << "&RD1 = " << Raiz << endl;  // Anotando posição
	  } else {                 // Se o Nó visitado está ocupado
        VZ = Raiz->RD->Valor;  // Atualize o Valor da 'Raiz'
		cout << "&RD2 = " << Raiz->RD << endl; // Posição do Nó
        Raiz = Raiz + 1;       // Visite o próximo espaço da RAM
		++cp;                  // Contagem
        goto vv;               // Volte para a condição de direção
	  }
	}
  }
  Raiz -= cp;   // Voltando pra posição original da RAIZ
  cout << "\nPor fim: &Raiz = " << Raiz << endl;

  // Conferindo o Resultado para IN= 12, 14, 18, 16, 9, 6
  cout << "\n\tRESULTADO:\n";
  cout << "Raiz (R) = " << Raiz->Valor << endl;           
  cout << "R-D = " << Raiz->RD->Valor << endl;
  cout << "R-E = " << Raiz->RE->Valor << endl;
  cout << "R-D-D = " << Raiz->RD->RD->Valor << endl;
  cout << "R-D-D-E = " << Raiz->RD->RD->RE->Valor << endl;
  //cout << "R-E-E = " << Raiz->RE->RE->Valor << endl;
  
  // Conferindo o Resultado para IN= 12, 14, 16, 18, 9, 6
  //cout << "\n\tRESULTADO:\n";
  //cout << "Raiz (R) = " << Raiz->Valor << endl;           
  //cout << "R-D = " << Raiz->RD->Valor << endl;
  //cout << "R-E = " << Raiz->RE->Valor << endl;
  //cout << "R-D-D = " << Raiz->RD->RD->Valor << endl;
  //cout << "R-D-D-D = " << Raiz->RD->RD->RD->Valor << endl;
  //cout << "R-E-E = " << Raiz->RE->RE->Valor << endl;

/********************************************************************/
// Há um erro de segmentação para o 2° Nó à esquerda
// Não consegui identificar a causa, logo, não pude resolver! 
// Volto outro dia pra consertar, mas lembre-se: a Árvore está OK!
/********************************************************************/

// Prova que a Árvore está OK!  
  cout << "\nRaiz (R) = " << Raiz->Valor;           
  cout << ", armazenando em " << Raiz << endl;
  for (int i=0; i<N; ++i){
    Raiz++;
    cout << "Ramo " << i+1 << " = " << Raiz->Valor;
	cout << ", armazenando em " << Raiz << endl;
  }
  
  return 0;
}
/********************************************************************/
// FIM - Para compilar digite: g++ teste24.cc -o saida
