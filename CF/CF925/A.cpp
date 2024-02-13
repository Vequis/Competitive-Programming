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

    int cont = 3;
    char a = 'a';
    char b = 'a';
    char c = 'a';

    while(cont < n) {
        if (c == 'z') {
            cont-=25;
            c = 'a';
            if (b == 'z') {
                cont-=25;
                b = 'a';
                a = (char)(a + 1);
                cont++;
            } else {
                cont++;
                b = (char)(b + 1);
            }
        } else {
            cont++;
            c = (char)(c + 1);
        }
        // cout << a << b << c << endl;
    }

    cout << a << b << c << endl;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
