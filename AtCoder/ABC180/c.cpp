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

using namespace std;

ll n;

int main(){_

    cin >> n;

    set<int> cj;

    for (long i=1; i*i<=n; i++){
        if (n%i==0){
            cj.insert(i);            
            cj.insert(n/i);            
        }
    }

    for (auto x : cj){
        cout << x << endl;
    }

    return 0;
}