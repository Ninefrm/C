#include <iostream>

using namespace std;

int main(){
  int n,m,x,y;

  cout<<"Ingresa N: ";
  cin>>n;
  cout<<"Ingresa M: ";
  cin>>m;
  cout<<"Ingresa X: ";
  cin>>x;
  cout<<"Ingresa Y: ";
  cin>>y;
  if(m/x==n){
    cout<<"Evoluciones total: "<<n<<endl;
  }
  while(m/x < n){
    n--;
    m+=y;
  }
  cout<<"Evoluciones total: "<<(m-y)/x<<endl;
  return 0;
}
