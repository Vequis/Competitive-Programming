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

string s;
int n, q;
vi psa;

int main(){_

    cin >> n >> q;
    psa = vi(n+1);
    cin >> s;

    psa[0] = 0;
    for(int i=0; i<n; i++){
        psa[i+1] = psa[i] + (s[i] - 'a' + 1);
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        cout << psa[b] - psa[a-1] << endl;
    }

    return 0;
}
