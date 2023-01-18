#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long int integer;
typedef long long int price;

int i;
int main()
{
	integer N, K;
	scanf("%lld %lld", &N, &K);

	//fisrt = 무게, second = 가격
	vector<pair<integer, price>> jewels;
	integer M, V;
	for (i = 0; i < N; ++i)
	{
		scanf("%lld %lld", &M, &V);
		jewels.push_back(make_pair(M, V));
	}
	sort(jewels.begin(), jewels.end());

	vector<integer> C;
	integer temp;
	for (i = 0; i < K; ++i)
	{
		scanf("%lld", &temp);
		C.push_back(temp);
	}
	sort(C.begin(), C.end());

	priority_queue<price> pq;

	integer index = 0;
	integer result = 0;
	for (const auto & bag : C)
	{
		while (index < N && jewels[index].first <= bag)
		{
			pq.push(jewels[index++].second);
		}

		if (pq.empty() == false)
		{
			result += pq.top();
			pq.pop();
		}
	}
	
	printf("%lld", result);
	return 0;
}




//void PrintJewels(const vector <pair<integer, integer>>  & jewels)
//{
//	int i = 1;
//	for (const auto & data : jewels)
//	{
//		cout << i << "번째 보석 || 무게 : " << data.first << ", 가격 : " << data.second << endl;
//		++i;
//	}
//}
//
//void PrintBags(const vector<integer>  & list, integer & size)
//{
//	int i = 1;
//	for (const auto & data : list)
//	{
//		cout << i << "번째 가방 || 허용 무게 : " << data << endl;
//		++i;
//		if (size < i) break;
//	}
//}


//j < i 면 내림차순, i < j 면 오름차순
//bool comp(pair<integer, integer> i, pair<integer, integer> j)
//{
//	//가격을 내림차순으로
//	return j.second < i.second;
//
//	//무게가 같으면
//	if (i.first == j.first)
//	{
//
//	}
//
//	//무게를 내림차순으로
//	return j.first < i.first;
//}