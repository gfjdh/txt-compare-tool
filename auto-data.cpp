#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

void DataCreate(int a,int b,int c)  //aΪ��ţ�bΪ��ţ�cΪ����������
{
    cout << endl << " ��ʼ�����������ģ���ļ�" << endl << endl;
    string s = "test-data" + to_string(b) + ".txt";
    ofstream write;
    write.open(s);
    for (int i = 1; i <= c; i++)
    {
        if (i <= 9)//��Ҫ��Ϊ�ˡ�-0��
            write << "[" << to_string(a) << "-b" << to_string(b) << "-0" << to_string(i) << "]\n";
        else
            write << "[" << to_string(a) << "-b" << to_string(b) << "-" << to_string(i) << "]\n";
        write << i << "\n\n";
    }
    cout << endl << " �����ɣ��������޸�"<< s <<"�ļ��е����ݺ��������б�����"<< endl << endl;
}