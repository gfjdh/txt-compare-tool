#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

int main()
{
    Readme();
    /////////////////////////////////////////////////以下是用户输入部分/////////////////////////////////////////////////////

    int a = 0, b = 0, c = 0, r = 0, x = 0;     //a为组号，b为序号，c为测试数据数，r为语言选项参数，x为输入中间变量;
    bool d = 0, del = 0, dev = 0, autodata = 0;     //d为demo区分选项参数，del为删除选项参数，dev为编译器选项参数。autodata为生成数据模板选项参数
    string parameter = "";    //用户指定的txt-compare.exe的参数

    cout << " ①请输入作业组号（例：3-b8则输入：3）：" << endl;
    cin >> x;
    a = CheckCin(x,99);
    system("cls");
    cout << " ②请输入作业编号（例：3-b8则输入：8）：" << endl;
    cin >> x;
    b = CheckCin(x,99);
    system("cls");
    cout << " ③请输入测试数据总数[0,99]：" << endl;
    cin >> x;
    c = CheckCin(x, 99);
    system("cls");

    if (c != 0)
    {
        cout << " 是否需要生成测试数据模板（是输入1，否输入0）：" << endl;
        x = _getch() - 48;
        autodata = CheckCin(x, 1);
        system("cls");
        if (autodata)
        {
            DataCreate(a, b, c);
            system("pause");
            return 0;
        }
    }

    cout << " ④是否只有c++或c程序（仅c++输入1，仅c输入2，否输入0）：" << endl;
    x = _getch() - 48;
    r = CheckCin(x, 2);
    if (r ==0)
    {
        cout << " 是否需要区分demo和demo-c（是输入1，否输入0）：" << endl;
        x = _getch() - 48;
        d = CheckCin(x, 1);
    }
    system("cls");
    cout << " ⑤是否需要区分VS(默认仅vs)和dev（是输入1，否输入0）:" << endl;
    x = _getch() - 48;
    dev = CheckCin(x, 1);
    system("cls");
    cout << " ⑥是否需要指定txt-compare.exe的参数（是输入1，否输入0）：" << endl;
    x = _getch() - 48;
    x = CheckCin(x, 1);
    if (x == 1)
    {
        cout << " 请在一行内输入您要指定的参数(参数均需带有--)" << endl;
        cin.ignore();
        getline(cin, parameter);
    }
    system("cls");
    cout << " ⑦是否需要自动删除生成的result文件（是输入1，否输入0）：" << endl;
    x = _getch() - 48;
    del = CheckCin(x, 1);
    system("cls");
    /////////////////////////////////////////////////以上是用户输入部分/////////////////////////////////////////////////////
    /////////////////////////////////////////////////以下是输出部分/////////////////////////////////////////////////////
    cout << endl << "开始输出txt校验批处理文件" << endl << endl;
    string s = to_string(a) + "-b" + to_string(b) + ".bat";
    ofstream write;
    write.open(s);

    write << "@echo off" << endl;  //以下功能是打印 运行作业exe的指令

    write << createExeRunCommand(a, b, c, "-demo", "");   //a为组号，b为序号，c为数据数，n为exe程序后缀，r为reslut后缀;
                                             //打印输出demo的结果的命令
    if (d)               //如果区分demo，打印输出demo-c的结果的命令
        write << createExeRunCommand(a, b, c, "-demo-c", "-c");

    if (r <= 1)
    {
        write << createExeRunCommand(a, b, c, "-1", "1");
        if (dev)         //如果区分dev，打印输出1-dev.exe的结果的命令
            write << createExeRunCommand(a, b, c, "-1-dev", "1-dev");
    }
    if (r != 1)
    {
        write << createExeRunCommand(a, b, c, "-2", "2");
        if (dev)        //如果区分dev，打印输出2-dev.exe的结果的命令
            write << createExeRunCommand(a, b, c, "-2-dev", "2-dev");
    }

    write << "@echo on" << endl; //以下功能是打印 对比结果txt的指令
    
    if (d)   //如果区分demo
    {
        if (r <= 1)
        {
            write << createTxtComparisonCommand(a, b, "", "1", parameter);   //a为组号，b为序号，r1为第一个txt后缀，r2为第二个txt后缀;
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
    else  //不区分demo
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

    if (del)  //以下功能是打印 删除结果txt文档的指令
    {
        write << "@echo off" << endl;

        write << createTxtDeleteCommand(a, b, "");   //a为组号，b为序号，r为txt后缀
        if (d)   //如果区分demo
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

        cout << "result文件将自动删除" << endl << endl;
    }
    else
        cout << "运行bat文件后，-result-1.txt是你的c++程序的输出，-result-2.txt是你的c程序的输出，-result是demo的输出" << endl << endl;
    write << "pause" << endl;
    /////////////////////////////////////////////////以上是输出部分/////////////////////////////////////////////////////
    const char* bat = s.c_str();
    cout << endl << "输出完成，即将自动运行bat文件，此后双击运行" << s << "文件即可一键比对作业输出结果txt" << endl;
    cout << "如果长时间卡死可能是demo或你的程序陷入死循环，请检查测试数据和程序后重新运行" << s << "文件" << endl;
    cout << "注意：如需重新生成" << s << "文件需要删除旧文件" << endl;
    system(bat);
    cout << s << "运行完成" << endl;
    system("pause");
    return 0;
}