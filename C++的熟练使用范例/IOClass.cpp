//
//  IOClass.cpp
//  C++的熟练使用范例
//
//  Created by wangjianwei on 16/4/7.
//  Copyright © 2016年 JW. All rights reserved.
//

#include <stdio.h>
#include <cmath>

#include <iostream>
#include <iomanip>//格式控制符必须不要忘记包含此头文件
using namespace std;
class IOClass
{
public:
    /**
     *  测试错误输出函数
     */
    static int testCerr( )
    {
        float a,b,c,disc;
        cout<<"please input a,b,c:";
        cin>>a>>b>>c;
        if (a==0)
            cerr<<"a is equal to zero,error!"<<endl;
        //将有关出错信息插入cerr流,在屏幕输出
        else
            if ((disc=b*b-4*a*c)<0)
                cerr<<"disc=b*b-4*a*c<0"<<endl;   //将有关出错信息插入cerr流,在屏幕输出
            else
            {
                cout<<"x1="<<(-b+sqrt(disc))/(2*a)<<endl;
                cout<<"x2="<<(-b-sqrt(disc))/(2*a)<<endl;
            }
        return 0;
    }
#pragma mark - 输入函数
    /**
     *  cin 函数测试
     */
   static int testCin( )
    {
        float grade;
        cout<<"enter grade:";
        while(cin>>grade)//能从cin流读取数据
        {
            if(grade>=85) cout<<grade<<"GOOD!"<<endl;
            if(grade<60) cout<<grade<<"fail!"<<endl;
            cout<<"enter grade:";
        }
        cout<<"The end."<<endl;
        return 0;
        
    }
    
