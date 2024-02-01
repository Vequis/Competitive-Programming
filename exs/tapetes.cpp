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

using namespace std;

int n, t;
ll ans;

int main(){_

    cin >> n >> t;

    ans = (n- (t-1) ) ;
    ans *= (n- (t-1) );
    ans += t-1;

    cout << ans << endl;

    return 0;
}