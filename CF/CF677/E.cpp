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

ll fact(int x){
    ll ans = 1;  
    for (int i=1; i<=x; i++){
        ans*=i;
    }

    return ans;
}

int main(){_

    long long ans = 1;

    cin >> n;

    ans = fact(n);

    ans/= fact(n/2);
    ans/= fact(n/2);


    ans *= fact(n/2 - 1);
    ans *= fact(n/2 - 1);

    ans/= 2;

    cout << ans << endl;

    return 0;
}