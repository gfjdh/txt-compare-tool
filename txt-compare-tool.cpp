#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

int main()
{
    ofstream write;
    int a = 0, b = 0, c = 0, r = 0, del = 0, x = 0;
    bool d = 0;
    cout << "###########################################################################################" << endl;
    cout << "txt-compare-tool-v0.2" << endl;
    cout << "��ͬ�ô�ѧ�߳���ҵ�ı�У���������ļ����ɹ��ߡ�ʹ��˵����" << endl;
    cout << "1.���������ļ���Ҫ������ʽΪ��test-data8.txt�����ڲ���ʽͬ��ʦget_input_data.exeҪ��" << endl;
    cout << "  �����е�3��8Ӧ�滻������Ҫ����ҵ��ţ���ͬ��" << endl;
    cout << "2.��ʦ����demo����������ʽӦΪ��3-b8-demo.exe���������c���԰汾��Ϊ��3-b8-demo-c.exe��" << endl;
    cout << "3.���c++����������ʽӦΪ��3-b8-1.exe��" << endl;
    cout << "4.���c����������ʽӦΪ��3-b8-2.exe��" << endl;
    cout << "6.�����ļ��ͱ�����Ӧ��ͬһĿ¼��" << endl;
    cout << "7.��ʦ��get_input_data.exe��txt_compare.exeӦ�ѿ���" << endl;
    cout << "8.�������ṩ�Ľ�������ο����������κ���ҵ������Ȿ�˸Ų�����" << endl;
    cout << "###########################################################################################" << endl << endl;
    cout << "��������ҵ��ţ�����3-b8�����룺3����" << endl;
    cin >> x;
    a = checkcin(x,99);
    cout << "��������ҵ��ţ�����3-b8�����룺8����" << endl;
    cin >> x;
    b = checkcin(x,99);
    cout << "�����������������[0,99]��" << endl;
    cin >> x;
    c = checkcin(x, 99);
    cout << "�Ƿ�ֻ��c++��c���򣨽�c++����1����c����2��������0����" << endl;
    cin >> x;
    r = checkcin(x, 2);
    if (r ==0)
    {
        cout << "�Ƿ���Ҫ����demo��demo-c��������1��������0����" << endl;
        cin >> x;
        d = checkcin(x, 1);
    }
    cout << "�Ƿ���Ҫ�Զ�ɾ�����ɵ�result�ļ���������1��������0����" << endl;
    cin >> x;
    del = checkcin(x, 1);

    int i = 0;
    cout << "��ʼ���txtУ���������ļ�" << endl << endl << endl;
    string s = to_string(a) + "-b" + to_string(b) + ".bat";
    write.open(s);
    write << "@echo off" << endl;

    if (c == 0)
        write << a << "-b" << b << "-demo.exe >  " << a << "-b" << b << "-result.txt" << endl;
    else
    {
        i = 1;
        write << "get_input_data test-data" << b << ".txt [" << a << "-b" << b << "-" << setfill('0') << setw(2) << i;
        write << "] | " << a << "-b" << b << "-demo.exe >  " << a << "-b" << b << "-result.txt" << endl;
    }       
    for (i = 2; i <= c; i++)
    {
        write << "get_input_data test-data" << b << ".txt [" << a << "-b" << b << "-" << setfill('0') << setw(2) << i;
        write << "] | " << a << "-b" << b << "-demo.exe >>  " << a << "-b" << b << "-result.txt" << endl;
    }

    if (r == 1 || r ==0)
    {
        if (c == 0)
            write << a << "-b" << b << "-1.exe >  " << a << "-b" << b << "-result1.txt" << endl;
        else
        {
            i = 1;
            write << "get_input_data test-data" << b << ".txt [" << a << "-b" << b << "-" << setfill('0') << setw(2) << i;
            write << "] | " << a << "-b" << b << "-1.exe >  " << a << "-b" << b << "-result1.txt" << endl;
        }
        for (i = 2; i <= c; i++)
        {
            write << "get_input_data test-data" << b << ".txt [" << a << "-b" << b << "-" << setfill('0') << setw(2) << i;
            write << "] | " << a << "-b" << b << "-1.exe >>  " << a << "-b" << b << "-result1.txt" << endl;
        }
    }
    
    if (d)
    {
        if (c == 0)
            write << a << "-b" << b << "-demo-c.exe >  " << a << "-b" << b << "-result.txt" << endl;
        else
        {
            i = 1;
            write << "get_input_data test-data" << b << ".txt [" << a << "-b" << b << "-" << setfill('0') << setw(2) << i;
            write << "] | " << a << "-b" << b << "-demo-c.exe >  " << a << "-b" << b << "-result-c.txt" << endl;
        }
        for (i = 2; i <= c; i++)
        {
            write << "get_input_data test-data" << b << ".txt [" << a << "-b" << b << "-" << setfill('0') << setw(2) << i;
            write << "] | " << a << "-b" << b << "-demo-c.exe >>  " << a << "-b" << b << "-result-c.txt" << endl;
        }
    }

    if (r == 2 || r ==0)
    {
        if (c == 0)
            write << a << "-b" << b << "-2.exe >  " << a << "-b" << b << "-result2.txt" << endl;
        else
        {
            i = 1;
            write << "get_input_data test-data" << b << ".txt [" << a << "-b" << b << "-" << setfill('0') << setw(2) << i;
            write << "] | " << a << "-b" << b << "-2.exe >  " << a << "-b" << b << "-result2.txt" << endl;
        }
        for (i = 2; i <= c; i++)
        {
            write << "get_input_data test-data" << b << ".txt [" << a << "-b" << b << "-" << setfill('0') << setw(2) << i;
            write << "] | " << a << "-b" << b << "-2.exe >>  " << a << "-b" << b << "-result2.txt" << endl;
        }
    }

    write << "@echo on" << endl;
    
    if (!d)
    {
        if (r == 1 || r ==0)
            write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result1.txt --display detailed" << endl;
        if (r == 2 || r ==0)
            write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result2.txt --display detailed" << endl;
    }
    else
    {
        if (r == 1 || r ==0)
            write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result1.txt --display detailed" << endl;
        if (r == 2 || r ==0)
            write << "txt_compare --file1 " << a << "-b" << b << "-result-c.txt --file2 " << a << "-b" << b << "-result2.txt --display detailed" << endl;
    }
    if (del)
    {
        write << "@echo off" << endl;
        write << "del " << a << "-b" << b << "-result.txt" << endl;
        if (d)
            write << "del " << a << "-b" << b << "-result-c.txt" << endl;
        if (r == 1 || r == 0)
            write << "del " << a << "-b" << b << "-result1.txt" << endl;
        if (r == 2 || r == 0)
            write << "del " << a << "-b" << b << "-result2.txt" << endl;
        cout << "result�ļ����Զ�ɾ��" << endl;
    }
    else
        cout << "-result-1.txt�����c++����������-result-2.txt�����c����������������demo�����" << endl;
    write << "pause" << endl;
    cout << "�����ɣ�˫������"<<s<<"�ļ�����һ���ȶ���ҵ������txt" << endl;
    cout << "ע�⣺������������bat�ļ���Ҫɾ�����ļ��������Ҫָ��txt_compare.exe�Ĳ����������޸�"<<s<<"�ļ�" << endl;
    cin >> a;
    return 0;
}