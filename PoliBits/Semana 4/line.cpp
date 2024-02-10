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
        int n;
        cin >> n;
        vi delta;

        int resp = 0;

        for(int i = 1; i <=n; i++) {
            int l = i - 1;
            int r = n - i;

            char c;
            cin >> c;

            if (c == 'L') {
                delta.eb(max(0LL, r - l));
                resp += l;
            } else {
                delta.eb(max(0LL, l - r));
                resp += r;
            }
        }

        sort(delta.rbegin(), delta.rend());
        // cout << delta[0] << endl;


        for(int i = 1; i <= n; i++) {
            resp += delta[i-1];
            cout << resp << ' ';
        }
        cout << endl;
    }

    return 0;
}
