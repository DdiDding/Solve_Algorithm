//#include <iostream>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//
//	return 0;
//}
///*
//거주조건
//a층의 b호에 살려면
//a-1층의 1호부터 b호까지 사람들의 수의 합만큼 사ㅏㄻ들을 데려와 살아야한다.
//
//즉 2층 3호에 살려면
//1층 1호, 1층 2호, 1층 3호의 사람의 합만큼 데리고 입주해야한다.
//
//
//1층 1호 = 1, 2호 - 3, 3호 - 6, 4호 - 10
//
//1 + 3 + 6 + 10
//
//3층:	1	5	15	25	60	116	200	420	585	805
//2층:	1	4	10	20	35	56	84	120	165	220
//1층:	1	3	6	10	15	21	28	36	45	55	66	78	91	105
//0층:	1	2	3	4	5	6	7	8	9	10	11	12	13	14
//
//[k][n] = [k][n -1] + [k - 1][n]
//
//
//
//비어있는 집이 없다.
//
//k, n 에 대해 
//k층에 n호에는 몇명이 살고있는가??
//
//아파트는 0층부터 있고 1호부터있다.
//
//
//*
///