#include <iostream>
using namespace std;

int main() {
  float n1,n2,n3,me,ma;
  char conceito;
  cout << "Digite a primeira nota: ";
  cin >> n1;
  cout << "Digite a segunda nota: ";
  cin >> n2;
  cout << "Digite a terceira nota: ";
  cin >> n3;
  cout << "Digite a media dos trabalhos: ";
  cin >> me;
  ma = (n1 + 2*n2 + 3*n3 + me)/7;
  if(ma >= 9)
    conceito = 'A';
  else if(ma >= 7.5)
    conceito = 'B';
  else if(ma >= 6)
    conceito = 'C';
  else if(ma >= 6)
    conceito = 'C';
  else if(ma >= 4)
    conceito = 'D';
  else if(ma < 4)
    conceito = 'E';

  cout << "Seu conceito e: "<< conceito << endl;
}
