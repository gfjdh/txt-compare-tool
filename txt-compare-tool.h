#include <iostream>
using namespace std;

void Readme();

int CheckCin(int x,int y);//x���������yΪ����

string createExeRunCommand(int a, int b, int c, string n, string r);   //aΪ��ţ�bΪ��ţ�cΪ��������nΪexe�����׺��rΪreslut��׺

string createTxtComparisonCommand(int a, int b, string r1, string r2, string c);   //aΪ��ţ�bΪ��ţ�r1Ϊ��һ��txt��׺��r2Ϊ�ڶ���txt��׺, cΪ�û�ָ���Ĳ���

string createTxtDeleteCommand(int a, int b, string r);   //aΪ��ţ�bΪ��ţ�rΪtxt��׺
