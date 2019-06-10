#include <bits/stdc++.h>
using namespace std;
int giros[20];
vector<int>mask[40000];
int suma;
int main(){
   int n;
   string flag="NO";
    int a[16];

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    int limit=pow(2,n);
    for (int i=0;i<limit;i++){
            int divis=i;
            int suma=0;
        for(int j=0;j<n;j++){
            mask[i].push_back((divis%2)*2-1);
            divis/=2;
        }
    for(int j=0;j<n;j++){
        suma=suma+mask[i][j]*a[j];
    }
    if (suma%360==0){
     flag="YES";
     break;
    }
    }
    cout<<flag;
    return 0;
}
