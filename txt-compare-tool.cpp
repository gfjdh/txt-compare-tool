#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

int main()
{
    Readme();
    /////////////////////////////////////////////////�������û����벿��/////////////////////////////////////////////////////

    int a = 0, b = 0, c = 0, r = 0, x = 0;     //aΪ��ţ�bΪ��ţ�cΪ������������rΪ����ѡ�������xΪ�����м����;
    bool d = 0, del = 0, dev = 0;     //dΪdemo����ѡ�������delΪɾ��ѡ�������devΪ������ѡ�������
    string parameter = "";    //�û�ָ����txt-compare.exe�Ĳ���

    cout << "��������ҵ��ţ�����3-b8�����룺3����" << endl;
    cin >> x;
    a = CheckCin(x,99);

    cout << "��������ҵ��ţ�����3-b8�����룺8����" << endl;
    cin >> x;
    b = CheckCin(x,99);

    cout << "�����������������[0,99]��" << endl;
    cin >> x;
    c = CheckCin(x, 99);

    cout << "�Ƿ�ֻ��c++��c���򣨽�c++����1����c����2��������0����" << endl;
    cin >> x;
    r = CheckCin(x, 2);
    if (r ==0)
    {
        cout << "�Ƿ���Ҫ����demo��demo-c��������1��������0����" << endl;
        cin >> x;
        d = CheckCin(x, 1);
    }

    cout << "�Ƿ���Ҫ����VS(Ĭ�Ͻ�vs)��dev��������1��������0��:" << endl;
    cin >> x;
    dev = CheckCin(x, 1);

    cout << "�Ƿ���Ҫָ��txt-compare.exe�Ĳ�����������1��������0����" << endl;
    cin >> x;
    x = CheckCin(x, 1);
    if (x == 1)
    {
        cout << "����һ����������Ҫָ���Ĳ���(�����������--)" << endl;
        getchar();
        getline(cin, parameter);
    }

    cout << "�Ƿ���Ҫ�Զ�ɾ�����ɵ�result�ļ���������1��������0����" << endl;
    cin >> x;
    del = CheckCin(x, 1);
    /////////////////////////////////////////////////�������û����벿��/////////////////////////////////////////////////////
    /////////////////////////////////////////////////�������������/////////////////////////////////////////////////////
    cout << endl << "��ʼ���txtУ���������ļ�" << endl << endl;
    string s = to_string(a) + "-b" + to_string(b) + ".bat";
    ofstream write;
    write.open(s);

    write << "@echo off" << endl;  //���¹����Ǵ�ӡ ������ҵexe��ָ��

    write << createExeRunCommand(a, b, c, "-demo", "");   //aΪ��ţ�bΪ��ţ�cΪ��������nΪexe�����׺��rΪreslut��׺;
                                             //��ӡ���demo�Ľ��������
    if (d)               //�������demo����ӡ���demo-c�Ľ��������
        write << createExeRunCommand(a, b, c, "-demo-c", "-c");

    if (r <= 1)
    {
        write << createExeRunCommand(a, b, c, "-1", "1");
        if (dev)         //�������dev����ӡ���1-dev.exe�Ľ��������
            write << createExeRunCommand(a, b, c, "-2-dev", "2-dev");
    }
    if (r != 1)
    {
        write << createExeRunCommand(a, b, c, "-2", "2");
        if (dev)        //�������dev����ӡ���2-dev.exe�Ľ��������
            write << createExeRunCommand(a, b, c, "-1-dev", "1-dev");
    }

    write << "@echo on" << endl; //���¹����Ǵ�ӡ �ԱȽ��txt��ָ��
    
    if (d)   //�������demo
    {
        if (r <= 1)
        {
            write << createTxtComparisonCommand(a, b, "", "1", parameter);   //aΪ��ţ�bΪ��ţ�r1Ϊ��һ��txt��׺��r2Ϊ�ڶ���txt��׺;
            if (dev)         
                write << createTxtComparisonCommand(a, b, "", "1-dev", parameter);
        }
        if (r != 1)
        {
            write << createTxtComparisonCommand(a, b, "-c", "2", parameter);
            if (dev)        
                write << createTxtComparisonCommand(a, b, "", "2-dev", parameter);
        } 
    }
    else  //������demo
    {
        if (r <= 1)
        {
            write << createTxtComparisonCommand(a, b, "", "1", parameter);
            if (dev)
                write << createTxtComparisonCommand(a, b, "", "1-dev", parameter);
        }
        if (r != 1)
        {
            write << createTxtComparisonCommand(a, b, "", "2", parameter);
            if (dev)
                write << createTxtComparisonCommand(a, b, "", "2-dev", parameter);
        }
    }

    if (del)  //���¹����Ǵ�ӡ ɾ�����txt�ĵ���ָ��
    {
        write << "@echo off" << endl;

        write << createTxtDeleteCommand(a, b, "");   //aΪ��ţ�bΪ��ţ�rΪtxt��׺
        if (d)   //�������demo
            write << createTxtDeleteCommand(a, b, "-c");

        if (r <= 1)
        {
            write << createTxtDeleteCommand(a, b, "1");
            if (dev)
                write << createTxtDeleteCommand(a, b, "1-dev");
        }
        if (r != 1)
        {
            write << createTxtDeleteCommand(a, b, "2");
            if (dev)
                write << createTxtDeleteCommand(a, b, "2-dev");
        }

        cout << "result�ļ����Զ�ɾ��" << endl << endl;
    }
    else
        cout << "����bat�ļ���-result-1.txt�����c++����������-result-2.txt�����c����������-result��demo�����" << endl << endl;
    write << "pause" << endl;

    /////////////////////////////////////////////////�������������/////////////////////////////////////////////////////

    cout << "�����ɣ��رձ����ں�˫������" << s << "�ļ�����һ���ȶ���ҵ������txt" << endl;
    cout << "��һ������bat�����п������󣬹رմ����������м���" << endl << endl;
    cout << "ע�⣺������������" << s << "�ļ���Ҫɾ�����ļ�" << endl;

    cin >> a;
    return 0;
}