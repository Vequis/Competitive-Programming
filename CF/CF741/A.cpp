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

int l, r, resp;

signed main(){_
    
    int t;
    cin >> t;
    while(t--){
        cin >> l >> r;

        //5 -> 2 e 3 resp: 2 = (n-1)/2
        // 4 -> 1 e 3 resp: 1 = (n-1)/2

        if (r >= 2*l-1){
            cout << (r-1)/2 << endl;
        } else {
            cout << r%l << endl;
        }
    }
    return 0;
}
