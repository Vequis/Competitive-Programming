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

int n, c, s;
int cont;

signed main(){_

    cin >> n >> c >> s;

    int atual = 1;
    if(s==1) cont++;
    for(int i=0; i<c; i++){
        int num;
        cin >> num;

        if(atual == 1 && num == -1) {
            atual = n;
        } else if (atual==n && num==1 ){
            atual = 1;
        } else {
            atual+=num;
        }

        if(atual == s) cont++;
    }

    cout << cont << endl;

    return 0;
}
