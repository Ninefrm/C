#include <iostream>
#include <array>

using namespace std;

int main(){
  int Z,Q,T, Pares;
  int Izquierdo[101], Derecho[101];
  for(int i=0;i<101;i++)Izquierdo[i]=0;
  for(int i=0;i<101;i++)Derecho[i]=0;
  cout<<"Ingresa el Número de Zapatos"<<endl;
  cin>>Z;
  int *NZ = new int[Z];
  for(int i=0; i<Z;i++){
  cout<<"Ingresa si el zapato es Derecho(0) o Izquierdo(1)"<<endl;
  cin>>Q;
  cout<<"Talla del Zapato: ";
  cin>>T;
  if(Q==0){
    Derecho[T]=1+Derecho[T];
  }
  if(Q==1){
    Izquierdo[T]=1+Izquierdo[T];
  }
  }
  for(int i=1; i<101; i++){
      if(Derecho[i]>=1 &&Izquierdo[i]>=1){
        Pares=(Derecho[i]+Izquierdo[i])/2+Pares;
      }
  }
      cout<<"Existen: "<<Pares<<endl;
  delete[] NZ;
  return 0;
}
