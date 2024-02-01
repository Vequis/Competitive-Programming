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

signed main(){_

    vi v;
    int n;
    while(cin >> n) {
        int q;
        cin >> q;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.pb(a);
        }

        while(q--) {
            int k;
            cin >> k;
            int a;
            cin >> a;

            int cont = 0;
            for(int i = 0; i < n; i++) {
                if(v[i] == a) cont++;

                if(cont == k) {
                    cout << i+1 << endl;
                    break;
                }

                if (i == n-1) {
                    cout << 0 << endl;
                }
            }


        }
    }

    return 0;
}
