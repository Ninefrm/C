#include <iostream>
using namespace std;
int main(){
  int A=0, B=0;
  int X=0;
  int division=0;
  int Total=0;
  cout<<"Interval[A,B]."<<endl;
  cout<<"A: ";
  cin>>A;
  cout<<"B: ";
  cin>>B;
  int Array=0;
  Array=B-A;
  int Numeros[Array];
  for(int i=0; i<=Array;i++){
    Numeros[i]=A;
    A=A+1;
  }
  int Valor=B;
  while(X<=Array){
    for(int i=0;i< Valor;i++){
      //cout<<"Estando: "<<Numeros[Array-i]<<endl;
      if(Numeros[Array]%(Valor-i)==0){
        division=division+1;
    }
    }

    if(division%2==0){
      Array--;
      division=0;
    }
    else{
    Total=1+Total;
    division=0;
    Array--;
    }
  }
  cout<<"The number of values having an Odd Number of Divisors: "<<Total<<endl;

  return 0;
}
