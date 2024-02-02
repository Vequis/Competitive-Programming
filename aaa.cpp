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

int m;

bool cmp(int a, int b) {
    return a%m < b%m;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> m >> n;

        vi v;
        for(int i =0 ; i < n; i++) {
            int a;
            cin >> a;
            v.pb(a);
        }


        // for (int x : v) cout << x << ' ';
        // cout << endl;
        sort(all(v), cmp);


        int itr = 0;
        for (int i = 0; i < m; i++) {
            cout << i;

            while(itr < sz(v) and v[itr]%m == i) {
                cout << " -> " << v[itr];
                itr++;
            }

            cout << " -> " <<  '\\' << endl;
        }
        cout << endl;

    }

    return 0;
}
