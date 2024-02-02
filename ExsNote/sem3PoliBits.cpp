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
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long //-> solução divina?

using namespace std;

int grid[100][100];
int visitados[100][100];    

queue<ii> fila;

int expo (int a, int b) {
    int resp = 1;
    int temp = a;
    while(b > 0) {

        if (b & 1) resp*=temp;
    
        temp *= temp;

        b/=2;
    }

    return resp;
}

signed main(){_

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int resp = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            grid[i][0] += grid[i][j];
            grid[0][j] += grid[i][j];
        }
    }

    for (int i = 1; i<= n; i++) {
        resp += expo(2, grid[i][0]) - 1 + expo(2, m - grid[i][0]) - 1;
    }

    for (int i = 1; i<= m; i++) {
        resp += expo(2, grid[0][i]) - 1 + expo(2, n - grid[0][i]) - 1;
    }

    resp -= n*m;

    cout << resp << endl;

    return 0;
}
