#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int testCaseMany = 0;
	scanf("%d", &testCaseMany);

	for (int i = 0; i < testCaseMany; ++i)
	{///�� �׽�Ʈ ���̽��� ���� ������ �ο����� ���⼭ �ݺ����� ����ؾ� ��
		
		int volunteerMany = 0;
		scanf("%d", &volunteerMany);

		vector<pair<int, int>> list;

		//������ ���� ���� ����
		for (int j = 0; j < volunteerMany; ++j)
		{
			int grade_1, grade_2;
			scanf("%d %d", &grade_1, &grade_2);
			list.push_back(make_pair(grade_1, grade_2));
		}

		//�����ɻ� �������� �������� ����
		sort(list.begin(), list.end());

		//�ڽź��� �����ɻ� ������ ���� �ο��� ���� �������� ��
		int passCnt = 1; //�̹� �����ɻ� ���� 1���� �߰��Ѱ�.
		int highGrade = list[0].second;
		for (int j = 1; j < volunteerMany; ++j)
		{
			if (list[j].second < highGrade)
			{//�հ�
				++passCnt;
				highGrade = list[j].second;
			}
		}
		printf("%d\n", passCnt);
	}
	return 0;
}

//���� ���ص� �� for�� �ۼ��ߴ���

////�ڽź��� �����ɻ� ������ ���� �ο��� ���� �������� ��
//int passCnt = 1; //�̹� �����ɻ� ���� 1���� �߰��Ѱ�.
//bool isPass = false;
//for (int j = 1; j < volunteerMany; ++j)
//{
//	for (int k = j - 1; 0 <= k; --k)
//	{
//		if (list[k].second < list[j].second)
//		{//Ż��
//			isPass = false;
//			break;
//		}
//		else
//		{
//			isPass = true;
//		}
//	}
//	if (isPass == true)
//		++passCnt;
//}