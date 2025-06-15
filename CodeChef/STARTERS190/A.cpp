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

int a[212345];

void solve() {
    int n;
    cin >> n;

    int flag = 0;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];

        if (i > 1 and a[i-1] > a[i]) flag=1;
    }

    if (!flag) {
        cout << 0 << endl;
        return;
    }

    int atual = 0;
    flag = 0;

    while(1) {
        flag = 0;
        for (int i = 1; i <= n; i++) {
            a[i] |= (1<<atual);
            if (i > 1 and a[i-1] > a[i]) flag=1;
        }

        if (!flag) break;
        atual++;
    }

    cout << (1 << atual) << endl;



}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}