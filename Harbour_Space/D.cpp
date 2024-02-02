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

signed main(){

    int t;
    cin >> t;

    while(t--) {_
        int n;
        cin >> n;

        vii ops;

        int cont = 0;

        for (int i = 0; i < n; i++) {

            int psa[4123];

            for (int j = 0; j < n; j++) psa[j] = 0;
        
            for(ii p : ops) {
                int dl = i - p.fs;


                // cout << endl;
                // cout << dl << endl;
                int idx;
                idx = max((int)0, p.sc - dl);
                psa[idx] += 1;
                // cout << i << '*' << ' ' <<  idx;
                idx = min((int)n, p.sc + dl + 1);
                psa[idx] += -1;
                // cout << '*' << idx << endl;
            }

            int acc = 0;
            for (int j = 0; j < n; j++) {
                // cout << psa[j];
                acc+=psa[j];
                int atual = acc%2;
                // cout << atual;
                char c;
                cin >> c;
                if (atual ^ ((int)(c - '0'))) {
                    ops.eb(i, j);
                    cont++;
                }
            }
            // cout << cont << endl;
            // cout << endl;
        }

        cout << cont << endl;
    }

    return 0;
}
