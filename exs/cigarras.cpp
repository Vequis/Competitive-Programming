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

using namespace std;

int mmc(int a, int b){
    if (b>a) swap(a,b);
    if (b==0) return a;
    return mmc(b, a%b);
}

int mdc(int a, int b){
    return a*b/mmc(a,b);
}

int a, b, n, l, at = 1, obj;

int main(){_

    cin >> n >> l;

    for (int i=0; i<n; i++){
        cin >> a;
        at = mdc(a,at);
    }

    obj = (l/at) * at;

    for (int i=1; i<=l; i++){
        if (mdc(i, at) == obj) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}   