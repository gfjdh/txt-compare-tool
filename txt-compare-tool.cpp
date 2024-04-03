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
    cout << "# 《同济大学高程作业文本校对批处理文件生成工具》使用说明：                                #" << endl;
    cout << "# 1.测试数据文件需要命名格式为“test-data8.txt”，内部格式同老师get_input_data.exe要求    #" << endl;
    cout << "#  （其中的3和8应替换成你需要的作业编号，下同）                                           #" << endl;
    cout << "# 2.老师给的demo程序命名格式应为‘3-b8-demo.exe’，如果有c语言版本则为‘3-b8-demo-c.exe’ #" << endl;
    cout << "# 3.你的c++程序命名格式应为‘3-b8-1.exe’,如果有dev版本则为‘3-b8-1-dev.exe’             #" << endl;
    cout << "# 4.你的c程序命名格式应为‘3-b8-2.exe’,如果有dev版本则为‘3-b8-2-dev.exe’               #" << endl;
    cout << "# 5.以上文件和本工具应在同一目录下                                                        #" << endl;
    cout << "# 6.老师的get_input_data.exe和txt_compare.exe应已可用                                     #" << endl;
    cout << "# 7.bug反馈途径见储存库                                                                   #" << endl;
    cout << "# 8.本工具提供的结果仅供参考，如果造成任何作业相关问题开发者概不负责                      #" << endl;
    cout << "#                                                                                         #" << endl;
    cout << "#          储存库链接（更新下载）https://github.com/gfjdh/txt-compare-tool                #" << endl;
    cout << "###########################################################################################" << endl << endl;

    /////////////////////////////////////////////////以上是说明部分/////////////////////////////////////////////////////////
    /////////////////////////////////////////////////以下是用户输入部分/////////////////////////////////////////////////////

    int a = 0, b = 0, c = 0, r = 0, x = 0; //a为组号，b为序号，c为测试数据数，r为语言选项参数，x为输入中间变量;
    bool d = 0, del = 0, dev = 0; //d为demo区分选项参数，del为删除选项参数，dev为编译器选项参数；
    cout << "请输入作业组号（例：3-b8则输入：3）：" << endl;
    cin >> x;
    a = checkcin(x,99);
    cout << "请输入作业编号（例：3-b8则输入：8）：" << endl;
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
    cout << "是否需要区分VS(默认仅vs)和dev（是输入1，否输入0）:" << endl;
    cin >> x;
    dev = checkcin(x, 1);
    cout << "是否需要自动删除生成的result文件（是输入1，否输入0）：" << endl;
    cin >> x;
    del = checkcin(x, 1);

    /////////////////////////////////////////////////以上是用户输入部分/////////////////////////////////////////////////////
    /////////////////////////////////////////////////以下是输出部分/////////////////////////////////////////////////////
    cout << "开始输出txt校验批处理文件" << endl << endl << endl;
    string s = to_string(a) + "-b" + to_string(b) + ".bat";
    ofstream write;
    write.open(s);

    write << "@echo off" << endl;  //以下功能是打印 运行作业exe的指令

    write << output(a, b, c, "-demo", "");   //a为组号，b为序号，c为数据数，n为exe程序后缀，r为reslut后缀;
                                             //打印输出demo的结果的命令
    if (d)               //如果区分demo，打印输出demo-c的结果的命令
        write << output(a, b, c, "-demo-c", "-c");

    if (r <= 1)
    {
        write << output(a, b, c, "-1", "1");
        if (dev)         //如果区分dev，打印输出1-dev.exe的结果的命令
            write << output(a, b, c, "-2-dev", "2-dev");
    }
    if (r != 1)
    {
        write << output(a, b, c, "-2", "2");
        if (dev)        //如果区分dev，打印输出2-dev.exe的结果的命令
            write << output(a, b, c, "-1-dev", "1-dev");
    }

    write << "@echo on" << endl; //以下功能是打印 对比结果txt的指令
    
    if (d)   //如果区分demo
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
    else  //不区分demo
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

    if (del)  //以下功能是打印 删除结果txt文档的指令
    {
        write << "@echo off" << endl;

        write << "del " << a << "-b" << b << "-result.txt" << endl;
        if (d)   //如果区分demo
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

        cout << "result文件已自动删除" << endl << endl;
    }
    else
        cout << "运行bat文件后，-result-1.txt是你的c++程序的输出，-result-2.txt是你的c程序的输出，-result是demo的输出" << endl << endl;
    write << "pause" << endl;

    /////////////////////////////////////////////////以上是输出部分/////////////////////////////////////////////////////

    cout << "输出完成，关闭本窗口后双击运行" << s << "文件即可一键比对作业输出结果txt" << endl;
    cout << "第一次运行bat可能有卡顿现象，关闭窗口重新运行即可" << endl << endl;
    cout << "注意：如需重新生成" << s << "文件需要删除旧文件，如果需要指定txt_compare.exe的参数可自行修改" << s << "文件" << endl << endl;

    cin >> a;
    return 0;
}