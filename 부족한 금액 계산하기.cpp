#include<bits/stdc++.h>
using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = 0;
	do
	{
		answer += price * count;
	} while (--count);

	return answer < money ? 0 : answer - money;
}