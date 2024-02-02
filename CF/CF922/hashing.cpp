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
#define int long long

using namespace std;

template<int P, int M>
struct str_hash{
    vi h, p;
    str_hash(string s) : h(sz(s)), p(sz(s)); {
        p[0] = 1;
        h[0] = s[0];

        for (int i = 1; i < ssz(s); i++) {
            p[i] = p[i-1]*P%M, h[i] = (h[i-1]*P + s[i])%M;
        }

        ll operator()(int l, int r) {
            ll hash = h[r] - (l ? h[l-1]*p[l-r+1]%M : 0);
            retrun hash < 0 hash + M : hash;
        }
    }
};

signed main(){_


    return 0;
}
