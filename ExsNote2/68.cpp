#include <iostream>

using namespace std;

int main() {
     int m,n;
     cin>>m>>n;
     int maxi = max(n,m);
     int x[maxi];
     int y[maxi];
     int z[maxi];

     for (int i=0;i<m;i++){
        cin>>x[i];
     }

    for (int i=0;i<n;i++){
        cin>>y[i];
     }

     if (maxi==m) {
        for (int i=maxi-1;i>=n;i--) {
            y[i]=0;
        }
     } else {
         for (int i=maxi-1;i>=m;i--) {
            x[i]=0;
         }
     }

     z[maxi-1]=0;
     for (int i=maxi-1;i>=0;i--){
        z[i]+=x[i]+y[i];
        if (z[i]>1){
            z[i] -= 2;
            z[i-1]=1;
        } else if (i>0) z[i-1]=0;
     }
     for (int i=0;i<maxi;i++){
        cout << z[i] << " ";
     }
     cout << endl;

     return 0;
 }
