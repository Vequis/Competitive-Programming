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

ii stats[3123];
int maxh[3123]; // max de vida que da pra ganhar usando m de magia

void solve() {
    int n, h, m;
    cin >> n >> h >> m;

    for (int i = 1; i <=n; i++) {
        int a, b;
        cin >> a >> b;
        stats[i] = {a, b};
    }

    int maxsum = 0; 
    for (int i = 0; i <= 3000; i++) maxh[i] = 0;

    for (int i = 1; i <= n; i++) {
        
        for (int j = 3000; j >= stats[i].sc; j--) {
            maxh[j] = max(maxh[j], maxh[j-stats[i].sc] + stats[i].fs);
        }

        maxsum += stats[i].fs;
        int delta = maxsum - h;

        // cout << maxsum << ' ' << delta << ' ' << maxh[m] << endl;
        if (delta < 0) continue;


        if (maxh[m] + h < maxsum) {
            cout << i-1 << endl;
            return;
        }
    }

    cout << n << endl;
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}