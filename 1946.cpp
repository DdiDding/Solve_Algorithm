#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int testCaseMany = 0;
	scanf("%d", &testCaseMany);

	for (int i = 0; i < testCaseMany; ++i)
	{///각 테스트 케이스에 대해 선발할 인원수가 여기서 반복마다 출력해야 함
		
		int volunteerMany = 0;
		scanf("%d", &volunteerMany);

		vector<pair<int, int>> list;

		//점수를 페어로 묶어 저장
		for (int j = 0; j < volunteerMany; ++j)
		{
			int grade_1, grade_2;
			scanf("%d %d", &grade_1, &grade_2);
			list.push_back(make_pair(grade_1, grade_2));
		}

		//서류심사 성적으로 오름차순 정렬
		sort(list.begin(), list.end());

		//자신보다 서류심사 성적이 좋은 인원과 나의 면접성적 비교
		int passCnt = 1; //이미 서류심사 성적 1등을 추가한것.
		int highGrade = list[0].second;
		for (int j = 1; j < volunteerMany; ++j)
		{
			if (list[j].second < highGrade)
			{//합격
				++passCnt;
				highGrade = list[j].second;
			}
		}
		printf("%d\n", passCnt);
	}
	return 0;
}

//내가 안해도 될 for문 작성했던것

////자신보다 서류심사 성적이 좋은 인원과 나의 면접성적 비교
//int passCnt = 1; //이미 서류심사 성적 1등을 추가한것.
//bool isPass = false;
//for (int j = 1; j < volunteerMany; ++j)
//{
//	for (int k = j - 1; 0 <= k; --k)
//	{
//		if (list[k].second < list[j].second)
//		{//탈락
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