#include <iostream>

using namespace std;

int main(){
  int N=0;
  int Divisible=0;
  cout<<"¿Cuantos números serán? ";
  cin>>N;
  int *Numeros = new int[N];
  for(int i=0;i<N;i++){
    cout<<"Ingresa los valores: ";
    cin>>Numeros[i];
  }
  /*for(int i=1;i<N;i++){
    Divisible=i+Divisible;
  }
  cout<<"El valor divisible será: "<<Divisible<<endl;
  */
  for(int i=0;i<N-2;i++){
    for(int j=1;j<N;j++){
      if((Numeros[i]+Numeros[j])%3==0){
        Divisible=Divisible+1;
      }

    }
  }
  cout<<"Output: "<<Divisible<<endl;


  delete []Numeros;
  return 0;
}