    /**
     *  get
     *用来从指定的输入流中提取一个字符（包括空白字符），函数的返回值就是读入的字符。 若遇到输入流中的文件结束符，则函数值返回文件结束标志EOF(End Of File)，一般以-1代表EOF，用-1而不用0或正值，是考虑到不与字符的ASCII代码混淆，但不同的C ++系统所用的EOF值有可能不同。
     */
    static int testGet( )
    {
        int c;
        cout<<"enter a sentence:"<<endl;
        while((c=cin.get())!=EOF)
            cout.put(c);
        return 0;
    }
    /**
     *  getChar
     *  其作用是从输入流中读取一个字符，赋给字符变量ch。如果读取成功则函数返回true(真)，如失败(遇文件结束符) 则函数返回false(假)。例13.6可以改写如下：
     */
    static int testGetChar( )
    {
        char c;
        cout<<"enter a sentence:"<<endl;
        while(cin.get(c))  //读取一个字符赋给字符变量c,如果读取成功,cin.get(c)为真
        {cout.put(c);}
        cout<<"end"<<endl;
        return 0;
    }
    /**
     *  get(char*,size,eof)
     cin.get(字符数组, 字符个数n, 终止字符)
     或
     cin.get(字符指针, 字符个数n, 终止字符)
     *  其作用是从输入流中读取n-1个字符，赋给指定的字符数组(或字符指针指向的数组)，如果在读取n-1个字符之前遇到指定的终止字符，则提前结束读取。如果读取成功则函数返回true(真)，如失败(遇文件结束符) 则函数返回false(假)。
     */
    static int testGet3Params( )
    {
        char ch[20];
        cout<<"enter a sentence:"<<endl;
        cin.get(ch,10,'\\n');//指定换行符为终止字符
        cout<<ch<<endl;
        return 0;
    }
    /**
     *  getline
     * getline函数的作用是从输入流中读取一行字符,其用法与带3个参数的get函数类似。即
     cin.getline(字符数组(或字符指针), 字符个数n, 终止标志字符)
     */
    static int testGetline( )
    {
        char ch[20];
        cout<<"enter a sentence:"<<endl;
        cin>>ch;
        cout<<"The string read with cin is:"<<ch<<endl;
        cin.getline(ch,20,'/');  //读个字符或遇'/'结束
        cout<<"The second part is:"<<ch<<endl;
        cin.getline(ch,20);  //读个字符或遇'/n'结束
        cout<<"The third part is:"<<ch<<endl;
        return 0;
    }
#pragma mark - cin 其他
    /**
     *  EOF
     eof是end of file的缩写，表示“文件结束”。从输入流读取数据，如果到达文件末尾(遇文件结束符)，eof函数值为非零值(真)，否则为0(假)。
     
     */
    static int testEOF( )
    {
        char c;
        while(!cin.eof( ))  //eof( )为假表示未遇到文件结束符
            if((c=cin.get( ))!=' ')  //检查读入的字符是否为空格字符
                cout.put(c);
        return 0;
    }
    /**
     peek函数
     
     peek是“观察”的意思，peek函数的作用是观测下一个字符。其调用形式为：
     c=cin.peek( );
     函数的返回值是指针指向的当前字符，但它只是观测，指针仍停留在当前位置，并不后移。如果要访问的字符是文件结束符，则函数值是EOF(-1)。
     putback函数
     
     其调用形式为
     cin.putback(ch);
     其作用是将前面用get或getline函数从输入流中读取的字符ch返回到输入流，插入到当前指针位置，以供后面读取。     */
    static int  testPeekAndPutPack()
    {
        char c[20];
        int ch;
        cout<<"please enter a sentence:"<<endl;
        cin.getline(c,15,'/');
        cout<<"The first part is:"<<c<<endl;
        ch=cin.peek( );  //观看当前字符
        cout<<"The next character(ASCII code) is:"<<ch<<endl;
        cin.putback(c[0]);  //将'I'插入到指针所指处
        cin.getline(c,15,'/');
        cout<<"The second part is:"<<c<<endl;
        return 0;
    }
    /**
     *
     其调用形式为
     cin.ignore(n, 终止字符)
     函数作用是跳过输入流中n个字符，或在遇到指定的终止字符时提前结束(此时跳过包括终止字符在内的若干字符)。如
     ighore(5, 'A')  //跳过输入流中个字符，遇'A'后就不再跳了
     也可以不带参数或只带一个参数。如
     ignore( )  // n默认值为，终止字符默认为EOF
     相当于
     ignore(1, EOF)
     */
    static int testIgnore( )
    {
        char ch[20];
        cin.get(ch,20,'/');
        cout<<"The first part is:"<<ch<<endl;
        cin.ignore();
        cin.get(ch,20,'/');
        cout<<"The second part is:"<<ch<<endl;
        return 0;
    }

#pragma mark 格式控制
    /**
     *  格式控制符控制输入输出
     */
    static int testIO()
    {
        int a;
        cout<<"input a:";
        cin>>a;
        cout<<"dec:"<<dec<<a<<endl;  //以十进制形式输出整数
        cout<<"hex:"<<hex<<a<<endl;  //以十六进制形式输出整数a
        cout<<"oct:"<<setbase(8)<<a<<endl;  //以八进制形式输出整数a
        char *pt="China";  //pt指向字符串"China"
        cout<<setw(10)<<pt<<endl;  //指定域宽为,输出字符串
        cout<<setfill('*')<<setw(10)<<pt<<endl;  //指定域宽,输出字符串,空白处以'*'填充
        double pi=22.0/7.0;  //计算pi值
        //按指数形式输出,8位小数
        cout<<setiosflags(ios::scientific)<<setprecision(8);
        cout<<"pi="<<pi<<endl;  //输出pi值
        cout<<"pi="<<setprecision(4)<<pi<<endl;  //改为位小数
        cout<<"pi="<<setiosflags(ios::fixed)<<pi<<endl;  //改为小数形式输出
        return 0;
    }
    /**
     *  使用格式函数确定输入输出格式
     */
    static int testIOFunc( )
    {
        int a=21;
        cout.setf(ios::showbase);//显示基数符号(0x或)
        cout<<"dec:"<<a<<endl;         //默认以十进制形式输出a
        cout.unsetf(ios::dec);         //终止十进制的格式设置
        cout.setf(ios::hex);           //设置以十六进制输出的状态
        cout<<"hex:"<<a<<endl;         //以十六进制形式输出a
        cout.unsetf(ios::hex);         //终止十六进制的格式设置
        cout.setf(ios::oct);           //设置以八进制输出的状态
        cout<<"oct:"<<a<<endl;         //以八进制形式输出a
        cout.unsetf(ios::oct);
        char *pt="China";              //pt指向字符串"China"
        cout.width(10);                //指定域宽为
        cout<<pt<<endl;                //输出字符串
        cout.width(10);                //指定域宽为
        cout.fill('*');                //指定空白处以'*'填充
        cout<<pt<<endl;                //输出字符串
        double pi=22.0/7.0;            //输出pi值
        cout.setf(ios::scientific);    //指定用科学记数法输出
        cout<<"pi=";                   //输出"pi="
        cout.width(14);                //指定域宽为
        cout<<pi<<endl;                //输出pi值
        cout.unsetf(ios::scientific); //终止科学记数法状态
        cout.setf(ios::fixed);        //指定用定点形式输出
        cout.width(12);               //指定域宽为
        cout.setf(ios::showpos);      //正数输出“+”号
        cout.setf(ios::internal);     //数符出现在左侧
        cout.precision(6);            //保留位小数
        cout<<pi<<endl;               //输出pi,注意数符“+”的位置
        return 0;
    }
#pragma mark -输出函数
    /**
     *  put函数
     */
    static int testPut( )
    {
        char *a="BASIC";//字符指针指向'B'
        for(int i=4;i>=0;i--)
            cout.put(*(a+i));                  //从最后一个字符开始输出
        cout.put('\n');
        return 0;
    }
    /**
     *  putChar 函数
     */
    static void testPutChar( )
    {
        char *a="BASIC";
        for(int i=4;i>=0;i--)
            putchar(*(a+i));
        putchar('\n');
    }
#pragma mark -主函数
    static int main()
    {
//        testCerr();
//        testIO();
//        testIOFunc();
//        testPut();
//        testPutChar();
//        testCin();
//        testGet();
//        testGetChar();
//        testGet3Params();
//        testGetline();
//        testEOF();
        testPeekAndPutPack();
        return 0;
    }
    
};
