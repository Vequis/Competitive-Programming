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
        int a, b, c;
        int al, bl, cl;
        cin >> a >> b >> c;

        al = max(max(a, b), c);
        cl = min(min(a, b), c);

        bl = a xor b xor c xor al xor cl;
        // cout << al << bl << cl << endl;

        int respa = 100*al + 10*bl + cl;
        
        cin >> a >> b >> c;

        al = max(max(a, b), c);
        cl = min(min(a, b), c);

        bl = a xor b xor c xor al xor cl;


        int respb = 100*al + 10*bl + cl;

        if (respa > respb) {
            cout << "Alice" << endl;
        } else if (respa < respb) {
            cout << "Bob" << endl;
        } else {
            cout << "Tie" << endl;
        }
    }

    return 0;
}
