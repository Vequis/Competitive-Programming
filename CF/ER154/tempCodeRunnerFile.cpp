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
        vi inc(212345);
        vi dec(212345);

        int n;
        cin >> n;

        int ant;
        cin >> ant;

        for (int i = 1; i < n; i++) {
            int a;
            cin >> a;

            dec[i] = dec[i-1];
            inc[i] = inc[i-1];
            if (a < ant) dec[i]++;
            if (a > ant) inc[i]++;
            if (a==ant){
                dec[i]++;
                inc[i]++;
            }
            ant = a;
        }

        int resp = INF;
        for (int i = 1; i < n; i++){
            resp = min(resp, min(dec[i], inc[i] + 1) + dec[n-1] - dec[i]);
            // cout << '*' << inc[i] << ' ' << dec[i] << endl;
        }
        cout << resp << endl;
    }

    return 0;
}
