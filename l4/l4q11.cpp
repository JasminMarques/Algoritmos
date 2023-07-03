// Questão 11
// Aluna: Jasmin Marques
// Turma: IF23

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main() {
char a[20];
  float da, valor, d;
  cout << "Digite o nome da mercadoria: \n";
  cin.get(a,20);
  setbuf(stdin, NULL);
  cout << "Digite o valor da mercadoria: \n";
  cin >> valor;
  d = valor * 10/100;
  da = valor - d;
  cout << a << endl;
  cout << "Valor da mercadoria: " << valor << endl;
  cout << "Desconto em reais: " << d << endl;
  cout << "Valor à vista: " << da;
    return 0;
}