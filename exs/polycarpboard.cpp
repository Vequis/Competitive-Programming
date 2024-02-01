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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

set<ll> nums;
int n, aux;
vector<pair<ll, ll> > adj;

//Não finalizado

int main(){_

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> aux;
        nums.insert(aux);
    }

    adj = vii(n+1);

    int ind = 0;
    for (auto x : nums){
        if (x%3){
            if (nums.find(2*x) != )
            adj[ind] = {2*x, -1};
        } else {
            adj[ind] = {2*x, x/3};
        }

        ind++;
    }

    for (int i=0; i<n; i++){
        if (dfs(i) == n){

        }
    }

    return 0;
}