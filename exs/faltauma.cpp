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
#define MAXX 1073741823

using namespace std;

int fact(int n){
    if (n==1) return 1;
    return n*fact(n-1);
}

int matriz[9][9];
int n, cartas;

int main(){_

    cin >> n;

    cartas = fact(n) - 1;

    for (int i=0; i<cartas; i++){
        for (int j=1; j<=n; j++){
            int x;
            cin >> x;
            matriz[x][j]++;
        }
    }

    cartas = fact(n-1);

    for (int j=1; j<=n; j++){
        for (int i=1; i<=n; i++){
            if (matriz[i][j] == cartas - 1) {
                cout << i << ' ';
                break;
            }
        }
    }

    cout << endl;

    return 0;
}