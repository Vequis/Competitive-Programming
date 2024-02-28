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

map<int, int> f;
void solve() {

    int n;
    cin >> n;
    f.clear();
    int soma = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        f[a%3]++;
        soma += a;
    }

    if (soma % 3 == 0) cout << 0 << endl;
    else if (soma %3 == 1) {
        if (f[1] > 0) cout << 1 << endl;
        else cout << 2 << endl;
    } else {
        cout << 1 << endl;
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
