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

int n, ptr1, ptr2;
vi h;
int soma, ok;

signed main(){_
    
    cin >> n;
    h = vi(n);
    for(int i=0; i<n; i++){
        cin >> h[i]; 
    }

    soma = h[0] + h[n-1];
    
    ptr1 = 0 + 1;
    ptr2 = (n-1) - 1;

    ok = 1;
    while(ptr1 <= ptr2){
        if(h[ptr1] + h[ptr2] != soma) ok = false;
        ptr1++;
        ptr2--;
    }

    if(ok) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}
