#include <bits/stdc++.h>
using namespace std;

int sumacif(int x) {
  int sum;
  while (x!=0) {
    sum=sum+x%10;
    x/=10;
  }
  return sum;
}

int profundidad(int p) {
  if(p==9) return 1;
  return profundidad(sumacif(p)) + 1;
}

int sumadecifras(string s) {
  int x;
  int suma;
  for (int i=0;i<s.size();i++) {
    x=s[i]-'0';
    suma=suma+x;
  }
  return suma;
}

int main() {
  string s;
  cin >> s;
  int x = sumadecifras(s);
  if(x%9!=0)cout<<0;
  else cout<<profundidad(x)+1;
  
  return 0;
}
