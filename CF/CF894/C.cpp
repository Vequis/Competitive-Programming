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
#define maxn

using namespace std;

vi v;

int bb(int x){
    int ini = 0, fim = sz(v), mid;

    while(ini<fim) {
        mid = ini + (fim-ini)/2;
        // if(v[mid] == x) return mid;
        if (v[mid] < x) fim = mid;
        else ini = mid + 1;

        // cout << x << ' ' << fim << ' ' << mid << ' ' << ini << endl;
    }

    return ini;

    return -1;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.pb(a);
        }

        int resp = 1;

        for (int i = 1; i <= n; i++) {
            if (bb(i) != v[i - 1]) resp = 0;
        }

        if (resp) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        v.clear();
    }

    return 0;
}

