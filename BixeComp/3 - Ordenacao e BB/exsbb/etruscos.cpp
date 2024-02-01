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

ll n, num;

ll bb(ll num){
    ll ini=0, fim= INT_MAX, mid;
    while(ini < fim){
        mid = ini + (fim-ini)/2;
        ll atual = mid;
        atual *= mid+1;
        atual/=2;
        // cout << ini << ' ' << mid << "* " << atual << ' ' << fim << endl;
        if ( atual > num) fim = mid;
        else ini = mid+1;
    }

    return ini-1;
}

int main(){_

    cin >> n;

    while(n--){
        cin >> num;

        cout << bb(num) << endl;
    }

    return 0;
}