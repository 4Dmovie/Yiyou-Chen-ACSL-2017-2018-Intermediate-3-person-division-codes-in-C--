//Language: C++
//Name: Yiyou Chen
//Division: 3 people intermediate
//Contest: ACSL Contest#2
//Date: Feburary 2nd, 2018
#include <bits/stdc++.h>
const int INF = ~0U>>1;
using namespace std;
string S;
int Closure1, Closure2, CutPlace;
char Missed;
stack <int> ST;
queue <int> Q;
int main(){
	for(int T = 1; T <= 5; ++T) {
		cin >> S;
		Closure1 = 0, Closure2 = 0;
		while(!Q.empty()) Q.pop();
		while(!ST.empty()) ST.pop();
		for(int i = 0; i < S.size(); ++i) {
			if(S[i] == '(') {
				Closure1++;
			}
			else if(S[i] == ')') {
				Closure1--;
			}
			else if(S[i] == '[') {
				Closure2++;
			}
			else if(S[i] == ']') {
				Closure2--;
			}
		}
		bool flag = -1;
		if(Closure1 > 0) {
			for(int i = 0; i < S.size(); ++i) {
				if(S[i] >= '0' && S[i] <= '9') {
					if(i == S.size() || S[i + 1] < '0' || S[i + 1] > '9') {
						Q.push(i + 2);
					}
				}	
				if(S[i] == '(') {
					while(!Q.empty()) Q.pop();
				}
				if(S[i] == ']') break;
			}
			Q.pop();
		}
		else if(Closure1 < 0) {
			for(int i = 0; i < S.size(); ++i) {
				if(S[i] >= '0' && S[i] <= '9') {
					if(i == 0 || S[i - 1] < '0' || S[i - 1] > '9') {
						ST.push(i + 1);
					}
				}
				if(S[i] == '[') {
					while(!ST.empty()) ST.pop();
				}
				if(S[i] == ')') {
					ST.pop();
					break;
				}
			}
		}
		else if(Closure2 > 0) {
			for(int i = 0; i < S.size(); ++i) {
				if(S[i] == ')') {
					while(!Q.empty()) Q.pop();
					Q.push(i + 2);
				}
				if(S[i] >= '0' && S[i] <= '9') {
					if(i == S.size() || S[i + 1] < '0' || S[i + 1] > '9') {
						Q.push(i + 2);
					}
				}
			}
		}
		else if(Closure2 < 0) {
			for(int i = 0; i < S.size(); ++i) {
				if(S[i] >= '0' && S[i] <= '9') {
					if (i == 0 || S[i - 1] < '0' || S[i - 1] > '9') {
						Q.push(i + 1);
					}
				}
				if(S[i] == '(') {
					Q.push(i + 1);
					break;
				}
			}
		}
		if(!Q.empty()){
			cout << Q.front();
			Q.pop();
			while(!Q.empty()) {
				cout << ", " << Q.front();
				Q.pop();
			}
		}
		int num = 0;
		int a[10000];
		if(!ST.empty()) {
			a[++num] = ST.top();
			ST.pop();
			while(!ST.empty()) {
				a[++num] = ST.top();
				ST.pop();
			}
			cout << a[num];
			for(int i = num - 1; i >= 1; --i) {
				cout << ", " << a[i]; 
			}
		}
		cout << endl;
	}
return 0;
}
/*
[2+3*8-3)]+6
[(2-5)+6
[(5+5-2]*5
13-[(6+18)/3*22
[4/(12-8/4*25]
*/
