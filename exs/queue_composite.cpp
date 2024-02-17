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
#define MODN 998244353
#define int long long // -> solução divina

using namespace std;

int p;
int s;
int al[512345];
int be[512345];
int te = 1;
int r = 1;
int pe[512345];

int pcor = 1;

int inv(int x) {
    if (x <= 1) return x;
    return (MODN - ((MODN/x)*inv(MODN%x))%MODN)%MODN;
}

void solve() {
    int op;
    cin >> op;

    if (op == 0) {
        int a, b;
        cin >> a >> b;

        p = (p*a)%MODN;
        s = (s + (b*inv(p))%MODN)%MODN;
        al[te] = a;
        be[te] = b;
        pe[te] = p;
        te++;
    } else if (op == 1) {
        s = (MODN + s - (be[r]*inv(pe[r]))%MODN)%MODN;
        // s = (s*al[r])%MODN;

        // p = (p*inv(al[r]))%MODN;
        pcor = (pcor * inv(al[r]))%MODN;

        r++;
    } else {
        int x;
        cin >> x;
        cout << ( ( ( (p*pcor) %MODN ) *x)%MODN + (p*s)%MODN)%MODN << endl;
    }
}

signed main(){_
    int t;
    cin >> t;

    p = 1;
    s= 0;

    while(t--) {
        solve();
    }

    return 0;
}
