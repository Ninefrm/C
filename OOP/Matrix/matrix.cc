#include <iostream>

using namespace std;

int main(){
  double matrix[3][3];
  double vector[3]={1,0,0};
  double vectorT[3]={0,0,0};
  double T=0;

  for(int i=0; i<3; i++){
    cout<<vector[i]<<" ";
  }

  cout<<endl;

  for(int i=0; i<3; i++){
    for(int j=0;j<3;j++){
      cout<<"Ingresa el valor ["<<i<<"]["<<j<<"]: ";
      cin>>matrix[i][j];
    }
  }

  for(int i=0; i<3; i++){
    cout<<"|";
    for(int j=0;j<3;j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<"|";
    cout<<endl;
  }

  for(int i=0; i<3; i++){
    for(int j=0;j<3;j++){
      T=T+(matrix[i][j]*vector[j]);
    }
    vectorT[i]=T;
  }
  return 0;
}
