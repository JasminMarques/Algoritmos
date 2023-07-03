// Questão 05
// Aluna: Jasmin Marques 
// Truma: IF23

#include <iostream>
#include <cstring>
using namespace std;
int main() {
string a;
  getline(cin,a);
  string b = a;
  int e = a.length() -1;
  //função que usa o tamanho da string (nomedastring.length())
  for(int i= 0; i <= a.length() -1; i++, e--) {
    int aux = a[i];
    a[i] = b[e];
    aux = b[e];
  }
cout << a;
  return 0;
}