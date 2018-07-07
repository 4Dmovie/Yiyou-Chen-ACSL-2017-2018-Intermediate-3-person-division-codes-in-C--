//Language: C++
//Name: Yiyou Chen
//Division: 3 people intermediate
//Contest: ACSL Contest#3
//Date: March 2nd, 2018
#include <bits/stdc++.h>
const int INF = ~0U>>1;
using namespace std;
string grid, query[10];
string a[100];
char Mdir[1000][10];
string find(char x) {
	if(x == '0') return "0000";
	if(x == '1') return "0001";
	if(x == '2') return "0010";
	if(x == '3') return "0011";
	if(x == '4') return "0100";
	if(x == '5') return "0101";
	if(x == '6') return "0110";
	if(x == '7') return "0111";
	if(x == '8') return "1000";
	if(x == '9') return "1001";
	if(x == 'A') return "1010";
	if(x == 'B') return "1011";
	if(x == 'C') return "1100";
	if(x == 'D') return "1101";
	if(x == 'E') return "1110";
	if(x == 'F') return "1111";
}
int drow[1000], dcol[10000], numberofsteps;
int val[10][10];
int ansrow, anscol;
void walk(int nowrow, int nowcol, int direction, int steps) {
	if(nowrow == 0) nowrow = 8;
	if(nowrow == 9) nowrow = 1;
	if(nowcol == 0) nowcol = 8;
	if(nowcol == 9) nowcol = 1;
	if(steps == 0) {
		ansrow = nowrow;
		anscol = nowcol;
		return ;
	}
	if(a[nowrow][nowcol - 1] == '0') {
		walk(nowrow + drow[direction], nowcol + dcol[direction], direction, steps - 1);
	}
	else {
		int newdirection = (int) (Mdir[direction][val[nowrow][nowcol]] - 'A');
		val[nowrow][nowcol] = ((val[nowrow][nowcol] + 1) % 4);
		walk(nowrow + drow[newdirection], nowcol + dcol[newdirection], newdirection, steps - 1);
	}
}
int main(){
	Mdir['L' - 'A'][0] = 'B', Mdir['L' - 'A'][1] = 'L', Mdir['L' - 'A'][2] = 'A', Mdir['L' - 'A'][3] = 'R'; 
	Mdir['R' - 'A'][0] = 'A', Mdir['R' - 'A'][1] = 'R', Mdir['R' - 'A'][2] = 'B', Mdir['R' - 'A'][3] = 'L'; 
	Mdir['B' - 'A'][0] = 'R', Mdir['B' - 'A'][1] = 'B', Mdir['B' - 'A'][2] = 'L', Mdir['B' - 'A'][3] = 'A'; 
	Mdir['A' - 'A'][0] = 'L', Mdir['A' - 'A'][1] = 'A', Mdir['A' - 'A'][2] = 'R', Mdir['A' - 'A'][3] = 'B'; 
	drow['R' - 'A'] = 0, drow['L' - 'A'] = 0, drow['A' - 'A'] = 1, drow['B' - 'A'] = -1;
	dcol['R' - 'A'] = -1, dcol['L' - 'A'] = 1, dcol['A' - 'A'] = 0, dcol['B' - 'A'] = 0;
	for(int i = 1; i <= 7; ++i) {
		cin >> grid;
		for(int j = grid.size(); j < 3; ++j) {
			a[i] = a[i] + "0000";
		}
		for(int j = 0; j < grid.size(); ++j) {
			if(grid[j] != ',') {
				a[i] = a[i] + find(grid[j]);
			}
		}
	}
	cin >> grid;
	for(int j = grid.size(); j < 2; ++j) {
		a[8] = a[8] + "0000";
	}
	for(int j = 0; j < grid.size(); ++j) {
		if(grid[j] != ',') {
			a[8] = a[8] + find(grid[j]);
		}
	}
	for(int i = 1; i <= 5; ++i) {
		memset(val, 0, sizeof(val));
		for(int j = 1; j <= 3; ++j) {
			cin >> query[j];
		}
		cin >> numberofsteps;
		if(query[3][0] == 'L' || query[3][0] == 'R' || query[3][0] == 'A' || query[3][0] == 'B')
			walk(query[1][0] - '0', query[2][0] - '0', query[3][0] - 'A', numberofsteps);
		cout << ansrow << ", " << anscol << endl;
	}
return 0;
}
/*
C, C7, 85, D6, 46, D7, E6, 87 
2, 3, L, 2 
2, 7, B, 8  
4, 5, R, 3 
6, 7, A, 5 
8, 8, L, 7
*/
