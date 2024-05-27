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

vi in[212345];
vi out[212345];
map<vi, int> f;

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (a + 1 != b) {
            in[a+1].pb(i);
            out[b].pb(i);
        }
    }

    vi atual = vi(n+1);

    for (int i = 1; i <=n; i++) atual[i] = 0;

    int resp = 0;
    for (int i = 1; i<=n-1; i++){
        for(int x : in[i]) atual[x] = 1;
        for(int x : out[i]) atual[x] = 0;

        f[atual]++;
        resp = max(resp, f[atual] + 1);
    }

    cout << resp << endl;
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