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

int a[1000], tree[4*1000], n;

void build(int node, int l, int r){
    if (l>r)return;
    if (l==r) {
        tree[node] = a[l];
        return;
    } 
    int mid = l+(r-l)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node] = max(tree[node*2], tree[2*node+1]);
}

int query(int node, int left, int right, int l, int r){
    if (l>r) return 0;
    if (l==left and r==right) return tree[node];
    int mid = left + (right-left)/2;
    return max(tree[node*2], tree[2*node + 1]);
}

int main(){_

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    int l,r;
    cin >> l >> r;

    build(1, 0, n-1);
    cout << query(1, 0, n-1, l, r) << endl;

    return 0;
}