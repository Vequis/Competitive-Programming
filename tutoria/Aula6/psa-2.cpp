#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX (1<<20)
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

vi a(MAX), psa(MAX);
int n, x;
int l,r;

int main(){_

    cin >> n;
    
    psa[0] = 1;

    for (int i=1; i<=n; i++){
        cin >> x;
        a[i] = x;
        psa[i] = psa[i-1] * x;
    }

    while((cin >> l >> r) and (l||r)){
        cout << 'Q' << '(' << l << ',' << r << ')' << ' ' << ':' << ' ' << psa[r] / psa[l-1] << endl;
    }

    return 0;
}