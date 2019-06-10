//tags: brute force
#include <bits/stdc++.h>
using namespace std;

int main(){
  int x[12];
  string s;
  cin>>s;
  int sum=0;

  for (int i=0; i<s.size();i++){
    if(s[i]=='4')x[i]=0;
    else if(s[i]=='7')x[i]=1;
    sum+=pow(2,s.size()-i-1)*x[i];
    }
  for(int i=1; i<s.size();i++)
  {sum+=pow(2,i);}
   cout<<sum+1;
  return 0;
}
