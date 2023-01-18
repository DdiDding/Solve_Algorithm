#include <iostream>
#include <string.h>
#include <set>
using namespace std;

set<int> friends[11];
bool check[11];

/* start - 찾으려는 학생
 * maxi - 총 학생 수
 * cnt - 짝을 지어야 하는 수, 짝을 지을때마다 감소하여 최종 0이 된다.
 */
void Self(const int & maxi, int cnt, int & result)
{
	//모든 학생을 다 짝지었는지 확인
	if (cnt == 0)
	{
		++result;
		return;
	}

	//시작할 학생 찾기
	//특징은 제일 앞의 학생을 찾는다는 것이다. 중요!
	//발견하지 못했을때를 생각못했다.
	int start;
	for (int i = 0; i < maxi; ++i)
	{
		if (check[i] == false)
		{
			start = i;
			break;
		}
	}

	//짝을 짓기
	for (int i = start + 1; i < maxi; ++i)
	{
		//start학생이 아니고 아직 짝이 지어지지 않았다면
		if (check[i] == false)
		{
			//서로 친구라면
			if (friends[start].find(i) != friends[start].end())
			{
				//짝을 지었다는 체크를 해주고
				check[start] = true;
				check[i] = true;

				//다음 학생을 찾는다.
				Self(maxi, cnt - 1, result);

				check[start] = false;
				check[i] = false;
			}
		}
	}
}

int main()
{
	//1.Input & Init data

	int C; cin >> C;
	while (C--)
	{
		int n, m; cin >> n >> m;

		//친구 체크하기
		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			friends[a].insert(b);
			friends[b].insert(a);
		}
		
		int result = 0;
		Self(n, n / 2, result);

		cout << result << '\n';

		memset(check, 0, sizeof(check));
		for (auto & d : friends)
		{
			d.clear();
		}
	}

	return 0;
}
/*
소풍을 간다.
학생을 두명씩 짝짓는다.
친구인 학생들끼리 짞짓는다.

테스트 케이스의 수 C
학생의수, 친구 쌍의 수

모든 경우의 수에서 각 쌍이 친구가 맞을때의 수를 카운팅하면 될거 같다!

부분문제를 생각해보자

0번 학생부터 짝을 지어간다.
친구라면 짝을 짓고 다음 학생으로 넘어간다.

해당 학생부터 짝을 지어간다.
친구라면 짝을 짓고 다음 학생으로 넘어간다.

--------------
0번 학생부터 짝을 지어간다.
짝을 지으려는 학생이 이미 짝이 지어졌는지 확인
친구인지도 확인
친구라면 짝을 짓고 다시 처음부터 시작

친구관계를 처음에는 vector<int>의 배열로 하려했는데
생각해보니 이건 그래프보다는 바로바로 검색해서 찾을수있는게 좋을것같아서
set?

*/
//
int n;
bool areFriends[10][10];

int Counting(bool taken[10])
{
	//가장 빠른 번호를 찾는다.
	bool first = -1;
	for (int i = 0; i < n; ++i)
	{
		if (taken[i] == false)
		{
			first = i;
			break;
		}
	}

	//기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (first == -1) return 1;

	int ret = 0;
	//짝지을 학생을 결정하기
	for (int second = first + 1; second < n; ++second)
	{
		if (taken[second] == false && areFriends[first][second])
		{
			taken[first] = taken[second] = true;
			ret += Counting(taken);
			taken[first] = taken[second] = false;
		}
	}
	return ret;
}
//이중 반복문처럼 보이는데 사실은 처음부터끝까지 반복하는것과 다름없다.
