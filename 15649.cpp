#include <iostream>
using namespace std;

int n, m;
//������� ���� �� �迭
int arr[10];
//Ư������ �������� Ȯ�� �迭
bool isused[10];

void Func(int k)
{
	//������̴ϱ� ���ư� ������ �����(base case)
	if (k == m) 
	{
		//�ϼ��� ������� ����ϴ°���
		//�ѹ��� ��Ƽ� ����ϴ°� �ƴ϶� ���ε���
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//��� ���ҿ��� �� �� �ִ� ���Ҹ� ã�� ���ư�
	//������ �Է� ������ 1���ʹϱ� 1���� �����ϴ°���
	for (int i = 1; i <= n; ++i)
	{
		//�Ⱦ� ���Ұ� ���Դ�.
		if (isused[i] == false)
		{
			//����� �߰� ���ְ�
			arr[k] = i;
			//���� ����ߴٰ� �湮ó�� ���ְ�
			isused[i] = 1;
			//��� ����
			Func(k + 1); 
			//������ ���� ���� �ٽ� �湮ó�� ������ְ�
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