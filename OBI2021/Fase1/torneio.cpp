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

char c;
int cont;

int main(){_

    for(int i=0; i<6; i++){
        cin >> c;
        if(c=='V')cont++;
    }

    if(cont==5 || cont==6) cout << 1 << endl;
    else if (cont==3 || cont==4) cout << 2 << endl;
    else if (cont==1 || cont==2) cout << 3 << endl;
    else cout << -1 << endl;

    return 0;
}
