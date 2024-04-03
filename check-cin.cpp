#include <iostream>
#include <iomanip>
#include <cstdio>
#include <limits>
using namespace std;

//////////////此函数用于整数输入检验//////////

int checkcin(int x,int y)//x待检查数，y为上限
{
	while (1)
	{
		if (!cin.good() || !(x >= 0 && x <= y))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入:"<<endl;
			cin >> x;
			continue;
		}
		else
			break;
	}
	return x;
}