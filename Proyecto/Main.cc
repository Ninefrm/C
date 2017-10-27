#include <iostream>
#include "Player.h"

using namespace std;

int main(){
  Player P1("Max");
  cout<<P1.Damage();
  P1.Damage(10);
  cout<<P1.Name();
  cout<<P1.Damage();
  P1.Name("Maximiliano");
  cout<<P1.Name();
}
