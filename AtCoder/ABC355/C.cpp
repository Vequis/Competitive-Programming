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
#define int long long // -> solução divina

using namespace std;

bool grid[2123][2123];

int n;
int lin(int x){ return (x+n-1)/n;}
int col(int x){ return (x-1)%n + 1;}

int confere_linha(int l) {
    for (int i = 1; i<=n; i++) if (!grid[l][i]) return false;
    return true;
}

int confere_col(int l) {
    for (int i = 1; i<=n; i++) if (!grid[i][l]) return false;
    return true;
}

int confere_diagonais() {
    int flag = 1;
    for (int i = 1; i <=n; i++) if (!grid[i][i]) flag = false;

    if (flag) return true;

    for (int i = 1; i <=n; i++) if (!grid[i][n+1-i]) return false;
    return true;
}

void solve() {
    
    int t;
    cin >> n >> t;

    for (int i = 1; i <=t; i++) {
        int x;
        cin >> x;
        grid[lin(x)][col(x)] = 1;

        if (confere_col(col(x)) or confere_linha(lin(x)) or confere_diagonais()) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;

}


signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}