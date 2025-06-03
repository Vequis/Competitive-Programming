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

int fib[112];

void solve() {
    int n, m;
    cin >> n >> m;

    string resp = "";
    while(m--) {
        int w, h, l;
        cin >> w >> h >> l;
        int maximo = max(max(w, h), l);
        int minimo = min(min(w, h), l);
        if (maximo >= fib[n] + fib[n-1] and minimo >= fib[n]) cout << '1';
        else cout << '0';
    }
    cout << endl;

}

signed main(){_
    int t;
    cin >> t;
    // t=1;
    fib[1] = 1;
    fib[2] = 2;

    for (int i = 3; i <= 15; i++) fib[i] = fib[i-1] + fib[i-2]; 

    while(t--) {
        solve();
    }

    return 0;
}