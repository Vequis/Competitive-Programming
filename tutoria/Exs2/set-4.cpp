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

using namespace std;

set<pair<int,int> > cj;
set<pair<int,int> >::iterator it;
map<int, int> f;
vii cont; 
int n, k;
int num, mex = 0, var;

int main(){_

    cin >> n >> k;

    for (int i=0; i<k; i++){
        cj.insert({0,i});
        f[i] = 0;
    }

    for (int i=0; i<n; i++){
        cin >> num;

        var = num%k;

        cj.erase({f[var], var});

        f[var]++;

        cj.insert({f[var], var});

        cout << ((*cj.begin()).fs)*k + (*cj.begin()).sc;

        if (i!=n-1) cout << ' ';
    }

    return 0;
}