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
#define maxn

using namespace std;

vi v;

int f(int x) {
    return (x*(x-1))/2;
}

int bb(int x){
    int ini = 0, fim = 1500000000, mid;

    while(ini<fim) {
        mid = ini + (fim-ini)/2;
        // if(v[mid] == x) return mid;
        if (f(mid) > x) fim = mid;
        else ini = mid + 1;

        // cout << x << ' ' << f(mid) <<  ' ' << fim << ' ' << mid << ' ' << ini << endl;
    }

    return ini;

    return -1;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        int resp = bb(n) - 1;
        cout << resp + n - f(resp) << endl;


    }

    return 0;
}

