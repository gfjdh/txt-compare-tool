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
    cout << "《同济大学高程作业文本校对批处理文件生成工具》使用说明：" << endl;
    cout << "1.测试数据文件需要命名格式为“test-data8.txt”，内部格式同老师get_input_data.exe要求" << endl;
    cout << "  （其中的3和8应替换成你需要的作业编号，下同）" << endl;
    cout << "2.老师给的demo程序命名格式应为‘3-b8-demo.exe’，如果有c语言版本则为‘3-b8-demo-c.exe’" << endl;
    cout << "3.你的c++程序命名格式应为‘3-b8-1.exe’" << endl;
    cout << "4.你的c程序命名格式应为‘3-b8-2.exe’" << endl;
    cout << "6.以上文件和本工具应在同一目录下" << endl;
    cout << "7.老师的get_input_data.exe和txt_compare.exe应已可用" << endl;
    cout << "8.本工具提供的结果仅供参考，如果造成任何作业相关问题本人概不负责" << endl;
    cout << "###########################################################################################" << endl << endl;
    cout << "请输入作业组号（例：3-b8则输入：3）：" << endl;
    cin >> x;
    a = checkcin(x,99);
    cout << "请输入作业组号（例：3-b8则输入：8）：" << endl;
    cin >> x;
    b = checkcin(x,99);
    cout << "请输入测试数据总数[0,99]：" << endl;
    cin >> x;
    c = checkcin(x, 99);
    cout << "是否只有c++或c程序（仅c++输入1，仅c输入2，否输入0）：" << endl;
    cin >> x;
    r = checkcin(x, 2);
    if (r ==0)
    {
        cout << "是否需要区分demo和demo-c（是输入1，否输入0）：" << endl;
        cin >> x;
        d = checkcin(x, 1);
    }
    cout << "是否需要自动删除生成的result文件（是输入1，否输入0）：" << endl;
    cin >> x;
    del = checkcin(x, 1);

    int i = 0;
    cout << "开始输出txt校验批处理文件" << endl << endl << endl;
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
        cout << "result文件已自动删除" << endl;
    }
    else
        cout << "-result-1.txt是你的c++程序的输出，-result-2.txt是你的c程序的输出，其余是demo的输出" << endl;
    write << "pause" << endl;
    cout << "输出完成，双击运行"<<s<<"文件即可一键比对作业输出结果txt" << endl;
    cout << "注意：如需重新生成bat文件需要删除旧文件，如果需要指定txt_compare.exe的参数可自行修改"<<s<<"文件" << endl;
    cin >> a;
    return 0;
}