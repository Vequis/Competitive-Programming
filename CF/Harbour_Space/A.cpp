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

    int x, y;
    int n;
    int t;
    cin >> t;

    while(t--) {
        cin >> x >> y >> n;

        if (y-x < n*(n-1)/2) {
            cout << -1 << endl;
        } else {
            int cont = n-1;

            cout << x << ' ';
            cout << y - n*(n-1)/2 + cont << ' ';
            int atual = y - n*(n-1)/2 + cont;
            cont--;

            for (int i = 3; i <= n; i++) {
                atual+=cont;
                cout << atual << ' ';
                cont--;
            }
            cout << endl;
        }
    }

    return 0;
}
