#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

void DataCreate(int a,int b,int c)  //a为组号，b为序号，c为测试数据数
{
    cout << endl << " 开始输出测试数据模板文件" << endl << endl;
    string s = "test-data" + to_string(b) + ".txt";
    ofstream write;
    write.open(s);
    for (int i = 1; i <= c; i++)
    {
        if (i <= 9)//主要是为了“-0”
            write << "[" << to_string(a) << "-b" << to_string(b) << "-0" << to_string(i) << "]\n";
        else
            write << "[" << to_string(a) << "-b" << to_string(b) << "-" << to_string(i) << "]\n";
        write << i << "\n\n";
    }
    cout << endl << " 输出完成，请自行修改"<< s <<"文件中的数据后重新运行本程序"<< endl << endl;
}