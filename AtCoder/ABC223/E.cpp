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

    int  x, y, a, b, c;

    cin >> x >> y >> a >> b >> c;

    int resp = 0;

    for (int i = 1; i <= y; i++) {
        int j = ceil((double)a/(double)i);
    
        if(j > x or j > ) continue;

        // cout << i << ' ' << j << endl;

        if (b <= (i)*(x-j) and c <= (x)*(y-i)) {
            cout << "Yes" << endl;
            return 0;
        }

        if (c <= (i)*(x-j) and b <= (x)*(y-i)) {
            cout << "Yes" << endl;
            return 0;
        }

        for(int k = 1; k <= y-i; k++ ) {
            int h = ceil((double)b/(double)k);
            if(h > x) continue;
            if (c <= (y-k-i)*(x) or c <= (x - max(h, j))*(y)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
