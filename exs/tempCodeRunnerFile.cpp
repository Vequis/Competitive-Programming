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

int n;
int a[100100];
stack<ii> pilha;
int menor[100100];

signed main(){_

    while((cin>>n) && (n!=0)){
        for(int i=1; i<=n; i++){
            cin >> a[i];
            while(!pilha.empty() && pilha.top().fs > a[i]){
                menor[pilha.top().sc] = i;
                pilha.pop();
            }

            pilha.push({a[i], i});
        }

        while(!pilha.empty()) {
            menor[pilha.top().sc] = n+1;
            pilha.pop();
        }

        int resp = 0;

        for(int i=1; i<=n; i++){
            resp = max(resp, (menor[i] - i)*a[i] );
        }

        cout << resp << endl;
    }

    return 0;
}
