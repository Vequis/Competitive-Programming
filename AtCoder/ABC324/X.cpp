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

vi v;

signed main(){_

    int n;
    cin >> n;
    int m;
    cin >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.eb(a);
    }

    sort(all(v));

    int resp = 0;
    for(int i = 0; i < n-m; i++) {
        // cout << i << ' ' << 2*(n-m) - 1 - i <<  endl;
        resp += (v[i] + v[2*(n-m) - 1 - i])*(v[i] + v[2*(n-m) - 1 - i]);
    }

    for(int i = 2*(n-m); i< n; i++) {
        // cout << i << endl;
        resp += v[i]*v[i];
    }

    cout << resp << endl;

    return 0;
}
