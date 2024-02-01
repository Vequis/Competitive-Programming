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

set<pair<string, string> > cj;

signed main(){_

    int n;
    cin >> n;

    bool end = false;

    for(int i=0; i<n; i++){
        string s1, s2;
        cin >> s1 >> s2;

        int antes = sz(cj);
        cj.insert({s1, s2});
        if(antes == sz(cj) && !end){
            cout << "Yes" << endl;
            end = 1;
        }
    }

    if(!end){
        cout << "No" << endl;
    }

    return 0;
}
