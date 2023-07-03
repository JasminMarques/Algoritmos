// Questão 06
// Aluna: Jasmin Marques 
// Truma: IF23

#include <iostream>
#include <cstring>
using namespace std;
int main() {
  char a[20], c;
  int vogais=0;
  cin.get(a,20);
  cout << "Digite um caractere: ";
  cin >> c;
  for(int i=0; i<= strlen(a); i++) {
    if(a[i]=='a' || a[i]=='e'|| a[i]=='i' || a[i]=='o' || a[i]=='u') { 
      vogais +=1;
      a[i] = c;
    }
  }
    cout << vogais << "\n";
    cout << a;
  return 0;
}