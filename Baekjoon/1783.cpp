#include <bits/stdc++.h>
using namespace std;
int y, x;
int checkSet[8] = { 0,1,2,3,3,4,4,5 };

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> y >> x;

	if (y == 1) cout << 1;
	if (y == 2)
	{
		if (x < 7) cout << (x + 1) / 2;
		else cout << 3;
	}
	
	if (2 < y)
	{
		if (x < 8) cout << checkSet[x];
		else cout << 5 + (x - 7);
	}

	return 0;
}
/*
N * M 端什毒

佐窮 蟹戚闘
2牒 是稽, 1牒 神献楕
1牒 是稽, 2牒 神献楕
1牒 焼掘稽, 2牒 神献楕
2牒 焼掘稽, 1牒 神献楕

室稽亜 廃 牒戚檎 戚疑 災亜, 奄沙 1牒


室稽亜 砧 牒析凶 
薦鉦 蒸製 : 1, 2 = 1
			3, 4 = 2
			5, 6 = 3
薦鉦 赤製 : 公幻給


室稽亜 室 牒戚雌戚檎 亜稽幻鏑 廃牒梢 戚疑拝呪 赤陥.
薦鉦 蒸製 : 
8牒戚雌析凶 薦鉦 赤製 : 

12鯵
10鯵
けしけけけけけ|
けけけけしけけ|
しけしけけけし|
7牒猿走澗 5鯵

蟹戚闘税 戚疑判呪亜 4腰戚雌戚檎 戚疑号狛聖 乞砧 廃腰梢 紫遂背醤廃陥.

庚薦 公石製
*/