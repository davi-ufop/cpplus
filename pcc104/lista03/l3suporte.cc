#include <iostream>
#include <algorithm>
int main(){
  using namespace std;
  int M[] = {1, 2, 3, 4, 5, 6};
  const int N=sizeof(M)/sizeof(M[0]);
  sort(M, M+N);
  do {
    cout << "( ";
    for (int i=0; i<N; i++){ cout << M[i] << " "; }
    cout << ")\n"; 
  } while ( next_permutation(M,M+N) );
  return 0;
}
