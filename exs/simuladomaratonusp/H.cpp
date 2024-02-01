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
#define INF 0x3f3f3f3f
#define MODN 1000000007
// #define int long long -> solução divina?

using namespace std;

int n, ans;

map<int, int> mp;

int main(){_

    cin >> n;

    for (int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        for(int i=(a/5)+1; i<=(b-1)/5; i++){
            if(mp[i]==0) ans++;
            else mp[i]=1;
        }
    }

    cout << ans << endl;

    return 0;
}