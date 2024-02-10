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


int last[312345];
int meio[312345];

vector<pair<int, int>> v;

signed main(){_
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    for(int i = 1; i <=n; i++) last[i] = -1;
	    for(int i = 1; i <=n; i++) meio[i] = -1;

	    
	    for(int i = 1; i <= 2*n; i++) {
	        int a;
	        cin >> a;
	        
	        if (last[a]== -1) last[a] = i;
	        else {
	            meio[a] = i - last[a] + 1;
	            v.emplace_back(meio[a], a);
	        }
	   
	    }
	    
	    sort(v.begin(), v.end());
	    
	    for(int i = n-1; i>=0; i--) {
	        cout << v[i].sc << ' ';
	    }
	    
	    cout << endl;

        v.clear();
	}

    return 0;
}
