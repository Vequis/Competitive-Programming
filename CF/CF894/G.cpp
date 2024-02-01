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

signed main(){

    multiset<int> s;
    multiset<int> dist;
    multiset<int>::iterator it;
    multiset<int>::iterator it2;

    int t;
    cin >> t;
    while(t--) {_

        int n;
        cin >> n;

        int diste = 0;

        vi v;

        int a, b;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            s.insert(num);
            v.pb(num);

            it = s.find(num);

            a = -1;
            b = -1;

            if (it != s.begin()) {
                it--;
                dist.insert(abs(num - *(it)));
                a = *(it);
                it++;
            }

            it++;
            if (it!=s.end()){
                dist.insert(abs(num - *(it)));
                b = *(it);
            }

            if(a != -1 and b != -1) {
                if(dist.find(abs(a-b)) != dist.end())
                    dist.erase(dist.find(abs(a-b)));
            }
        }

        int q;
        cin >> q;

        // for(int x : dist) cout << x << ' ';
        // cout << endl;

        while(q--) {
            int ind, x;
            cin >> ind >> x;

            int atual = v[ind-1];

            it = s.find(atual);

            // cout << *(it) << endl;

            a = -1;
            b = -1;
            if (it != s.begin()) {
                it--;
                if(dist.find(abs(atual - *(it))) != dist.end())
                    dist.erase(dist.find(abs(atual - *(it))));
                a = *(it);
                it++;
            }

            // for(int d : dist) cout << d << ' ';
            // cout << endl;

            it++;
            if (it!=s.end()){
                if(dist.find(abs(atual - *(it))) != dist.end())
                    dist.erase(dist.find(abs(atual - *(it))));
                b = *(it);
            }

            it--;
            s.erase(it);
            if(b!= -1 and a!= -1) dist.insert(abs(a-b));


            s.insert(x);
            v[ind-1] = x;

            it = s.find(x);

            a= -1;
            b = -1;
            if (it != s.begin()) {
                it--;
                dist.insert(abs(x - *(it)));
                a = *(it);
                it++;
            }

            it++;
            if (it!=s.end()){
                dist.insert(abs(x - *(it)));
                b = *(it);
            }

            if(a != -1 and b != -1) {
                if(dist.find(abs(a-b)) != dist.end())
                    dist.erase(dist.find(abs(a-b)));
            }

            it = dist.end();
            it--;
            it2 = s.end();
            it2--;


            cout << *(it) + *(it2) << ' ';
        }
        cout << endl;

        s.clear();
        dist.clear();
    }


    return 0;
}
