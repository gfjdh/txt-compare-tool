#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

//////////////�˺������ںϳ�����ַ���///////////////

string output(int a,int b,int c,string n,string r)   //aΪ��ţ�bΪ��ţ�cΪ��������nΪexe�����׺��rΪreslut��׺
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
        if(i<=9)//��Ҫ��Ϊ�ˡ�-0��
            result += "get_input_data test-data" + to_string(b) + ".txt [" + to_string(a) + "-b" + to_string(b) + "-0" + to_string(i);
        else
            result += "get_input_data test-data" + to_string(b) + ".txt [" + to_string(a) + "-b" + to_string(b) + "-" + to_string(i);
        
        result += "] | " + to_string(a) + "-b" + to_string(b) + n + ".exe >>  " + to_string(a) + "-b" + to_string(b) + "-result" + r + ".txt\n";
    }

    return result;
}