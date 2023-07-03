// Questão 7
// Aluna: Jasmin Marques
// Turma: IF23

#include <iostream>
#include <cstring>
using namespace std;
int main() {
char a[20];
  cout << "Escreva uma palavra toda em maiúsculo ou toda em minúsculo: \n";
  cin.get(a,20);
  setbuf(stdin, NULL);
  char b[strlen(a)];
  strcpy(b,a); // copie oq tem em a, e coloque em b
  int e = strlen(a) -1;
  //função que usa o tamanho da string (nomedastring.length())
  for(int i= 0; i <= strlen(a) -1; i++, e--) {
    int aux = a[i];
    a[i] = b[e];
    aux = b[e];
  }
  if (strcmp(a,b) == 0) {
    cout << "É um palíndromo! :)";
  } else {
    cout << "Não é um palíndromo. :(";
  }
  
  return 0;
}