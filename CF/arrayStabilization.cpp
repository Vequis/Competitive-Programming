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

int t;
int n;
int a[212345];
int b[212345];

int mdc(int a, int b){ 
    if (b > a) swap(a, b);
    if (b== 0) return a;
    return mdc(b, a%b);
}

signed main(){_

    cin >> t;
    while(t--) {
        cin >> n;

        for(int i = 1; i <=n; i++) cin >> a[i];

        int acum = -1;

        int geral = a[1];

        for(int i = 2; i <=n; i++) geral = mdc(geral, a[i]);
        for(int i = 1; i <=n; i++) a[i] /= geral;

        bool ehtudo1 = true;
        for(int i = 1; i <=n; i++) ehtudo1 = ehtudo1 and (a[i] == 1);
        if(ehtudo1) {
            cout << 0 << endl;
            continue;
        }

        for(int i = 1; i <=n - 1; i++) b[i] = mdc(a[i], a[i+1]);
        b[n] = mdc(a[n], a[1]);

        // for(int i = 1; i <=n; i++) cout << b[i] << ' ';
        // cout << endl;

        vi ones;
        int cur = 0;
        int resp = 0;
        for(int i = 1; i <=n; i++) {
            if (acum == -1) {
                acum = b[i];
            } else {
                acum = mdc(acum, b[i]);
            }

            if (acum == 1) {
                resp = max(resp, cur);
                cur = 0;
                acum = -1;
                ones.pb(i);
            } 

            if (b[i] != 1) cur++;
        }

        for(int i = 1; i <=n; i++) {
            if (acum == -1)
                break;

            acum = mdc(acum, b[i]);

            if (acum == 1) {
                resp = max(resp, cur);
                break;
            } 
        }

        cout << resp + 1 << endl;
    }



    return 0;
}
