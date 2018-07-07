//Yiyou Chen ACSL 2017-2018 Contest1 Intermediate Ninty-Nine
#include <bits/stdc++.h>
const int INF = ~0U>>1;
using namespace std;
int total, id, x; int Player[1002]; char ch;
int getint(char ch) {
	if(ch >= '2' && ch <= '9') return (int)(ch - '0');
	if(ch == 'T') return 10;
	if(ch == 'J') return 11;
	if(ch == 'Q') return 12;
	if(ch == 'K') return 13;
	if(ch == 'A') return 14;
}
int work(int value, int number) {
	if(number == 9) return value;
	if(number == 10) return value - 10;
	if(number == 14) {
		if(value + 14 <= 99) return value + 14;
		return value + 1;
	}
	return value + number;
}
int main(){
	for(int T = 1; T <= 5; ++T) {
		id = 0;
		cin >> total;
		for(int i = 1; i <= 3; ++i) {
			cin >> ch; cin >> ch; x = getint(ch);
			Player[++id] = x;
		}
		int ans = -1, hello = -1;
		for(int i = 1; i <= 7; ++i) {
			cin >> ch;
			cin >> ch; x = getint(ch);
			if(i % 2 == 1) {
				sort(Player + 1, Player + id + 1);
				total = work(total, Player[id]), Player[id] = x;
			}
			else 
				total = work(total, x);
			if(ans == -1 && total > 99)
				ans = total, hello = i;
		}
		cout << ans << ", ";
		if(hello & 1) cout << "dealer\n";
		else cout << "player\n";
	}
return 0;
}
/*
75, 7, 3, 8, 8, 7, T, 5, 9, A, 6
80, 9, T, 7, 8, K, A, 3, 5, Q, T
94, 4, 2, 2, 7, T, 3, A, 5, J, K
80, 6, 6, 4, T, 9, 8, 6, 5, Q, K
90, T, 8, 5, 9, 9, Q, K, A, J, 8
*/
