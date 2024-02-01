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

int pma[212345];
int psa[212345];
int l[212345];

int a[212345];

int trivial = 0;
int mult(int a, int b, int lim) {
    if (a*b >= lim) trivial = 1;
    return (a*b)%MODN;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vi not1;

        pma[0] = 1;
        psa[0] = 0;

        trivial = 0;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];

            if(a[i] > 1) not1.pb(i);
            psa[i] = psa[i-1] + a[i];
            pma[i] = mult(pma[i-1], a[i], 2*n);
        }

        if(trivial) {
            int ini = 1;
            int fim = n;
            while(a[ini] == 1) ini++;
            while(a[fim] == 1) fim--;

            // cout << '*' << ini << ' ' << fim << endl;
            cout << ini << ' ' << fim << endl;
            continue;
        }

        int ganho = -1;
        ii resp = {1, 1};


        for(int i = 0; i < sz(not1); i++) {

            for(int j = i+1; j < sz(not1); j++) {

                // cout << '&' << i << ' ' << j << endl;

                int cur = (pma[not1[j]] / pma[not1[i] - 1]) - (psa[not1[j]] - psa[not1[i]-1]);

                // cout << cur << endl;

                if (cur > ganho and cur > 0) {
                    ganho = cur;
                    resp = make_pair(not1[i], not1[j]);
                }
            }
        }

        cout << resp.fs << ' ' << resp.sc << endl;
    }

    return 0;
}
