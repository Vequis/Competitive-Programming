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

using namespace std;

int n, d, comp;
vi psa, a;
map<int,int> f;
ll ans, soma;

int main(){_

    cin >> n >> d;

    psa = vi(n+1);
    a = vi(n+1);

    psa[0] = 0;
    f[0] = 1;

    for (int i=1; i<=n; i++){
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
        soma+=a[i];
    }

    comp = soma-d;
    for(int i=1; i<=n; i++) {

        ans+= f[psa[i] - d];

        f[psa[i]]++;

        ans+= f[psa[i] - comp];
        if (psa[i] == comp or i==n) ans--;
    }

    cout << ans << endl;

    return 0;
}