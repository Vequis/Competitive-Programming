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

int a[212345];

void solve() {

    int n;
    cin >> n;

    int x = 0;
    int contmaior= 1;
    for(int i = 1; i <=n; i++) {
        cin >> a[i];
        x = x xor a[i];
        // while( (1<<contmaior) <= a[i] ) contmaior++;
    }
    int resp = x;
    // while( (1<<contmaior) <= x ) contmaior++;


    for(int i = 1; i <=n; i++) {
        int c = (x xor a[i]);
        int b = a[i];
        
        int cur = 0;
        int sobra = 0;
        for(int j = 62; j>=0; j--) {
            sobra*=2;
            if (c & (1LL << j)) cur += (1LL << j);
            if (b & (1LL << j)) sobra++;

            if (!(c & (1LL << j)) and sobra > 0 and j > 0) {
                cur += (1LL<<j);
                sobra--;
            }

            if (j == 0 and b & 1LL and !(c & (1LL << j))) cur+=1;

            // cout << '%' << j << ' ' << cur << endl;
        }

        if ((x xor a[i]) & 1 == 1 and a[i] & 1 == 1) cur--;

        // cout << '*' << c << ' ' << b << ' ' << cur << endl;

        resp = max(resp, cur);
        // cout << '*' << cur << endl;
    }

    cout << resp << endl;



}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
