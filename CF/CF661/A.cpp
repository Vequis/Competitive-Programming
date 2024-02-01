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

vi v;
priority_queue<int, vi, greater<int> > pq;
int n, t;
bool ok;

int main(){_

    cin >> t;

    while(t--){
        ok  = true;
        cin >> n;

        v = vi(n);

        for (int i=0; i<n; i++){
            int num;
            cin >> num;

            pq.push(num);
        }

        int atual = pq.top();

        pq.pop();

        while(!pq.empty()){
            if (pq.top() == atual or pq.top() == atual+1){
                atual = pq.top();
                pq.pop();
            } else {
                ok = false;
                break;
            }
        }

        if (ok){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        while(!pq.empty()) pq.pop();
    }

    return 0;
}