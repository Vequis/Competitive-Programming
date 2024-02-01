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

int a[112345];
int b[112345];


signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n, p;

        cin >> n >> p;

        for(int i = 0; i < n; i++) {
            cin >> a[i+1];
        }
        vii v;

        
        for(int i = 0; i < n; i++) {
            cin >> b[i+1];
            v.eb(b[i+1], a[i+1]);
        }
        v.eb(p, n+1);

        sort(all(v));


        int rest = n-1;
        int custo = p;

        int itr = -1;
        while(rest > 0) {
            itr++;

            // cout << rest << ' ' << v[itr].sc << ' ' << custo << endl;
            custo += min(v[itr].sc, rest)*v[itr].fs;
            rest -= min(v[itr].sc, rest);
        }

        cout << custo << endl;

    }

    return 0;
}
