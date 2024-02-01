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

char s[1111];

int mdc(int a, int b) {
    if(a < b) swap(a, b);
    if(b==0) return a;
    return mdc(b, a%b);
}

int vis[1111];

signed main(){_

    int n;
    cin >> n;

    memset(vis, -1, sizeof(vis));

    for(int j = 1; j <= 9; j++) {
        if (n%j == 0) {

            for(int k = n/j; k<=n; k+=n/j) {
                if (vis[k] == -1) {
                    vis[k] = j;
                }
            }
        }
    }
    for(int i = 0; i <=n; i++) {


        // cout << i << ' ' << y << endl;
        s[i] = '-';
        if (vis[i] != -1) s[i] = (char)('0' + vis[i]);
        s[0] = '1';
        cout << s[i];
    }

    return 0;
}
