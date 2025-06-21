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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int a[212345];


void solve() {
    int n, k;
    cin >> n >> k;


    multiset<int> s;

    int resp = 0;

    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        s.insert(a[i]);

        resp += a[i] * (a[i] + 1) / 2;
    }

    if (n==1) {
        cout << resp << endl;
        return;
    }

    while(1) {
        int c = *(s.begin());
        int b = *(s.rbegin());

        // cout << b << ' ' << c << endl;
        int delta = k + 1 + c - b;
        s.erase(s.find(b));
        s.erase(s.find(c));

        s.insert(b-1);
        s.insert(c+1);

        if (delta < 0) {
            resp+=delta;
        } else {
            cout << resp << endl;
            return;
        }
    }


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