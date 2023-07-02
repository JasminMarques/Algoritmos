// Questão 04
// Aluna: Jasmin Marques 
// Truma: IF23

#include <iostream>
# include <cstring>
using namespace std;
int main() {
  char a[20];
  cin.get(a,20);
  int i = strlen(a);
  for (; i >= 0; i--) {
    cout << a[i];
  }
  return 0;
}