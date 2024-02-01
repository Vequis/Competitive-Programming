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
// #define int long long -> solução divina?

using namespace std;

ll t, n, x, k;
ll resp;

int main(){_

    cin >> k;

    while(k--){
        cin >> n >> x >> t;

        resp = t/x;
        resp*=n;

        cout << resp << endl;
        resp -= (t/x)*(t/x + 1)/2;

        if(n < t/x){
            resp+=(t/x - n)*(t/x - n +1)/2;
        } 
        cout << resp << endl;
    }

    return 0;
}
