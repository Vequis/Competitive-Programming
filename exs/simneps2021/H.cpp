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

signed main(){_

    return 0;
}


#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long 

using namespace std;

signed main(){_

    int n;
    cin >> n;

    string s;
    cin >> s;

    int var = 0;
    string gab;
    for(int i=0; i<n; i++){
        if(var==0){
            gab.pb('I');
        } else {
            gab.pb('O');
        }
        var = var^1;
    }

    int resp = 0;
    for(int i=0; i<n; i++){
        if(s[i] !=gab[i]) resp++;
    }

    cout << resp << endl;

    return 0;
}
