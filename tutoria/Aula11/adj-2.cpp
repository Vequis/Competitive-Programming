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
#define vvi vector<vi>
#define vvii vector<vii>
#define endl '\n'
#define ll long long int
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int n, m, u, v, w;
vvii adj;
int main(){_

    cin >> n >> m;

    adj = vvii(n+1);

    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }

    for (vii u : adj) {
        for (ii v : u){
            cout << v.fs << ' ' << v.sc << ' ';
        }
        cout << endl;
    }

    return 0;
}