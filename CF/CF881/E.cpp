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
// #define int long long // -> solução divina

using namespace std;

void op(int n) {

}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vii segs;

        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            segs.eb(a, b);

        }

        sort(all(segs));

        int cont[112345];

        for(int i = 0; i < m; i++) {
            cont[i] = (segs[i].sc - segs[i].fs + 1) / 2 + 1;
        }

        int q;
        cin >> q;

        int ini = 0;
        int fim = q+1;

        int quer[112345];
        for(int i = 0; i < q; i++) cin >> quer[i];

        int resptemp = 0;
        while(ini < fim) {
            int mid = ini + (fim- ini)/2;
            resptemp = 0;

            int temp[112345];
            int psa[112345];

            psa[0] = 0;
            for(int i = 1; i <= n; i++) temp[i] = 0;
            for(int i = 0; i < mid; i++) temp[quer[i]] = 1;
            for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + (temp[i] == 1); 

            for(int i = 0; i < m; i++) {
                if (psa[segs[i].sc] - psa[segs[i].fs - 1] >= cont[i]) {
                    // cout << '*' << segs[i].sc << ' ' << segs[i].fs << endl;
                    // cout << '*' << psa[segs[i].sc] << ' ' << psa[segs[i].fs - 1] << endl;
                    resptemp = 1;
                    break;
                }
            }


            // cout << ini << ' ' << mid << ' ' << fim << endl;
            if (resptemp == 1) fim = mid;
            else ini = mid+1;
        }
        // cout << ini << ' ' << fim << endl;
        
        if(ini == q+1) cout << -1 << endl;
        else cout << ini << endl;

    }

    return 0;
}
