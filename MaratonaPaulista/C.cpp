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
    int x, y;
    cin >> x >> y;

    if (x <= -100 and x>=-200 and y>=0 and y<=100 and y<=x+200) {
        cout << "S" << endl;
        return;
    } else if (x >= -100 and x<= 0 and y>=0 and y<=100) {
        cout << "S" << endl;
        return;
    } else if (x >= -100 and x<= 0 and y>=-100 and y<=0 and y >= -x - 100) {
        cout << "S" << endl;
        return;
    } else if (x >= 0 and x<= 100 and y>=0 and y<=100 and y<=-x + 100) {
        cout << "S" << endl;
        return;
    } else if (x >= 0 and x<= 100 and y>=-100 and y<=0) {
        cout << "S" << endl;
        return;
    } else if (x >= 100 and x<= 200 and y>=-100 and y<=0 and y >= x-200) {
        cout << "S" << endl;
        return;
    }

    cout << "N" << endl;
    return;
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