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

    int n;
    cin >> n;

    string a, b, c;
    cin >> a >> b >> c;

    int resp = INF;

    for(int i = 0; i <= 9; i++) {
        
        int cur = -1;
        int cont = 0;

        vi va, vb, vc;

        for(int j = 0; j < n; j++) {
            if (a[j] == (char)('0' + i)) va.pb(j);
            if (b[j] == (char)('0' + i)) vb.pb(j);
            if (c[j] == (char)('0' + i)) vc.pb(j);
        }

        va.pb(INF);
        vb.pb(INF);
        vc.pb(INF);
 
        if(va[0] == INF and vc[0] == INF and vb[0] ==INF){
            cur = INF;
        } else if (vc[0] == INF and vb[0] ==INF) {
            cur = 3*va[0] + 3*n;
        } else if (vc[0] == INF and va[0] ==INF) {
            cur = 3*vb[0] + 3*n;
        } else if (va[0] == INF and vb[0] ==INF) {
            cur = 3*vc[0] + 3*n;
        } else if (vc[0] == INF) {
            
            int cur = 0;
            int cont = 0;
            int used[3];

            while(cont < 3) {
                used[0] = used[1] = used[2] = 0;

                for(int j = 0; j < n; j++) {
                    if (a[j] )
                }
            }
        }

        resp = min(resp, cur);
    }

    if(resp == INF) {
        cout << -1 << endl;
    } else {
        cout << resp << endl;
    }

    return 0;
}
