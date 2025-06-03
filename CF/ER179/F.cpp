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

int mdc(int a, int b){ 
    if (b > a) swap(a, b);
    if (b==0) return a;
    return mdc(b, a%b);
}

void solve() {

    int p, s;
    cin >> p >> s;

    int g = mdc(p, s);
    p/=g; s/=g;

    for (int x = 0; x <= 50000; x++) {
        for (int y = 0; (x+1)*(y+1)<=50000; y++) {
            int per = 2*(x + y + 2);
            if (per % p) continue;
            int area = (per/p) * s;

            if (x+y+1 <= area and area <= (x+1)*(y+1)) {
                cout << area << endl;

                for (int i = 0; i<=x; i++) cout << i << ' ' << 0 << endl;
                for (int i = 1; i<=y; i++) cout << 0 << ' ' << i << endl;

                area-=(x+y+1);

                int a = 1;
                int b = 1;

                for (int i =1; i<=area; i++) {
                    cout << a << ' ' << b << endl;
                    a++;
                    if (a==x+1) {
                        a = 1;
                        b++;
                    }
                }
                return;
            }
        }
    }   

    cout << -1 << endl;
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