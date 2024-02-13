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

int v[212345];
map<int, int> f;

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        f[v[i]]++;
    }

    int ptrini = 0;
    int ptrfim = n-1;

    if (v[ptrini] == v[ptrfim]) {
        while( ptrini != n-1 and v[ptrini] == v[0]) ptrini++;
        while( ptrini != n-1 and v[0] == v[ptrfim]) ptrfim--;

        if(n-1 == ptrini) cout << 0 << endl;
        else
        cout << ptrfim - ptrini + 1 <<  endl;
    } else {
        ptrini++;
        while(v[ptrini] == v[ptrini - 1]) ptrini++;
        
        ptrfim--;
        while(v[ptrfim] == v[ptrfim+1])ptrfim--;

        cout << min(n - 1 - ptrini + 1, ptrfim - 0 + 1) << endl;

    }
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
