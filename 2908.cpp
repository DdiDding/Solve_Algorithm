#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string a, b, c = ""; cin >> a >> b;
	for (int i = a.size() - 1; 0 <= i; --i)
	{
		if (c == "")
		{
			if (a[i] == b[i])
			{
				cout << a[i];
				continue;
			}
			a[i] > b[i] ? c = a : c = b;
		}
		cout << c[i];
	}
	return 0;
}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	string a, b, c; cin >> a >> b;
//	for (int i = a.size() - 1; 0 <= i; --i)
//	{
//		if (a[i] == b[i]) continue;
//
//		a[i] > b[i] ? c = a : c = b;
//		break;
//	}
//
//	for (int i = a.size() - 1; 0 <= i; --i)
//	{
//		cout << c[i];
//	}
//	return 0;
//}

/*
수학을 정말 못해
수의 크기를 비교하는 문제
세 자리 수 두개를 칠 판에 씀
크기가 큰 수 말해
수를 거꾸로읽는다ㅏ??

734 893
거꾸로
437 398 

같지 않은 수니까 같은 경우 없음 0이 포함 안됨
그냥 인덱스 거꾸로 하면 될듯?

인덱스 비교나 거꾸로 출력할때 정수보단 문자열이 편하지

세자리 수니까 size는 똑같음.
for(str.size() -1 ; 0 <= i; --i)
{
더 큰거 비교 하면 될듯? 
더 큰게 나오면 종료하고 
}

*/