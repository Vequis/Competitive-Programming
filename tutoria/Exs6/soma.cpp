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

int n,k;
ll soma, ans;
map<long long int, int> f;

int main(){_

    cin >> n >> k;

    f[0] = 1;

    for (int i=1; i<=n; i++){
        int num;
        cin >> num;

        soma+=num;

        ans += f[soma-k];

        f[soma]++;
    }

    cout << ans << endl;

    return 0;
}