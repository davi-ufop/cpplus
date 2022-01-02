// Bibliotecas e prefixos
#include <iostream>
using namespace std;

// Template pra determinar a média interpolada
template <typename tipo>
tipo meDia(tipo x, tipo y){
  tipo dif = (x > y) ? x-y: y-x;
  x = (x < y) ? x: y;
  return x + dif/2;
}	

// Função principal
int main(){
  // Declaração das variáveis
  double x1, y1;
  int x2, y2;

  // Entradas dos dados
  cout << "Digite o valor de x1 (real): ";
  cin >> x1;
  cout << "Digite o valor de y1 (real): ";
  cin >> y1;
  cout << "Digite o valor de x2 (inteiro): ";
  cin >> x2;
  cout << "Digite o valor de y2 (inteiro): ";
  cin >> y2;

  // Resultados diretos 
  cout << "\nMédias Triviais:\n";
  cout << "MedTriv 1 = " << (x1 + y1)/2 << endl;
  cout << "MedTriv 2 = " << (x2 + y2)/2 << endl;
 
  // Determinando médias interpoladas
  double med1 = meDia<double>(x1, y1);
  int med2 = meDia<int>(x2, y2);

  // Valores interpolados
  cout << "\nMédias Interpoladas:\n";
  cout << "MedInter 1 = " << med1 << endl;
  cout << "MedInter 2 = " << med2 << endl;

  return 0;
}
// FIM - Para compilar: g++ teste01.cc -o saida
