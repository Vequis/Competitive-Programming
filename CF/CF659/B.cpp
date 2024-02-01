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

int t, n, k ,l;
vector< set<int> >  v;
vi d;
bool ok;

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n >> k >> l;
        ok = true;

        v= vector< set<int> > (set<int>, n+1);

        for (int j=1; i<=n; i++){
            cin >> d[j];
            if (d[j] > l) ok = false;
            else {
                for (int p=0; p<=(d[j] - l); p++){
                    v[j].insert(p); 
                }
            }
        }
        if(!ok) break;

        for (int i)


    }

    return 0;
}