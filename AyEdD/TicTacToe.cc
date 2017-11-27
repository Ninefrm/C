#include <iostream>
#include <vector>

using namespace std;

void imp(vector <int> v);
int Jugador(int i);
int Decision(int i);
bool win(vector <int> v);

int main(){
  vector <int> Gato;
  int Movimiento;
  for(int i=0; i<=8;i++) Gato.push_back(0);
  imp(Gato);
  cout<<"Usa el pad númerico para elegir la posición de tu turno"<<endl<<"{ 7 8 9 }"<<endl<<"{ 4 5 6 }"<<endl<<"{ 1 2 3 }"<<endl<<"X equivale a 1, y O equivale a 2. 0 Es un espacio vacio."<<endl;

  for(int i=0;i<=8;i++){
  cout<<"¿Donde deseas colocar "<<Jugador(i)<<"?."<<endl;
  cin>>Movimiento;
    if(Gato[Decision(Movimiento)]==0){
      Gato[Decision(Movimiento)]=Jugador(i);
      imp(Gato);
    }
    else{
      cout<<"Ese espacio esta ocupado."<<endl;
      i=i-1;
    }
    if(win(Gato)){
      return 0;
    }
  }
  cout<<"Empate."<<endl;
  return 0;
}

void imp(vector <int> v){
  for(int i=0; i<=8;i++){
    cout<<v[i];
    if(i==2 || i==5 || i==8) cout<<endl;
    else cout<<"|";
  }
}
int Jugador(int i){
  if(i==0){
    return 2;
  }
  if(i%2==0){
    return 2;
  }
  else{
    return 1;
  }
}
int Decision(int i){
  if(i==1||i==2||i==3){
    return i+5;
  }
  if(i==4||i==5||i==6){
    return i-1;
  }
  if(i==7||i==8||i==9){
    return i-7;
  }
}
bool win(vector <int> v){
  for(int j=1;j<=4;j++){
    if(v[Decision(5-j)]==v[Decision(5)] && v[Decision(5+j)]==v[Decision(5)]){
      if(v[Decision(5)]==0) return false;
      cout<<"Ganó: "<<v[Decision(5)]<<endl;
      return true;
    }
  }
  if(v[Decision(2-1)]== v[Decision(2)] && v[Decision(2+1)] == v[Decision(2)]){
    if(v[Decision(2)]==0) return false;
    cout<<"Ganó: "<<v[Decision(2)]<<endl;
    return true;
  }
  if(v[Decision(4-3)] == v[Decision(4)] && v[Decision(4+3)] == v[Decision(4)]){
    if(v[Decision(4)]==0) return false;
    cout<<"Ganó: "<<v[Decision(4)]<<endl;
    return true;
  }
  if(v[Decision(6-3)] == v[Decision(6)] && v[Decision(6+3)] == v[Decision(6)]){
    if(v[Decision(6)]==0) return false;
    cout<<v[Decision(6)]<<endl;
    return true;
  }
  if(v[Decision(8-1)] == v[Decision(8)] && v[Decision(8+1)] == v[Decision(8)]){
    if(v[Decision(8)]==0) return false;
    cout<<"Ganó: "<<v[Decision(8)]<<endl;
    return true;
  }
  return false;
}
