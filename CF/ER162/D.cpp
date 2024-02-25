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

int a[312345];
int psa[312345];
int resp[312345];
int antdif[312345];
int proxdif[312345];
set<int> cj;

void solve() {
    int n;
    cin >> n;

    psa[0] = 0;
    cj.clear();
    cj.insert(0);
    for(int i = 1; i <=n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
        cj.insert(psa[i]);
        if (a[i] != a[i-1]) antdif[i] = i-1;
        else antdif[i] = antdif[i-1];
    }
    for(int i =n; i>=1; i--) {
        if (a[i] != a[i+1]) proxdif[i] = i+1;
        else proxdif[i] = proxdif[i+1];
    }

    for (int i = 1; i <=n; i++) {
        resp[i] = INF;
        if (psa[i-1] - a[i] <= 0) continue;

        auto it = cj.upper_bound(psa[i-1] - a[i]);
        // cout << (*it) << ' ';
        it--;
        // cout << (*it) << ' ' << i - distance(cj.begin(), it) - 1 << endl;
        resp[i] = i - distance(cj.begin(), it) - 1;
        if (a[i] == a[i-1]) {
            if (antdif[i-1] != 0) resp[i] = max( i-1 - antdif[i-1] + 1, resp[i]);
            else resp[i] = INF;
        }
    }

    // for(int i = 1; i<=n; i++) {
    //     if (resp[i] != INF) cout << resp[i] << ' ';
    //     else cout << -1 << ' ';
    // }
    // cout << endl;

    cj.clear();
    cj.insert(0);
    psa[n+1] = 0;
    for(int i = n; i >=1; i--) {
        psa[i] = psa[i+1] + a[i];
        cj.insert(psa[i]);
    }

    for (int i = 1; i <=n; i++) {
        // resp[i] = INF;
        if (psa[i+1] - a[i] <= 0) continue;

        auto it = cj.upper_bound(psa[i+1] - a[i]);
        it--;
        int x =  1+n-i - distance(cj.begin(), it) - 1;
        if (a[i] == a[i+1]) {
            if (proxdif[i+1] != n+1) x = max(x, proxdif[i+1] - i);
            else x=INF;
        }
        resp[i] = min(resp[i], x);
    }

    for(int i = 1; i<=n; i++) {
        if (resp[i] != INF) cout << resp[i] << ' ';
        else cout << -1 << ' ';
    }
    cout << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

