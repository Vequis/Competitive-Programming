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
const int MODN = 1000000007;

using namespace std;

int pot, x, n, k, juq;
int total =1;
ll ans = 2;

ll mult(ll a, ll b){
    ll ans = (a*b)%MODN;
    return ans;
}

ll fact(int n){
    if (n<2) return 1;
    return n*fact(n-1);
}

int main(){_

    cin >> n >> k;

    for (int i=0; i<n; i++) total*=2;
    cin >> juq;

    for (int i=0; i<total-1; i++){
        int num;
        cin >> num;
        if (num < juq) x++;
    }


    pot = 1;
    for (int i=0; i<k-1; i++) pot*=2;
    if (x<pot-1) {
        cout << 0 << endl;
        return 0;
    } else if (k==n+1){
        cout << fact(total) << endl;
        return 0;
    } 

    ans = mult(ans, pot);
    for (int i=0; i<=pot-1; i++){
        ans = mult(ans, x-i);
    }

    cout << pot << ' ' << total << ' ' << x << endl;
    cout << 1 << ' '<< ans << endl;

    ans = mult(ans, pot);
    ans = mult(ans, total-(x+1));


    for (int i=1; i<=pot-1; i++){
        ans = mult(ans, total-(pot+2-i));
    }

    cout << ans << endl;

    return 0;
}