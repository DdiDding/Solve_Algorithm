#include<iostream>
#include<string>
#include <sstream>
#include <cctype>
#include <vector>
#include <stdlib.h>

using namespace std;


void main()
{
#include <cctype>
//isdigit(char)�� ��ȯ ���� 0�̸� �����̰� �ƴϸ� ������
//���� �ϳ��ϳ��� �Ǻ��ذ��¹��
string str = "1233BVBBA";

for (int i = 0; i < str.length(); ++i)
{
	if (isdigit(str[i]) == 0) cout << "������";
	else cout << "������";
}
	
	return;
}