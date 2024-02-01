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

int t[1123456];
bool res[1123456];

signed main(){_

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        t[i] = (t[i] + a)%k;
    }

    for (int i = 0; i < n; i++) {
        if (t[i] > n-1 or res[t[i]]) {
            cout << "N" << endl;
            return 0;
        } else {
            res[t[i]] = 1;
        }
    }

    cout << "S" << endl;

    return 0;
}
