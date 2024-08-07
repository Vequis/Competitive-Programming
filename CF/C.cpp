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

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int a[1123];

        for(int i = 1; i <=n; i++) {
            cin >> a[i];
        }

        int resp = 0;

        for(int i = 1; i <=n; i++) {
            int cur = 0;
            int itr = i-1;

            int maxat = a[i];

            while( cur <= k and itr >= 1) {
                if(itr==i-1)maxat--;
                maxat++;

                int var = a[i] + (i - itr) - a[itr];
                if( var > 0) cur += var;

                // cout << '*' << i << ' ' << cur << ' ' << maxat << endl;

                itr--;
            }

            if(cur <= k) maxat++;
            if(i == 1) maxat--;

            cout << maxat << endl;
            resp = max(resp, maxat);
        }

        cout << resp << endl;
    }

    return 0;
}
