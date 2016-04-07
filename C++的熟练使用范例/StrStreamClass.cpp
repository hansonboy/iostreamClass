//
//  StrStreamClass.cpp
//  C++的熟练使用范例
//
//  Created by wangjianwei on 16/4/7.
//  Copyright © 2016年 JW. All rights reserved.
//

#include <stdio.h>
#include <strstream>
#include <iostream>
using namespace std;
class StrStreamClass
{
public:

    struct student
    {
        int num;
        char name[20];
        float score;
    };
    /**
     *  ostrstream类提供的构造函数的原型为：
     ostrstream::ostrstream(char *buffer,int n,int mode=ios::out);
     buffer是指向字符数组首元素的指针，n为指定的流缓冲区的大小（一般选与字符数组的大小相同，也可以不同），第3个参数是可选的，默认为ios::out方式。可以用以下语句建立输出字符串流对象并与字符数组建立关联：
     ostrstream strout(ch1,20);
     作用是建立输出字符串流对象strout，并使strout与字符数组ch1关联（通过字符串流将数据输出到字符数组ch1），流缓冲区大小为20。
     
     [例13.17] 将一组数据保存在字符数组中。
     */
    static void testOstrstream( )
    {
        student stud[3]={1001,"Li",78,1002,"Wang",89.5,1004,"Fun",90};
        char c[50];  //用户定义的字符数组
        ostrstream strout(c,30);  //建立输出字符串流,与数组c建立关联,缓冲区长
        for(int i=0;i<3;i++)  //向字符数组c写个学生的数据
            strout<<stud[i].num<<stud[i].name<<stud[i].score;
        strout<<ends;  //ends是C++的I/O操作符,插入一个'\\0'
        cout<<"array c:"<<c<<endl;  //显示字符数组c中的字符
        
    }
    /**
     *  istrstream类提供了两个带参的构造函数，原型为：
     istrstream::istrstream(char *buffer);
     istrstream::istrstream(char *buffer,int n);
     buffer是指向字符数组首元素的指针，用它来初始化流对象（使流对象与字符数组建立关联）。可以用以下语句建立输入字符串流对象：
     istrstream strin(ch2);
     作用是建立输入字符串流对象strin，将字符数组ch2中的全部数据作为输入字符串流的内容。
     istrstream strin(ch2,20);
     流缓冲区大小为20，因此只将字符数组ch2中的,20个字符作为输入字符串流的内容。
     *
    [例13.18] 在一个字符数组c中存放了个整数,以空格相间隔,要求将它们放到整型数组中,再按大小排序,然后再存放回字符数组c中
     */
    static int testIstrstream( )
    {
        char c[50]="12 34 65 -23 -32 33 61 99 321 32";
        int a[10],i,j,t;
        cout<<"array c:"<<c<<endl;  //显示字符数组中的字符串
        istrstream strin(c,sizeof(c));  //建立输入串流对象strin并与字符数组c关联
        for(i=0;i<10;i++)
            strin>>a[i];  //从字符数组c读入个整数赋给整型数组a
        cout<<"array a:";
        for(i=0;i<10;i++)
            cout<<a[i]<<" ";  //显示整型数组a各元素
        cout<<endl;
        for(i=0;i<9;i++)  //用起泡法对数组a排序
            for(j=0;j<9-i;j++)
                if(a[j]>a[j+1])
                {t=a[j];a[j]=a[j+1];a[j+1]=t;}
        ostrstream strout(c,sizeof(c));  //建立输出串流对象strout并与字符数组c关联
        for(i=0;i<10;i++)
            strout<<a[i]<<" ";  //将个整数存放在字符数组c
        strout<<ends;  //加入'\\0'
        cout<<"array c:"<<c<<endl;  //显示字符数组c
        return 0;
    }
    static int main()
    {
//        testOstrstream();
        testIstrstream();
        return 0;
    }
};