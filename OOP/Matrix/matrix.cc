#include <iostream>

using namespace std;

void impM(double m[][3]);
void impV(double v[]);
void multi(double v[], double vT[], double m[][3]);
void copy(double v[], double vT[]);
void div(double v[]);
double men(double v[]);

int main(){
  double matrix[3][3];
  double vector[3]={1,0,0};
  double vectorT[3]={0,0,0};

  for(int i=0; i<3; i++){
    for(int j=0;j<3;j++){
      cout<<"Ingresa el valor ["<<i<<"]["<<j<<"]: ";
      cin>>matrix[i][j];
    }
  }
  for(int i=0;i<5;i++){
  multi(vector, vectorT, matrix);
  }
  impM(matrix);
  cout<<endl;
  impV(vector);
  return 0;
}

void impV(double v[]){
  for(int i=0; i<3; i++){
    cout<<v[i]<<" ";
    cout<<endl;
  }
}
void impM(double m[][3]){
  for(int i=0; i<3; i++){
    cout<<"|";
    for(int j=0;j<3;j++){
      cout<<m[i][j]<<" ";
    }
    cout<<"|";
    cout<<endl;
  }
}
void multi(double v[], double vT[],double m[][3]){
  int T=0;
  for(int i=0; i<3; i++){
    for(int j=0;j<3;j++){
      T=T+(m[i][j]*v[j]);
    }
    vT[i]=T;
    T=0;
  }
  copy(v,vT);
}

void copy(double v[], double vT[]){
  for(int i=0; i<3;i++){
    v[i]=vT[i];
  }
  for(int i=0; i<3;i++){
    vT[i]=0;
  }
}
void div(double v[]) {
  double Max=0;
  if(v[1]>v[2]>v[3]){
    Max=v[1];
  }
  if(v[2]>v[3]>v[1]){
    Max=v[2];
  }
  if(v[3]>v[2]>v[1]){
    Max=v[3];
  }
  for(int i=0; i<3; i++){
    v[i]=v[i]/Max;
  }
}

double men(double v[]){
  double Men;
  if(v[1]<v[2]<v[3]){
    Men=v[1];
  }
  if(v[2]<v[3]<v[1]){
    Men=v[2];
  }
  if(v[3]<v[2]<v[1]){
    Men=v[3];
  }
  return Men;
}
