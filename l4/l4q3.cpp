// Questão 03
// Aluna: Jasmin Marques 
// Truma: IF23

#include <iostream>
using namespace std;
int main() {
  char i=0, a[20];
  int s=0;
  cin.get(a,20);
  while (a[i] != '\0') {
    s+=1;
    i++;
  }
  cout << s;
  return 0;
}