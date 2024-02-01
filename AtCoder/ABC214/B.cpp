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

    int s, t;
    cin >> s >> t;

    int cont = 0;
    for(int a = 0; a<=s; a++){
        for(int b=0; b<=s-a; b++){
            for(int c=0; c<=s-a-b; c++){
                if(a*b*c <= t) cont++;
            }    
        }
    }

    cout << cont << endl;

    return 0;
}
