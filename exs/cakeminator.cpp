#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int

using namespace std;

vector< vi > matriz(12, vi(12));

int r, c;

int main(){_

    cin >> r >> c;

    for (int i=1; i<=r; i++){
        string st;
        cin >> st;
        for (int j=1; j<=c; j++){
            matriz[i][j] = st[j-1];
            if (st[j-1] == 'S'){
                matriz[i][0] = 1;
                matriz[0][j] = 1;
            }
        }
    }

    int somaR = 0;
    int soma = 0;
    for (int i=1; i<=r; i++){
        if (matriz[0][i] == 0) somaR ++;
    }

    soma+= somaR*c;

    for (int i=1; i<=c; i++){
        if (matriz[i][0] == 0) soma += r-somaR;
    }

    cout << soma << endl;

    return 0;
}