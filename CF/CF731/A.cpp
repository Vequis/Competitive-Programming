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

int xa, ya, xb, yb, resp, xf, yf;
int q;

signed main(){_

    cin >> q;

    while(q--){
        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xf >> yf;

        resp = abs(xa-xb) + abs(ya-yb);

        if(xa==xb and xa==xf and yf<=max(ya,yb) and yf>=min(ya,yb)) resp+=2;
        if(ya==yb and ya==yf and xf<=max(xa,xb) and xf>=min(xa,xb)) resp+=2;
    
        cout << resp << endl;
    }

    return 0;
}
