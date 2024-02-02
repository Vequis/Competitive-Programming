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
#define int long long

using namespace std;

signed main(){_

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vi a;

        for (int i = 0; i < n; i++){
            int num;
             cin>> num;
             a.pb(num);
        }

        vi b;
        b.pb(a[0]);
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                b.pb(a[i]);
            }
            b.pb(a[i]);
        }

        cout << b.size() << endl;
        for (int x : b) cout << x << ' ';
        cout << endl;
    }

    return 0;
}
