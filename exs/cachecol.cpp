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
const int MODN = 1e9 + 7;

using namespace std;

ll n, ans;

ll f(ll n, int tipo){
    if (n==0) return 1;
    else if (n==1){
        return 6;
    }

    int a = f(n-1, 0);
    int b = f(n-1, 1);

    if (tipo == 0){
        return (a*2 + b*2)%MODN;
    } else {
        return (a*2 + b*3)%MODN;
    }
}

int main(){_

    cin >> n;

    cout << f(n,0) + f(n, 1) << endl;

    return 0;
}