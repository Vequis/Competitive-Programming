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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int a[212345];
int b[212345];

void solve() {
    int n;
    cin >> n; 
    
    for (int i =1 ; i<=n-1; i++) cin >> a[i];

    for (int i = 1; i <=n; i++) {
        b[i] = b[i-1] + a[i-1];
    }   

    for (int i = 1; i<=n-1; i++) {
        for (int j = i+1; j <=n; j++) {
            cout << b[j] << ' ';
            b[j] -= a[i];
        }
        cout << endl;

    }
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}