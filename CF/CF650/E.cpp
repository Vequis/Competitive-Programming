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
//Solving it 5 years later!!

// or ans = 1
// or ans = max(f[a[i]])
// divide cada a[i] por k

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, int> f;
    for (char c : s) {
        f[c]++;
    }

    int resp = min(k, n);
    for (int i = 2*k; i <= n; i+=k) {
        int mult = i/k;
        int cont = 0;

        for (ii p : f) {
            cont += p.sc/mult;
        } 

        if (cont >= k) resp = max(resp, i);
    }

    cout << resp << endl;
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}