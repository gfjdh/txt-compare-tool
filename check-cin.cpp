#include <iostream>
#include <limits>
using namespace std;

int checkcin(int x,int y)
{
	while (1)
	{
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ÇëÖØÐÂÊäÈë:"<<endl;
			cin >> x;
			continue;
		}
		if (x >= 0 && x <= y)
		{
			break;
		}
	}
	return x;
}
