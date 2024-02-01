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

int valid(int a, int b, int c, int x) {
    if (x == 0) return false;
    if (a%x) return 0;
    if (b%x) return 0;
    if (c%x) return 0;


    int var = a/x;
    var += b/x;
    var += c/x;
    if (var - 3 > 3) return false;

    // cout << x << endl;
    return true; 

}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int resp = false;
        int x = a;
        resp = resp or valid(a, b, c, x);
        x = a/2;
        resp = resp or valid(a, b, c, x);
        x = a/3;
        resp = resp or valid(a, b, c, x);
        x = a/4;
        resp = resp or valid(a, b, c, x);
        x = b;
        resp = resp or valid(a, b, c, x);
        x = b/2;
        resp = resp or valid(a, b, c, x);
        x = b/3;
        resp = resp or valid(a, b, c, x);
        x = b/4;
        resp = resp or valid(a, b, c, x);
        x = c;
        resp = resp or valid(a, b, c, x);
        x = c/2;
        resp = resp or valid(a, b, c, x);
        x = c/3;
        resp = resp or valid(a, b, c, x);
        x = c/4;
        resp = resp or valid(a, b, c, x);

        if (resp) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
