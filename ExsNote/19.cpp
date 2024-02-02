#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int peE[31];
    int peD[31];
    int corretos=0;

    for (int i=0;i<31;i++){
        peE[i]=0;
        peD[i]=0;
    }

    for (int i=0;i<n;i++) {
        int tam;
        string lado;
        cin >> tam >> lado;
        if (lado=="E") {peE[tam-30]+=1;}
        else           {peD[tam-30]+=1;}
    }

    for (int i=0;i<31;i++){
        corretos += min(peE[i],peD[i]);
    }

    cout << corretos << endl;
    return 0;
}
