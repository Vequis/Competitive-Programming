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

int t, n, k;

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n >> k;
        for (int j=0; j<n; j++){
            if (j%3==0) cout << 'a';
            else if(j%3==1) cout << 'b';
            else cout << 'c';
        }
        cout << endl;
    }

    return 0;
}