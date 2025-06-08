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

int a[212345];
int b[212345];

void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <=n;  i++) cin >> a[i];
    for (int i = 1; i <=n; i++) cin >> b[i];

    if (a[n] == b[n]) {
        cout << n << endl;
        return;
    }

    set<int> acumuladao;
    for (int i = n-1; i>=1; i--) {
        if (acumuladao.find(a[i]) != acumuladao.end() or acumuladao.find(b[i]) != acumuladao.end() or a[i] == a[i+1] or b[i] == b[i+1] or a[i] == b[i]) {
            cout << i << endl;
            return;
        }

        acumuladao.insert(a[i+1]);
        acumuladao.insert(b[i+1]);
    }

    cout << 0 << endl;
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