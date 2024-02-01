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

using namespace std;

int n,q;

char a[200100];
string tree[4*200100];

void build(int node, int l, int r){
    if (l > r) return;
    if (l==r) {
        tree[node] = a[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node] = tree[2*node] + tree[2*node+1];
}

char query(int node, int left, int right, int id){
    if (left==right) return tree[node][0];
    int mid = left + (right-left)/2;
    if (id<=mid){
        return query(2*node, left, mid, id);
    } else {
        return query(2*node+1, mid+1, right, id);
    }
}

void update(int node, int l, int r, int id, char val){
    if (l==r){
        tree[node] = val;
        return;
    }
    int mid = l+(r-l)/2;
    if (id<=mid) update(2*node, l, mid, id, val);
    else update(2*node+1, mid+1, r, id, val);
    tree[node] = tree[2*node] + tree[2*node + 1];
    return;
}

void update2(){
    string aux;
    aux = tree[2];
    tree[2] = tree[3];
    tree[3] = aux;
    build(4,0, 2*n-1);
    tree[1] = tree[2] + tree[3];
}

int main(){_

    cin >> n;
    // for (int i=0; i<n; i++){
    //     char c;
    //     cin >> c;
    //     s1+=c;
    // }

    // for (int i=0; i<n; i++){
    //     char c;
    //     cin >> c;
    //     s2+=c;
    // }

    for(int i=0; i<(2*n); i++){
        cin >> a[i];
    }
    build(1, 0, 2*n-1);

    cin >> q;

    for (int i=0; i<q; i++){
        int x,t,b;
        cin >> t;
        cin >> x >> b;
        if (t==1){
            char c,d;
            c = query(1, 0,n-1, x-1);
            d = query(1, 0,n-1, x-1);
            update(1, 0, 2*n-1, x-1, d);
            update(1, 0, 2*n-1, b-1, c);
        } else {
            update2();
        }
        cout << t << ' ' << tree[1] << endl;
    }

    cout << tree[1] << endl;

    return 0;
}