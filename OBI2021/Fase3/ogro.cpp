#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    cin >> n;

    if(n==0){
        cout << "*" << endl;
        cout << "*" << endl;
    } else if(n<=5){
        for(int i=1; i<=n; i++) cout << "I";
        cout << endl;
        cout << "*" << endl;
    } else {
        cout << "IIIII" << endl;
        for(int i=6; i<=n; i++) cout << "I";
        cout << endl;
    }
}
