#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int m[10005][3];

int cont_func(long long int n){
    long long int novo;

    if (n==1) {
        return 1;
    }
    if (n%2==0) novo = n/2;
    else novo = 3*n + 1;

    return cont_func(novo) + 1;
}

int main() {

    vector < pair<pair<int,int> ,long long int> > V;

    int cont = -1;

    int mi, ma;
    int ind;
    while (cin >> mi >> ma){
        //cont++;
        //m[cont][0] = mi;
       // m[cont][1] = ma;
        long long int valorMaior = 0;
        for (int i= min(mi,ma); i<=max(ma,mi); i++){
            if (cont_func(i) > valorMaior){
                ind = i;
                valorMaior = cont_func(i);
            }
        }
        V.push_back(make_pair(make_pair(mi,ma), valorMaior));
        //cout << mi << " " << ma << " " << valorMaior << endl;
    }

    for (int i=0; i<V.size(); i++) {
        //cout << m[i][0] << " " << m[i][1] << " " <<  m[i][2] << endl;
        cout << V[i].first.first << " " << V[i].first.second << " " << V[i].second << endl;
    }

    return 0;
}
