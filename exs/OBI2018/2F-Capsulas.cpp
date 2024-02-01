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

int lo, hi, v, n;
int caps[212345];

int moedas(int d) {
    int resp = 0;
    for (int i = 0; i < n; i++) {
        resp += d/caps[i];
    }

    return resp;
}

int p(int d) {
    return v <= moedas(d);
}

signed main(){_

    cin >> n;
    cin >> v;

    for (int i = 0; i < n; i++) {
        cin >> caps[i];
    }

    lo = 0; hi = 1112233445566778899/n;
    while(lo < hi) {
        int md = lo + (hi-lo)/2;
        if (p(md)) hi = md;
        else lo = md + 1;
    }

    cout << lo << endl;

    return 0;
}
