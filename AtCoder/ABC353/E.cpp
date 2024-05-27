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

int resp = 0;
struct TrieNode
{
	map<char,TrieNode*> children;
	int prefixes;
	bool endofword;
	TrieNode()
	{
		prefixes=0;
		endofword=false;
	}
};
void insert(TrieNode *root,string word)
{
	TrieNode *current=root;
	for(int i=0;i<word.size();i++)
	{   
		char ch=word[i];
		TrieNode *node=current->children[ch];
		if(!node)
		{
			node=new TrieNode();
			current->children[word[i]]=node;
		}
		current=node;
		current->prefixes++;
        resp += current->prefixes - 1;
	}
	current->endofword=true;
}


void solve() {
    TrieNode *root=new TrieNode();

    int n;
    cin >> n;

    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.eb(s);
    }
    sort(all(v));

    for (int i = 0; i < n; i++) insert(root, v[i]);


    cout << resp << endl;
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}