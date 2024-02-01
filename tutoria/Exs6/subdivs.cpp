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

int n;
vector<ll> psa;
int num;
map<long long int,int> f;
ll ans = 0;

int main(){_

    cin >> n;

    psa = vector<ll>(n+1);

    psa[0] = 0;
    f[0] = 1;
    for (int i=1; i<=n; i++){
        cin >> num;

        psa[i] = (psa[i-1] + num%n + n)%n;
        ans += f[psa[i]]++;
    }

    cout << ans << endl;

    return 0;
}