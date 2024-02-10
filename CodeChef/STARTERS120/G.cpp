#include <bits/stdc++.h>
using namespace std;

int last[112345];
int meio[112345];

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    for(int i = 1; i <=n; i++) last[i] = -1;
	    for(int i = 1; i <=n; i++) meio[i] = -1;
	    
	    vector<pair<int, int>> v;
	    
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
	    
	    for(int i = n-1; i>=0; i++) {
	        cout << v[i].second << ' ';
	    }
	    
	    cout << endl;
	}

}

