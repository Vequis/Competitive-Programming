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

int a, b, x, y, t;
ll resp;

int main(){_

    cin >> t;
    while(t--){
        cin >> x >> y >> a >> b;

        if(a<b) swap(a,b);

        resp=0;
        if(x<y) swap(x,y);
        while(x-a>0 and y-b>0){
            resp++;
            x-=a;
            y-=b;
            if(a<b) swap(a,b);
        }

        cout << resp << endl;
    }

    return 0;
}