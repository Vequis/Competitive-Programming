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

priority_queue<int, vi, greater<int> > pq0, pq1;
int t, n, ultima;
string s;
vi resp;

int main(){_

    cin >> t;

    while(t--){
        cin >> n;

        resp = vi(n);
        ultima = 1;
        for (int i=0; i<n; i++){
            char c;
            cin >> c;

            if (c=='0'){
                if (pq1.empty()){
                    resp[i] = (ultima);
                    pq0.push(ultima);
                    ultima++;
                } else {
                    resp[i] = (pq1.top());
                    pq0.push(pq1.top());
                    pq1.pop();
                }
            } else {
                if (pq0.empty()){
                    resp[i] = (ultima);
                    pq1.push(ultima);
                    ultima++;
                } else {
                    resp[i] = (pq0.top());
                    pq1.push(pq0.top());
                    pq0.pop();
                }
            }
        }

        cout << ultima-1 << endl;;

        for (int i=0; i<n; i++){
            cout << resp[i];
            if(i!=n-1) cout << ' ';
        }

        while(!pq1.empty())pq1.pop();
        while(!pq0.empty())pq0.pop();

        cout << endl;
    }

    return 0;
}