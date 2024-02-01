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
#define MAX (1<<10)

using namespace std;

int a[MAX], psa[MAX];
int n, m, l, c;
int r;
ll ans = 0, atual;

//Problema das fitas, dadas as fitas, qual posição tem mais fitas?;

int main(){_

    cin >> n >> m;

    while(m--){
        cin >> l >> r;
        a[l] += 1;
        a[r+1] += -1;
    }

    for (int i=1; i<=n; i++){
        psa[i] = a[i] + psa[i-1];
        ans = max(ans, psa[i]);
    }

    cout << ans << endl;

    return 0;
}