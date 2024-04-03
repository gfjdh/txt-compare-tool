#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

int main()
{
    cout << "###########################################################################################" << endl;
    cout << "# txt-compare-tool v1.1                                                                   #" << endl;
    cout << "# ��ͬ�ô�ѧ�߳���ҵ�ı�У���������ļ����ɹ��ߡ�ʹ��˵����                                #" << endl;
    cout << "# 1.���������ļ���Ҫ������ʽΪ��test-data8.txt�����ڲ���ʽͬ��ʦget_input_data.exeҪ��    #" << endl;
    cout << "#  �����е�3��8Ӧ�滻������Ҫ����ҵ��ţ���ͬ��                                           #" << endl;
    cout << "# 2.��ʦ����demo����������ʽӦΪ��3-b8-demo.exe���������c���԰汾��Ϊ��3-b8-demo-c.exe�� #" << endl;
    cout << "# 3.���c++����������ʽӦΪ��3-b8-1.exe��,�����dev�汾��Ϊ��3-b8-1-dev.exe��             #" << endl;
    cout << "# 4.���c����������ʽӦΪ��3-b8-2.exe��,�����dev�汾��Ϊ��3-b8-2-dev.exe��               #" << endl;
    cout << "# 5.�����ļ��ͱ�����Ӧ��ͬһĿ¼��                                                        #" << endl;
    cout << "# 6.��ʦ��get_input_data.exe��txt_compare.exeӦ�ѿ���                                     #" << endl;
    cout << "# 7.bug����;���������                                                                   #" << endl;
    cout << "# 8.�������ṩ�Ľ�������ο����������κ���ҵ������⿪���߸Ų�����                      #" << endl;
    cout << "#                                                                                         #" << endl;
    cout << "#          ��������ӣ��������أ�https://github.com/gfjdh/txt-compare-tool                #" << endl;
    cout << "###########################################################################################" << endl << endl;

    /////////////////////////////////////////////////������˵������/////////////////////////////////////////////////////////
    /////////////////////////////////////////////////�������û����벿��/////////////////////////////////////////////////////

    int a = 0, b = 0, c = 0, r = 0, x = 0; //aΪ��ţ�bΪ��ţ�cΪ������������rΪ����ѡ�������xΪ�����м����;
    bool d = 0, del = 0, dev = 0; //dΪdemo����ѡ�������delΪɾ��ѡ�������devΪ������ѡ�������
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
    cout << "�Ƿ���Ҫ����VS(Ĭ�Ͻ�vs)��dev��������1��������0��:" << endl;
    cin >> x;
    dev = checkcin(x, 1);
    cout << "�Ƿ���Ҫ�Զ�ɾ�����ɵ�result�ļ���������1��������0����" << endl;
    cin >> x;
    del = checkcin(x, 1);

    /////////////////////////////////////////////////�������û����벿��/////////////////////////////////////////////////////
    /////////////////////////////////////////////////�������������/////////////////////////////////////////////////////
    cout << "��ʼ���txtУ���������ļ�" << endl << endl << endl;
    string s = to_string(a) + "-b" + to_string(b) + ".bat";
    ofstream write;
    write.open(s);

    write << "@echo off" << endl;  //���¹����Ǵ�ӡ ������ҵexe��ָ��

    write << output(a, b, c, "-demo", "");   //aΪ��ţ�bΪ��ţ�cΪ��������nΪexe�����׺��rΪreslut��׺;
                                             //��ӡ���demo�Ľ��������
    if (d)               //�������demo����ӡ���demo-c�Ľ��������
        write << output(a, b, c, "-demo-c", "-c");

    if (r <= 1)
    {
        write << output(a, b, c, "-1", "1");
        if (dev)         //�������dev����ӡ���1-dev.exe�Ľ��������
            write << output(a, b, c, "-2-dev", "2-dev");
    }
    if (r != 1)
    {
        write << output(a, b, c, "-2", "2");
        if (dev)        //�������dev����ӡ���2-dev.exe�Ľ��������
            write << output(a, b, c, "-1-dev", "1-dev");
    }

    write << "@echo on" << endl; //���¹����Ǵ�ӡ �ԱȽ��txt��ָ��
    
    if (d)   //�������demo
    {
        if (r <= 1)
        {
            write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result1.txt --display detailed" << endl;
            if (dev)         
                write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result1-dev.txt --display detailed" << endl;
        }
        if (r != 1)
        {
            write << "txt_compare --file1 " << a << "-b" << b << "-result-c.txt --file2 " << a << "-b" << b << "-result2.txt --display detailed" << endl;
            if (dev)        
                write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result2-dev.txt --display detailed" << endl;
        } 
    }
    else  //������demo
    {
        if (r <= 1)
        {
            write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result1.txt --display detailed" << endl;
            if (dev)
                write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result1-dev.txt --display detailed" << endl;
        }
        if (r != 1)
        {
            write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result2.txt --display detailed" << endl;
            if (dev)
                write << "txt_compare --file1 " << a << "-b" << b << "-result.txt --file2 " << a << "-b" << b << "-result2-dev.txt --display detailed" << endl;
        }
    }

    if (del)  //���¹����Ǵ�ӡ ɾ�����txt�ĵ���ָ��
    {
        write << "@echo off" << endl;

        write << "del " << a << "-b" << b << "-result.txt" << endl;
        if (d)   //�������demo
            write << "del " << a << "-b" << b << "-result-c.txt" << endl;

        if (r <= 1)
        {
            write << "del " << a << "-b" << b << "-result1.txt" << endl;
            if (dev)
                write << "del " << a << "-b" << b << "-result1-dev.txt" << endl;
        }
        if (r != 1)
        {
            write << "del " << a << "-b" << b << "-result2.txt" << endl;
            if (dev)
                write << "del " << a << "-b" << b << "-result2-dev.txt" << endl;
        }

        cout << "result�ļ����Զ�ɾ��" << endl << endl;
    }
    else
        cout << "����bat�ļ���-result-1.txt�����c++����������-result-2.txt�����c����������-result��demo�����" << endl << endl;
    write << "pause" << endl;

    /////////////////////////////////////////////////�������������/////////////////////////////////////////////////////

    cout << "�����ɣ��رձ����ں�˫������" << s << "�ļ�����һ���ȶ���ҵ������txt" << endl;
    cout << "��һ������bat�����п������󣬹رմ����������м���" << endl << endl;
    cout << "ע�⣺������������" << s << "�ļ���Ҫɾ�����ļ��������Ҫָ��txt_compare.exe�Ĳ����������޸�" << s << "�ļ�" << endl << endl;

    cin >> a;
    return 0;
}