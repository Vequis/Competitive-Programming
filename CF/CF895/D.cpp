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

int mdc(int a, int b){ 
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b) {
    return (a*b)/mdc(a,b);
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int x, y;
        cin >> x >> y;
        int var = mmc(x, y);

        int contM = (n/x) - (n/mmc(x, y));
        int contMenor = (n/y) - (n/mmc(x, y));

        int resp = 0;

        // cout << contM << ' ' << contMenor << endl;

        resp += n*(n+1)/2;
        // cout << resp << endl;
        resp -= (n-contM)*(n-contM+1)/2;
        // cout << resp << endl;

        resp-= ((contMenor)*(contMenor+1))/2;
        cout << resp << endl;
    }

    return 0;
}
