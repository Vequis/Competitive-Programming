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

double area(int h1, int h2, int b){
    return (h1+h2)*b/2.0;
}

int n;
int h[11234];

signed main(){_

    double resp = 0;

    cin >> n;

    for(int i=0; i<=n; i++){
        cin >> h[i];
    }

    for(int i=1; i<=n; i++){
        int base;
        cin >> base;
        resp+=area(h[i-1], h[i], base);
    }

    cout << fixed;
    cout << setprecision(1) << resp << endl;

    return 0;
}
