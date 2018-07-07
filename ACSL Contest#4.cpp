//Yiyou Chen C++ ACSL Contest#4 Programming Part
#include <bits/stdc++.h>
const int INF = ~0U>>1;
using namespace std;
char ch;
int hashh[100005];
int num[100005], val[1005][1005];
string s;
int main(){
	while(cin >> s) {
		if(s == "RESET") {
		  memset(val, 0, sizeof(val));
		  memset(num, 0, sizeof(num));
		  memset(hashh, 0, sizeof(hashh));
			while(scanf("%c", &ch)) {
				if(ch == '\n') {
					break;
				}
				else {
					if(ch >= 'a' && ch <= 'z') {
						ch = (char)(ch - 32);
					}
					if(ch >= 'A' && ch <='Z') {
						++hashh[(int)ch];
						int loop = 0;
						for(int i = 65; i <= 90; ++i) {
							if(hashh[i] != 0) {
								++loop;
								if(val[loop][num[loop]] != i) {
									val[loop][++num[loop]] = i;
								}
							}
						}
					}
				}
			}
		}
		else if(s == "ADD") {
			while(scanf("%c", &ch)) {
				if(ch == '\n') break;
				else {
					if(ch >= 'a' && ch <= 'z') {
						ch = (char)(ch - 32);
					}
					if(ch >= 'A' && ch <='Z') {
						++hashh[(int)ch];
						int loop = 0;
						for(int i = 65; i <= 90; ++i) {
							if(hashh[i] != 0) {
								++loop;
								if(val[loop][num[loop]] != i) {
									val[loop][++num[loop]] = i;
								}
							}
						}
					}
				}
			}
		}
		else if(s == "DELETE") {
			while(scanf("%c", &ch)) {
				if(ch == '\n') break;
				else {
					if(ch >= 'a' && ch <= 'z') {
						ch = (char)(ch - 32);
					}
					if(ch >= 'A' && ch <='Z') {
						if(hashh[(int)ch] > 0) --hashh[(int)ch];
						int loop = 0;
						for(int i = 65; i <= 90; ++i) {
							if(hashh[i] != 0) {
								++loop;
								if(val[loop][num[loop]] != i) {
									val[loop][++num[loop]] = i;
								}
							}
						}
					}
				}
			}
		}
		else if(s == "REPORT") {
			int pos;
			cin >> pos;
			for(int i = 1; i <= num[pos]; ++i) {
				cout << (char)val[pos][i];
			}
			cout << endl;
		}
	}
return 0;
}
/*
RESET abracadabracabob
REPORT 3
REPORT 5
ADD BATH
DELETE BOA
REPORT 5
DELETE drr
REPORT 5
RESET American Computer Science League
ADD Computer
DELETE Computer
DELETE COMPUTER
REPORT 10
*/
