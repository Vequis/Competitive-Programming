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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int n, m, u, v, w;
int adj[MAX][MAX];

int main(){_

    cin >> n >> m;

    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << adj[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}