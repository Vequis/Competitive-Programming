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

int c, n, t, d;
priority_queue<ii, vii, greater<ii> > pq;
ii p;

bool demora(int chegada, int livre){
    return (livre-chegada>20);
}

int cont = 0;

int main(){_

    cin >> c >> n;

    for (int i =0; i<c; i++){
        pq.push({0,i});
    }

    while(n--){
        cin >> t >> d;

        p = pq.top();
        pq.pop();

        pq.push({max(t,p.fs)+d, p.sc});

        // cout << t << " " << p.fs << endl;

        if(demora(t, p.fs)) cont++;
    }

    cout << cont << endl;

    return 0;
}