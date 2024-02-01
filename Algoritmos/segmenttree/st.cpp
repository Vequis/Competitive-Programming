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

int n, a[1000], tree[4*1000];

void build(int a[], int node, int left, int right){
    if (left>right) return;
    if (left==right){
        tree[node] = a[left];
        return;
    }   

    int mid = left + (right-left)/2;
    build(a, 2*node, left, mid);
    build(a, 2*node + 1, mid+1, right);
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}

int sum(int node, int left, int right, int l, int r){
    if (l > r) return 0;
    if (l==left and r == right) return tree[node];
    int mid = left + (right-left)/2;
    return sum(2*node, left, mid, l, min(r, mid)) + sum(2*node+1, mid+1, right, max(l, mid+1), r);
}

void update(int node, int l, int r, int id, int val){
    if (l==r) {
        tree[node] = val;
        return;
    }
    int mid = l + (r-l)/2;
    if (id<=mid){
        update(2*node, l, mid, id, val);
    } else {
        update(2*node+1, mid+1, r, id, val);
    }

    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}

int main(){

    cin >> n;
    for (int i=0; i<n;i++){
        cin >> a[i];
    }

    int l,r;
    cin >> l >> r;

    build(a, 1, 0, n-1);

    update(1, 0, n-1, 3, 5);

    cout << sum(1, 0, n-1, l, r) << endl;

    return 0;
}