#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int h[n];
    int var=1;

    for(int i=0;i<n;i++){
        cin>>h[i];
    }

    for(int i=1;i<=n-2;i++){
        if ((h[i-1]>h[i])and(h[i+1]>h[i])) var=0;
    }
    if (var==0) cout << "S" << endl;
    else cout << "N" << endl;
    return 0;
}
