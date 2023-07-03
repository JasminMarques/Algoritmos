// Questão 8
// Aluna: Jasmin Marques
// Turma: IF23

#include <iostream>
# include <cstring>
using namespace std;
int main() {
  char a[20];
  char b[10];
  cin.get(a,20);
  setbuf(stdin, NULL);
  cin.get(b,10);
  if ((strstr(a,b) != 0)){
    cout << "Está contida";
  } else {
    cout << "Não está contida";
  }
  return 0;
}