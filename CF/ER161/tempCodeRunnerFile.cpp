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

int a[1123456];

int prox[112345];

void solve() {

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    prox[1] = 2;
    prox[n] = n-1;

    for(int i = 2; i < n; i++) {
        if (a[i+1] - a[i] < a[i] - a[i-1]) prox[i] = i+1;
        else prox[i] = i-1;
    }

    int m;
    cin >> m;

    while(m--) {
        int x, y;
        cin >> x >> y;
        int desc = (x > y);

        int resp = 0;
        if (!desc) {

            for(int i = x; i <= y-1; i++) {
                if (prox[i] == i+1) resp++;
                else resp += a[i+1] - a[i];
            }

        } else {
            for(int i = x; i >= y+1; i--) {
                if (prox[i] == i-1) resp++;
                else resp += a[i] - a[i-1];
            }

        }
        cout << resp << endl;
    }
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
