/* TIC TAC TOE 100% CS ACADEMY
name: Samuel Maximiliano Fonseca Romero.
school: DICIS 2017.
*/
#include <iostream>
#include <vector>

using namespace std;

int result(vector <int> G, int uno, int dos, int zero);
int getTurno(vector <int> G, int uno, int dos, int zero);
void getDatos(vector <int> G, int &uno, int &dos, int &zero);
void getZero(vector<int> G, vector <int> &zero);
bool dosequinas(vector <int> G, int n);
int GatoFull(vector <int> G, int uno, int dos);
int Decision(int i);
bool unaequinas(vector <int> G, int n);
int main(){
  vector <int> G;
  int uno=0, dos=0, zero=0;

  for(int i=0; i<=8;i++) G.push_back(0);
  for(int i=0; i<=8;i++) cin>>G[i];

  getDatos(G,uno,dos,zero);

  cout<<result(G, uno, dos, zero);
  return 0;
}
int result(vector <int> G, int uno, int dos, int zero){
  vector <int> cero;
  int Turno=  getTurno(G,uno,dos,zero);
  if(Turno==-1) return -1;
  if(GatoFull(G,uno,dos)==1||GatoFull(G,uno,dos)==2||GatoFull(G,uno,dos)==-1)return GatoFull(G,uno, dos);
  else{


  if(Turno==G[4]&&uno==2) return Turno;

  if(Turno==0) return 0;
  int TurnoSig=0;
  if(Turno==1)TurnoSig=2;
  if(Turno==2)TurnoSig=1;

  if(G[4]==1&&dos==1)return 1;
  if(zero==7&&G[4]==2&&uno==1&&dos==1) return 0;


  getZero(G,cero);
  if(zero==2&&Turno!=2)return 1;
  if(zero==2&&Turno==2)return 0;

  for(int i=0;(unsigned)i<cero.size()+1;i++){
    if(cero[i]==0){
      if(Turno == G[3] && G[6] == G[3]) return Turno;
      if(Turno == G[1] && G[2] == G[1]) return Turno;
      if(Turno == G[4] && G[8] == G[4]) return Turno;
      if(Turno == G[2] && G[6] == G[2] && G[3]==0 && G[1]==0) return Turno;
      if(TurnoSig == G[2] && G[6] == G[2] && G[3]==0 && G[1]==0) return TurnoSig;
    }
    if(cero[i]==1){
      if(Turno == G[0] && G[2] == G[0]) return Turno;
      if(Turno == G[4] && G[7] == G[4]) return Turno;
    }
    if(cero[i]==2){
      if(Turno == G[1] && G[0] == G[1]) return Turno;
      if(Turno == G[5] && G[8] == G[5]) return Turno;
      if(Turno == G[4] && G[6] == G[4]) return Turno;
      if(Turno == G[8] && G[0] == G[8] && G[1]==0 && G[5]==0) return Turno;
      if(TurnoSig == G[8] && G[0] == G[8] && G[1]==0 && G[5]==0) return TurnoSig;

    }
    if(cero[i]==3){
      if(TurnoSig == G[0] && G[6] == G[0] && G[7]==0) return TurnoSig;
      if(Turno == G[0] && G[6] == G[0]) return Turno;
      if(Turno == G[4] && G[5] == G[4]) return Turno;
    }
    if(cero[i]==4){
      if(TurnoSig == G[3] && G[7] == G[3] && G[1]==0 && G[5]==0) return TurnoSig;
      if(TurnoSig == G[1] && G[5] == G[1] && G[3]==0 && G[7]==0) return TurnoSig;
      if(TurnoSig == G[0] && G[2] == G[0] && G[6]==0 && G[8]==0) return TurnoSig;
      if(TurnoSig == G[6] && G[8] == G[6] && G[0]==0 && G[2]==0) return TurnoSig;

      if(Turno == G[3] && G[7] == G[3] && G[1]==0 && G[5]==0) return Turno;
      if(Turno == G[1] && G[5] == G[1] && G[3]==0 && G[7]==0) return Turno;
      if(Turno == G[0] && G[2] == G[0] && G[6]==0 && G[8]==0) return Turno;
      if(Turno == G[6] && G[8] == G[6] && G[0]==0 && G[2]==0) return Turno;

        for(int j=4;j>1;j--){
          if(G[4-j]==Turno && G[4+j]==Turno){
            return Turno;
          }
        }
    }
    if(cero[i]==5){
      if(Turno == G[2] && G[8] == G[2]) return Turno;
      if(Turno == G[4] && G[3] == G[4]) return Turno;
    }
    if(cero[i]==6){
      if(Turno == G[3] && G[0] == G[3]) return Turno;
      if(Turno == G[7] && G[8] == G[7]) return Turno;
      if(Turno == G[4] && G[2] == G[4]) return Turno;
      if(Turno == G[0] && G[8] == G[0] && G[3]==0 && G[7]==0) return Turno;
      if(TurnoSig == G[0] && G[8] == G[0] && G[3]==0 && G[7]==0) return TurnoSig;

    }
    if(cero[i]==7){
      if(Turno == G[6] && G[8] == G[6]) return Turno;
      if(Turno == G[4] && G[1] == G[4]) return Turno;
    }
    if(cero[i]==8){
      if(Turno == G[5] && G[2] == G[5]) return Turno;
      if(Turno == G[7] && G[6] == G[7]) return Turno;
      if(Turno == G[4] && G[0] == G[4]) return Turno;
      if(Turno == G[6] && G[6] == G[2] && G[7]==0 && G[5]==0) return Turno;
      if(TurnoSig == G[6] && G[6] == G[2] && G[7]==0 && G[5]==0) return TurnoSig;

    }
  }
  if((zero == 7 && dos == 1 && G[0]==1) || G[6]==1 || G[8]==1 || (G[2]==1 && G[4]==0)) return 1;

  if(G[4]==0&&G[0]+G[1]+G[2]==G[6]+G[7]+G[8]&&G[3]==G[5])return 1;
  if(Turno==2 && G[4]==0) return 1;
  return -1;
  }
}
int getTurno(vector <int> G, int uno, int dos, int zero){
  if(((uno-dos)<0) || (dos>uno) || (uno-dos)>1) return -1;
  if((uno-dos)==0 && zero==5 && G[4]==2 && dosequinas(G,1)) return 1;

  if((uno-dos)==0 && zero==5 && G[4]==2 && unaequinas(G,1) && dosequinas(G,1)==false) return 0;
  if(zero==5 && (uno-dos)==0 && dosequinas(G,1)==false && G[4]==2 && unaequinas(G,1)==false) return 2;
  if(zero==6 && (uno-dos)==1 && dosequinas(G,1)==false && G[4]==2 && unaequinas(G,1)==false) return 2;


  if((uno-dos)==1 && zero==6) return 0;


  if(zero==5&&uno==dos&& !dosequinas(G,1)) return 0;
  if(zero==9 || zero==8||(zero==7 && uno!=1 && dos!=1)) return 0;
  if((uno-dos)==0 && zero>0) return 1;
  if((uno-dos)==1 && zero>0) return 2;
  if((uno==dos) && zero==0) return 0;
  return 0;
}
void getDatos(vector <int> G, int &uno, int &dos, int &zero){ //vemos cuantos unos, dos y ceros hay
  for(int i=0; i<=8;i++){
    if(G[i]==1) uno++;
    if(G[i]==2) dos++;
    if(G[i]==0) zero++;
  }
}
void getZero(vector <int> G, vector <int> &zero){ //con esto sabremos donde hay aún ceros
  for(int i=0;i<9;i++){
    if(G[i]==0) zero.push_back(i);
  }
}
bool dosequinas(vector <int> G, int n){
  if(G[0] == n && G[2] == n) return true;
  if(G[0] == n && G[6] == n) return true;
  if(G[0] == n && G[8] == n) return true;

  if(G[2] == n && G[6] == n) return true;
  if(G[2] == n && G[8] == n) return true;

  if(G[6] == n && G[8] == n) return true;
  return false;
}
bool unaequinas(vector <int> G, int n){
  if(G[0] == n || G[2] == n) return true;
  if(G[0] == n || G[6] == n) return true;
  if(G[0] == n || G[8] == n) return true;

  if(G[2] == n || G[6] == n) return true;
  if(G[2] == n || G[8] == n) return true;

  if(G[6] == n || G[8] == n) return true;
  return false;
}
int GatoFull(vector <int> G, int uno, int dos){
  int win=0,aux=0;
  for(int j=1;j<=4;j++){
    if(G[Decision(5-j)]==G[Decision(5)] && G[Decision(5+j)]==G[Decision(5)]){
      if(G[Decision(5)]==0) return false;
      win = win+G[Decision(5)];
      aux=G[Decision(5)];
    }
  }
  if(G[Decision(2-1)]== G[Decision(2)] && G[Decision(2+1)] == G[Decision(2)]){
    if(G[Decision(2)]==0) return false;
    win = win+G[Decision(2)];
    aux = G[Decision(2)];
  }
  if(G[Decision(4-3)] == G[Decision(4)] && G[Decision(4+3)] == G[Decision(4)]){
    if(G[Decision(4)]==0) return false;
    win = win+G[Decision(4)];
    aux = G[Decision(4)];
  }
  if(G[Decision(6-3)] == G[Decision(6)] && G[Decision(6+3)] == G[Decision(6)]){
    if(G[Decision(6)]==0) return false;
    win = win+G[Decision(6)];
    aux = G[Decision(6)];
  }
  if(G[Decision(8-1)] == G[Decision(8)] && G[Decision(8+1)] == G[Decision(8)]){
    if(G[Decision(8)]==0) return false;
    win = win+G[Decision(8)];
    aux = G[Decision(8)];
  }
  if(win==3)return-1;
  if((aux-win)==0||(win-aux)==1){
    if(aux==1 && uno==dos)return -1;
    if(aux==2 && uno>dos) return -1;
    return aux;
  }
  return 8;
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
  return 0;
}
