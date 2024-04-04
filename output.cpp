#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include "txt-compare-tool.h"
using namespace std;

//////////////此函数用于输出说明///////////////
void Readme()
{
    cout << "        ###########################################################################################" << endl;
    cout << "        # txt-compare-tool v1.2                                                                   #" << endl;
    cout << "        # 《同济大学高程作业文本校对批处理文件生成工具》使用说明：                                #" << endl;
    cout << "        # 1.测试数据文件需要命名格式为“test-data8.txt”，内部格式同老师get_input_data.exe要求    #" << endl;
    cout << "        #  （其中的3和8应替换成你需要的作业编号，下同）                                           #" << endl;
    cout << "        # 2.老师给的demo程序命名格式应为‘3-b8-demo.exe’，如果有c语言版本则为‘3-b8-demo-c.exe’ #" << endl;
    cout << "        # 3.你的c++程序命名格式应为‘3-b8-1.exe’,如果有dev版本则为‘3-b8-1-dev.exe’             #" << endl;
    cout << "        # 4.你的c程序命名格式应为‘3-b8-2.exe’,如果有dev版本则为‘3-b8-2-dev.exe’               #" << endl;
    cout << "        # 5.以上文件和本工具应在同一目录下                                                        #" << endl;
    cout << "        # 6.老师的get_input_data.exe和txt_compare.exe应已可用                                     #" << endl;
    cout << "        # 7.bug反馈途径见储存库                                                                   #" << endl;
    cout << "        # 8.本工具提供的结果仅供参考，如果造成任何作业相关问题开发者概不负责                      #" << endl;
    cout << "        #                                                                                         #" << endl;
    cout << "        #          储存库链接（更新下载）https://github.com/gfjdh/txt-compare-tool                #" << endl;
    cout << "        ###########################################################################################" << endl << endl;
}


//////////////此函数用于合成"运行作业exe的指令"的字符串///////////////
string createExeRunCommand(int a,int b,int c,string n,string r)   //a为组号，b为序号，c为数据数，n为exe程序后缀，r为reslut后缀
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

//////////////此函数用于合成"对比结果txt的指令"的字符串///////////////
string createTxtComparisonCommand(int a, int b, string r1, string r2, string c)   //a为组号，b为序号，r1为第一个txt后缀，r2为第二个txt后缀, c为用户指定的参数
{
    string result;
    result = "txt_compare --file1 " + to_string(a) + "-b" + to_string(b) + "-result"+ r1 +".txt --file2 " 
            + to_string(a) + "-b" + to_string(b) + "-result"+ r2 +".txt --display detailed "+ c +"\n";    
    return result;
}

//////////////此函数用于删除"对比结果txt的指令"的字符串///////////////
string createTxtDeleteCommand(int a, int b, string r)   //a为组号，b为序号，r为txt后缀
{
    string result;
    result = "del " + to_string(a) + "-b" + to_string(b) + "-result" + r + ".txt\n";
    return result;
}