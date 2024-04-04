#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

//////////////�˺����������˵��///////////////
void Readme()
{
    cout << "        ###########################################################################################" << endl;
    cout << "        # txt-compare-tool v1.2                                                                   #" << endl;
    cout << "        # ��ͬ�ô�ѧ�߳���ҵ�ı�У���������ļ����ɹ��ߡ�ʹ��˵����                                #" << endl;
    cout << "        # 1.���������ļ���Ҫ������ʽΪ��test-data8.txt�����ڲ���ʽͬ��ʦget_input_data.exeҪ��    #" << endl;
    cout << "        #  �����е�3��8Ӧ�滻������Ҫ����ҵ��ţ���ͬ��                                           #" << endl;
    cout << "        # 2.��ʦ����demo����������ʽӦΪ��3-b8-demo.exe���������c���԰汾��Ϊ��3-b8-demo-c.exe�� #" << endl;
    cout << "        # 3.���c++����������ʽӦΪ��3-b8-1.exe��,�����dev�汾��Ϊ��3-b8-1-dev.exe��             #" << endl;
    cout << "        # 4.���c����������ʽӦΪ��3-b8-2.exe��,�����dev�汾��Ϊ��3-b8-2-dev.exe��               #" << endl;
    cout << "        # 5.�����ļ��ͱ�����Ӧ��ͬһĿ¼��                                                        #" << endl;
    cout << "        # 6.��ʦ��get_input_data.exe��txt_compare.exeӦ�ѿ���                                     #" << endl;
    cout << "        # 7.bug����;���������                                                                   #" << endl;
    cout << "        # 8.�������ṩ�Ľ�������ο����������κ���ҵ������⿪���߸Ų�����                      #" << endl;
    cout << "        #                                                                                         #" << endl;
    cout << "        #          ��������ӣ��������أ�https://github.com/gfjdh/txt-compare-tool                #" << endl;
    cout << "        ###########################################################################################" << endl << endl;
}


//////////////�˺������ںϳ�"������ҵexe��ָ��"���ַ���///////////////
string createExeRunCommand(int a,int b,int c,string n,string r)   //aΪ��ţ�bΪ��ţ�cΪ��������nΪexe�����׺��rΪreslut��׺
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

//////////////�˺������ںϳ�"�ԱȽ��txt��ָ��"���ַ���///////////////
string createTxtComparisonCommand(int a, int b, string r1, string r2, string c)   //aΪ��ţ�bΪ��ţ�r1Ϊ��һ��txt��׺��r2Ϊ�ڶ���txt��׺, cΪ�û�ָ���Ĳ���
{
    string result;
    result = "txt_compare --file1 " + to_string(a) + "-b" + to_string(b) + "-result"+ r1 +".txt --file2 " 
            + to_string(a) + "-b" + to_string(b) + "-result"+ r2 +".txt --display detailed "+ c +"\n";    
    return result;
}

//////////////�˺�������ɾ��"�ԱȽ��txt��ָ��"���ַ���///////////////
string createTxtDeleteCommand(int a, int b, string r)   //aΪ��ţ�bΪ��ţ�rΪtxt��׺
{
    string result;
    result = "del " + to_string(a) + "-b" + to_string(b) + "-result" + r + ".txt\n";
    return result;
}