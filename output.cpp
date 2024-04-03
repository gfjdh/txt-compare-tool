#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

//////////////此函数用于合成输出字符串///////////////

string output(int a,int b,int c,string n,string r)   //a为组号，b为序号，c为数据数，n为exe程序后缀，r为reslut后缀
{
    string result;
    int i = 1;
    if (c == 0)
        result = to_string(a) + "-b" + to_string(b) + n + ".exe >   " + to_string(a) + "-b" + to_string(b) + "-result" + r + ".txt\n";
    else
    {       
        result = "get_input_data test-data" + to_string(b) + ".txt [" + to_string(a) + "-b" + to_string(b) + "-0" + to_string(i);
        result += "] | " + to_string(a) + "-b" + to_string(b) + n + ".exe >   " + to_string(a) + "-b" + to_string(b) + "-result" + r + ".txt\n";
    }

    for (i = 2; i <= c; i++)
    {
        if(i<=9)//主要是为了“-0”
            result += "get_input_data test-data" + to_string(b) + ".txt [" + to_string(a) + "-b" + to_string(b) + "-0" + to_string(i);
        else
            result += "get_input_data test-data" + to_string(b) + ".txt [" + to_string(a) + "-b" + to_string(b) + "-" + to_string(i);
        
        result += "] | " + to_string(a) + "-b" + to_string(b) + n + ".exe >>  " + to_string(a) + "-b" + to_string(b) + "-result" + r + ".txt\n";
    }

    return result;
}