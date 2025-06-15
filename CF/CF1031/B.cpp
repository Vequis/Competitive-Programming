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
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    int x1l = x1 + a;
    int y1l = y1 + b;

    if (((x1-x2) % a == 0 and x1 != x2) or ((y1-y2) % b == 0) and y1!=y2) {
        cout << "Yes" << endl;
    }  else {
        cout << "No" << endl;
    }

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