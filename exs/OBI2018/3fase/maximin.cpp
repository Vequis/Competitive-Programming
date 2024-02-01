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

int a[112345];

signed main(){_

    int n, l, r;
    cin >> n >> l >> r;

    int resp = 0;

    for(int i=1; i<=n; i++) cin >> a[i];

    sort(a+1, a+n+1);

    if(l < a[1]) resp = 2*(a[1] - l);
    if(a[n] < r) resp = 2*max(resp, r - a[n]);

    int ind_l = -1, ind_r = -1;
    for(int i=2; i<=n; i++) {
        if(a[i] < l) {
            if(ind_l == -1){
                resp = max(resp, 2*min(a[i] - l, l - a[i-1]));
                ind_l = i;
                continue;
            }
            continue;
        } else if (a[i] > r) {
            resp = max(resp, 2*min(a[i] - r, r - a[i-1]));
            ind_r = i;
            break;
        }
        resp = max(a[i] - a[i-1], resp);
    }

    // resp = max(resp, a[1] - l);
    // resp = max(resp, r - a[n]);

    cout << resp/2 << endl;

    return 0;
}
