#include <iostream>
using namespace std;

void Readme();

int CheckCin(int x,int y);//x待检查数，y为上限

string createExeRunCommand(int a, int b, int c, string n, string r);   //a为组号，b为序号，c为数据数，n为exe程序后缀，r为reslut后缀

string createTxtComparisonCommand(int a, int b, string r1, string r2, string c);   //a为组号，b为序号，r1为第一个txt后缀，r2为第二个txt后缀, c为用户指定的参数

string createTxtDeleteCommand(int a, int b, string r);   //a为组号，b为序号，r为txt后缀
