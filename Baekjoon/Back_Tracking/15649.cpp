#include <iostream>
using namespace std;

int n, m;
//결과값을 저장 할 배열
int arr[10];
//특정수가 쓰였는지 확인 배열
bool isused[10];

void Func(int k)
{
	//재귀형이니까 돌아갈 조건을 세운다(base case)
	if (k == m) 
	{
		//완성된 결과물을 출력하는거임
		//한번에 모아서 출력하는게 아니라 따로따로
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//모든 원소에서 들어갈 수 있는 원소를 찾고 돌아감
	//문제의 입력 범위가 1부터니까 1부터 시작하는것임
	for (int i = 1; i <= n; ++i)
	{
		//안쓴 원소가 나왔다.
		if (isused[i] == false)
		{
			//결과에 추가 해주고
			arr[k] = i;
			//원소 사용했다고 방문처리 해주고
			isused[i] = 1;
			//재귀 들어가고
			Func(k + 1); 
			//나오면 이제 원소 다시 방문처리 취소해주고
			isused[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	Func(0);

	return 0;
}