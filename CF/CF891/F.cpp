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
#define int long long

using namespace std;

vi v;

int bb(int x){
    int ini = 0, fim = sz(v), mid;

    while(ini<fim) {
        mid = ini + (fim-ini)/2;
        if(v[mid] == x) return mid;
        else if (v[mid] > x) fim = mid;
        else ini = mid + 1;
    }

    return -1;
}

int bbsqrt(int x){
    int ini = 0, fim = 2111222333, mid;

    while(ini<fim) {
        mid = ini + (fim-ini)/2;
        if(mid*mid == x) return mid;
        else if (mid*mid > x) fim = mid;
        else ini = mid + 1;
    }

    return -1;
}

map<int, int> f;

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
            f[a]++;
        }

        int q;
        cin >> q;

        sort(all(v));

        while(q--) {
            int x,y;
            cin >> x >> y;

            int resp = 0;

            int raiz = bbsqrt(x*x - 4*y);
            int a1 = (x - raiz) / 2;
            int a2 = (x + raiz) / 2;

            if (raiz > 0) {
                resp = f[a1]*f[a2];
            } else if (raiz == 0) {
                int fr = f[a1];
                resp = fr*(fr - 1)/2;
            }

            // cout << '*' << x << ' ' << y << ' '<< a1 << ' ' << a2 << ' ' << resp << endl;

            cout << resp << ' ';
        }

        cout << endl;

        f.clear();
        v.clear();
    }

    return 0;
}
