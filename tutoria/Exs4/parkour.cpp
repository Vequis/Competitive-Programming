#include <bits/stdc++.h>

using namespace std;

stack<int> pilha;
priority_queue< pair<int,int> > pq;
vector<pair<int,int> > ngr, a; 
map<int,int> cont; // Guarda os prédios e suas alturas e distancias
int n, maior, x, h; //numero de predios ; maior altura(final) ; variaveis de leitura;

int func(int  i){
	if (i==-1) return 0;
	if(cont[a[i].first] != -1) return cont[a[i].first];

	int ans = func(ngr[i].first) + func(ngr[i].second);
	cont[a[i].first] = ans;
	return ans;
}

int main() {
	cin >> n;

	a = vector< pair<int,int> > (n);
	ngr = vector<pair<int,int> > (n, {-1,-1});

	for (int i=0; i<n; i++)	{
		cin >> x >> h;

		a[i] = {x,h};
		pq.push({h,x});

		cont[x] = -1;
	}

	maior = (pq.top()).first;

	sort(a.begin(), a.end());

	while(!pq.empty() and pq.top().first == maior){
	    cont[pq.top().second] = 1;
		pq.pop();
	}

	for (int i=0; i<n; i++){
		while(!pilha.empty() && a[i].second > a[pilha.top()].second) {
			ngr[pilha.top()] = {-1,i};
			pilha.pop();
	 	}
		pilha.push(i);		
	}

	while(!pilha.empty()) pilha.pop();

	for (int i=n-1; i>=0; i--) {
		while(!pilha.empty() && a[i].second > a[pilha.top()].second) {
			ngr[pilha.top()] = {i, ngr[pilha.top()].second};
			pilha.pop();
		}

		pilha.push(i);
	}

	// for(int i=0;i<n; i++) cout << i << ' ' << a[i].first << ' ' << a[i].second << ':' << ngr[i].first << ' ' << ngr[i].second << endl;
	long long soma = 0;

	for (int i=0; i<n; i++){
		cout << i << ' ' << func(i) << endl;
		soma+= func(i);		
	}

	cout << soma << endl;

	return 0;
}
