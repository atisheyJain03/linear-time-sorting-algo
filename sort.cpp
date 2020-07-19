#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int MAX = 100000;

vector<int> v,zeros,ones;


//void lin_sort(int s, int e,int k) {
//	if (( e-s <=1) || k<0) return;
//	
//	for (int i = s; i < e; i++) {
//		if (v[i] & (1 << k)) ones.push_back(v[i]);
//		else zeros.push_back(v[i]);
//	}
//	int l1 = ones.size() , l2 = zeros.size();
//	for (int i = 0; i < ones.size();i++) v[s + i] = ones[i];
//	for (int i = 0; i < zeros.size(); i++) v[s + l1 + i] = zeros[i];
//	zeros.assign(0, 0);
//	ones.assign(0, 0);
//	lin_sort(s, s + l1, k - 1);
//	lin_sort(s + l1, e, k - 1);
//}


//void lin_sort(int k , queue<pair<int,int> > &q) {
//	if (q.empty() || k < 0) return;
//	queue<pair<int, int> > q_new;
//	while (q.size()) {
//		pair<int, int> qf = q.front();
//		q.pop();
//		int s = qf.first , e = qf.second;
//		if ((e - s <= 1)) continue;
//		zeros.resize(0);
//		ones.resize(0);
//		for (int i = s; i < e; i++) {
//			if (v[i] & (1 << k)) ones.push_back(v[i]);
//			else zeros.push_back(v[i]);
//		}
//		int l1 = ones.size(), l2 = zeros.size();
//		for (int i = 0; i < ones.size(); i++) v[s + i] = ones[i];
//		for (int i = 0; i < zeros.size(); i++) v[s + l1 + i] = zeros[i];
//		q_new.push({ s,s + l1 });
//		q_new.push({ s + l1,e });
//	}
//	lin_sort(k - 1, q_new);
//}


void lin_sort(int k, queue<pair<int, int> >& q) {
	
	while (k>=0 && !q.empty()) {
		int x = q.size();
		for (int i = 0; i < x; i++) {
			pair<int, int> qf = q.front();
			q.pop();
			int s = qf.first, e = qf.second;
			if ((e - s <= 1)) continue;
			
			int l1 = 0, l2 = 0;
			for (int i = s; i < e; i++) {
				if (v[i] & (1 << k)) {
					ones[l1] = v[i];
					l1++;
				}
				else {
					zeros[l2] = v[i];
					l2++;
				}
			}
			for (int i = 0; i < l1; i++) v[s + i] = ones[i];
			for (int i = 0; i < l2; i++) v[s + l1 + i] = zeros[i];
			q.push({ s,s + l1 });
			q.push({ s + l1,e });
		}
		k--;
	}
}



bool check() {
	for (int i = 0; i < v.size() - 1; i++) if (v[i] < v[i + 1]) return false;
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v.assign(n, 0);
		zeros.assign(n, 0);
		ones.assign(n, 0);
		//for (int &i : v) cin >> i;
		for (int i = 0; i < n; i++) v[i] = rand() % 1000 ;
		queue<pair<int, int> > q;
		q.push({ 0,n });
		lin_sort(11,q);
	//	for (int i : v) cout << i << " "; cout << endl;
		check() ? cout << "CORRECT\n" : cout << "INCORRECT\n";
	}
}
