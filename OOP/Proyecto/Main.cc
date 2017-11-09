#include <iostream>
#include "Player.h"

using namespace std;

int main(){
  Player P1("Max");

  cout<<"Daño: "<<P1.Damage()<<endl;
  P1.Damage(10);
  cout<<"Nombre: "<<P1.Name()<<endl;
  cout<<"Daño: "<<P1.Damage()<<endl;
  P1.Name("Maximiliano");
  cout<<"Nombre: "<<P1.Name()<<endl;
  cout<<P1.Life()<<endl;
  cout<<P1.AttackSpeed()<<endl;
}
