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

void solve() {

    int n;
    cin >> n;

    vi v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.eb(a);
    }
    while(v[sz(v) - 1] == 0) v.pop_back();

    int ant = 0;
    for (int i = 0; i < sz(v); i++) {
        int dif = v[i] + ant;
        if (i!=0) dif++;

        // cout << i << ' ' << dif << endl;

        if (dif < 0) {
            cout << "No" << endl;
            return;
        } else if (dif == 0 and i!=sz(v) - 1) {
            cout << "No" << endl;
            return;
        }

        if (i == sz(v) - 1 and dif != 0) {cout << "No" << endl; return;} 
        ant = dif-1;
    }


    cout << "Yes" << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
