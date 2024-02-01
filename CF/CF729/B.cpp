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
#define int long long // -> solução divina

using namespace std;

int a, b;

int func(int n){
    if(n<=0) return 0;

    if(n==1) return 1;
    if(n%a == 0 and (a!=1)) return func(n/a);

    if(b==0) return 0;
    return func(n-b);
}

int n;

signed main(){_

    int t;
    cin >> t;

    while(t--){
        cin >> n >> a >> b;

        // while(n>0){
        //     if(n==1 or n%a==0){
        //         cout << "Yes" << endl;
        //         break;
        //     }

        //     n-=b;
        //     if(n<= 0) break;
        // }

        if(func(n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
