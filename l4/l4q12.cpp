// Questão 12
// Aluna: Jasmin Marques
// Turma: IF23

#include <iostream>
#include <cstring>
using namespace std;
int main() {
char s[40];
int i,j, aux;
  cin.get(s,40);
  setbuf(stdin, NULL);
  cin >> i >> j;
  if (i >= 0 && j >= 0) {
    if(i>j) {
      aux = j;
      j = i;
      i = aux;
    }
    for(; i <= j; i ++) {
      cout << s[i];
    }
  }
  return 0;
}