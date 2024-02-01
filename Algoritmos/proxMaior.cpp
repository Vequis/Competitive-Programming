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

vi nums;
int n;
vi gr;
stack<int> fila;

int main(){_

    cin >> n;

    gr = vi(n+1, -1);
    nums = vi(n+1);

    for (int i=1; i<n+1; i++){
        cin >> nums[i];
    }

    fila.push(1);

    for (int i=2; i<=n; i++){
        while (!fila.empty() && nums[i] > nums[fila.top()]){
            gr[fila.top()] = nums[i];
            fila.pop();
        }
        fila.push(i);
    }

    for (int i=1; i<=n; i++){
        cout << i << " : " << gr[i] << endl;
    }

    return 0;
}