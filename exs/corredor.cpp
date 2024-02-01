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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

vi psa;
int n, menor, ans, atual;

int main(){_

    cin >> n;

    psa=  vi(n+1);

    for (int i=1; i<=n; i++){
        cin >> psa[i];
        psa[i]+= psa[i-1];
        atual = psa[i] - menor;
        menor = min(psa[i], menor);
        ans = max(atual, ans);
    }

    cout << ans << endl;

    return 0;
}