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

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vi v;
        for (int i = 0; i < n*(n-1)/2; i++) {
            int a;
            cin >> a;
            v.pb(a);
        }

        sort(all(v));

        // for (int i = 0; i < n*(n-1)/2; i++) {
        //     cout << v[i];
        // }

        int idx = 0;
        for (int i = n-1; i>0; i--) {
            cout << v[idx] << ' ';
            idx += i;
        }

        cout << v[sz(v) -1 ] << endl;
    }

    return 0;
}
