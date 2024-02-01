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
int k;
set<int> resp;
int t;

signed main(){_
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        k = a+b;

        if(a<b) swap(a,b);

        for(int i=k/2; i>=0; i--){
            if(a-i <=k/2+1) resp.insert(a-i + (k/2 - i));

        }

        if(k%2==1){
            for(int i=k/2+1; i>=0; i--){
                if(a-i <=k/2) resp.insert(a-i + (k/2+1 - i));
            }
        }
        cout << sz(resp) << endl;

        for(int x : resp) {
            cout << x << ' ';
        }
        cout << endl;
        resp.clear();
    }

    return 0;
}
