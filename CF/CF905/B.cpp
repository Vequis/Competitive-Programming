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

int v[112345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int k;
        cin >> k;

        int resp = INF;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            resp = min(resp, (k - (a)%k));

            if (a%k == 0) resp = 0;
            v[i] = a;
        }

        int resp2 = INF;

        if (k == 4) {

            int contpar = 0;
            for(int i = 0; i < n; i++) {
                if (v[i] %2 == 0) contpar++;
            }

            if(contpar >= 2) resp2 = 0;
            if (contpar == 1 and n > 1) resp2 = 1;
            if (contpar == 0 and n > 1) resp2 = 2;
        }

        cout << min(resp, resp2) << endl;
    }

    return 0;
}
