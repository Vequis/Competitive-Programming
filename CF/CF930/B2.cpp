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

string a, b;
int n;
string resposta;

void solve() {

    cin >> n;
    cin >> a >> b;

    int lastfixo = -1;

    for (int i = 0; i < n-1; i++) {
        if (b[i] != a[i+1]) {
            if (b[i] == '1' and a[i+1] == '0') lastfixo = i;
            else {
                cout << a.substr(0, i+1) << b.substr(i, n - i) << endl;
                cout << i - lastfixo << endl;
                return;
            }
        }
    }

    // cout << lastfixo << endl;
    cout << a << b[n-1] << endl;
    cout << n - lastfixo - 1 << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
