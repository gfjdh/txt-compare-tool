#include <iostream>
#include <iomanip>
#include <cstdio>
#include <limits>
using namespace std;

//////////////�˺������������������//////////

int checkcin(int x,int y)//x���������yΪ����
{
	while (1)
	{
		if (!cin.good() || !(x >= 0 && x <= y))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����Ƿ�������������:"<<endl;
			cin >> x;
			continue;
		}
		else
			break;
	}
	return x;
}