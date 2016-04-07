//
//  FstreamClass.cpp
//  C++的熟练使用范例
//
//  Created by wangjianwei on 16/4/7.
//  Copyright © 2016年 JW. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;
class FstreamClass
{
public:
#pragma mark - ASCII文件读取操作测试
    /**
     *  C++对ASCII文件的读写操作
     *[例13.11] 有一个整型数组，含个元素，从键盘输入个整数给数组，将此数组送到磁盘文件中存放。
     */
    static int testWriteOfstream( )
    {
        int a[10];
        ofstream outfile("f1.dat",ios::out);//定义文件流对象,打开磁盘文件"f1.dat"
        if(!outfile)                        //如果打开失败,outfile返回值
        {
            cerr<<"open error!"<<endl;
            exit(1);
        }
        cout<<"enter 10 integer numbers:"<<endl;
        for(int i=0;i<10;i++)
        {
            cin>>a[i];
            outfile<<a[i]<<" ";
        }            //向磁盘文件"f1.dat"输出数据
        outfile.close();                   //关闭磁盘文件"f1.dat"
        return 0;
    }

    
    /**
  [例13.12] 从例13.11建立的数据文件f1.dat中读入个整数放在数组中，找出并输出个数中的最大者和它在数组中的序号。
     */
    static int testReadIfsream( )
    {
        int a[10],max,i,order;
        //定义输入文件流对象,以输入方式打开磁盘文件f1.dat
        ifstream infile("f1.dat",ios::in);
        if(!infile)
        {
            cerr<<"open error!"<<endl;
            exit(1);
        }
        for(i=0;i<10;i++)
        {
            infile>>a[i];  //从磁盘文件读入10个整数,顺序存放在a数组中
            cout<<a[i]<<" ";  //在显示器上顺序显示10个数
        }
        cout<<endl;
        max=a[0];
        order=0;
        for(i=1;i<10;i++)
            if(a[i]>max)
            {
                max=a[i];  //将当前最大值放在max中
                order=i;  //将当前最大值的元素序号放在order中
            }
        cout<<"max="<<max<<endl<<"order="<<order<<endl;
        infile.close();
        return 0;
    }
    

    /**
     *  [例13.13] 从键盘读入一行字符，把其中的字母字符依次存放在磁盘文件f2.dat中。再把它从磁盘文件读入程序，将其中的小写字母改为大写字母，再存入磁盘文件f3.dat。
     */
    static int  testWriteAndRead( )
    {
        save_to_file( );  //调用save_to_file( ),从键盘读入一行字符并将其中的字母存入磁盘文件f2.dat
        get_from_file( );  //调用get_from_file(),从f2.dat读入字母字符,改为大写字母,再存入f3.dat
        return 0;
    }
    /** save_to_file函数从键盘读入一行字符,并将其中的字母存入磁盘文件*/
    static void save_to_file( )
    {
        ofstream outfile("f2.dat");  //定义输出文件流对象outfile,以输出方式打开磁盘文件f2.dat
        if(!outfile)
        {
            cerr<<"open f2.dat error!"<<endl;
            exit(1);
        }
        char c[80];
        cin.getline(c,80);  //从键盘读入一行字符
        for(int i=0;c[i]!=0;i++)  //对字符逐个处理,直到遇'/0'为止
            if(c[i]>=65 && c[i]<=90||c[i]>=97 && c[i]<=122)  //如果是字母字符
            {
                outfile.put(c[i]);  //将字母字符存入磁盘文件f2.dat
                cout<<c[i];  //同时送显示器显示
            }
        cout<<endl;
        outfile.close();  //关闭f2.dat
    }
    /**从磁盘文件f2.dat读入字母字符,将其中的小写字母改为大写字母,再存入f3.dat*/
    static void get_from_file()
    {
        char ch;
        //定义输入文件流outfile,以输入方式打开磁盘文件f2.dat
        ifstream infile("f2.dat",ios::in);
        if(!infile)
        {
            cerr<<"open f2.dat error!"<<endl;
            exit(1);
        }
        ofstream outfile("f3.dat");
        //定义输出文件流outfile,以输出方式打开磁盘文件f3.dat
        if(!outfile)
        {
            cerr<<"open f3.dat error!"<<endl;
            exit(1);
        }
        while(infile.get(ch))  //当读取字符成功时执行下面的复合语句
        {
            if(ch>=97 && ch<=122)  //判断ch是否为小写字母
                ch=ch-32;  //将小写字母变为大写字母
            outfile.put(ch);  //将该大写字母存入磁盘文件f3.dat
            cout<<ch;  //同时在显示器输出
        }
        cout<<endl;
        infile.close();  //关闭磁盘文件f2.dat
        outfile.close();  //关闭磁盘文件f3.dat
    }
#pragma mark - 二进制文件的输入输出操作

    struct student
    {
        char name[20];
        int num;
        int age;
        char sex;
    };
    /**
     *  [例13.14] 将一批数据以二进制形式存放在磁盘文件中。
     *
     用成员函数read和write读写二进制文件
     
     对二进制文件的读写主要用istream类的成员函数read和write来实现。这两个成员函数的原型为
     istream& read(char *buffer,int len);
     ostream& write(const char * buffer,int len);
     字符指针buffer指向内存中一段存储空间。len是读写的字节数。调用的方式为：
     a. write(p1,50);
     b. read(p2,30);
     上面第一行中的a是输出文件流对象，write函数将字符指针p1所给出的地址开始的50个字节的内容不加转换地写到磁盘文件中。在第二行中，b是输入文件流对象，read 函数从b所关联的磁盘文件中，读入30个字节(或遇EOF结束），存放在字符指针p2所指的一段空间内。
     */
    static int testBinaryWriteFile( )
    {
        student stud[3]={"Li",1001,18,'f',"Fun",1002,19,'m',"Wang",1004,17,'f'};
        ofstream outfile("stud.dat",ios::binary);
        if(!outfile)
        {
            cerr<<"open error!"<<endl;
            abort( );//退出程序
        }
        for(int i=0;i<3;i++)
            outfile.write((char*)&stud[i],sizeof(stud[i]));
        outfile.close( );
        return 0;
    }

    /**
    [例13.15] 将刚才以二进制形式存放在磁盘文件中的数据读入内存并在显示器上显示。
     */
    static int testBinaryReadFile( )
    {
        student stud[3];
        int i;
        ifstream infile("stud.dat",ios::binary);
        if(!infile)
        {
            cerr<<"open error!"<<endl;
            abort( );
        }
        for(i=0;i<3;i++)
            infile.read((char*)&stud[i],sizeof(stud[i]));
        infile.close( );
        for(i=0;i<3;i++)
        {
            cout<<"NO."<<i+1<<endl;
            cout<<"name:"<<stud[i].name<<endl;
            cout<<"num:"<<stud[i].num<<endl;;
            cout<<"age:"<<stud[i].age<<endl;
            cout<<"sex:"<<stud[i].sex<<endl<<endl;
        }
        return 0;
    }
    /**
     *
     *
     [例13.16] 有个学生的数据,要求:
     把它们存到磁盘文件中;
     将磁盘文件中的第,3,5个学生数据读入程序,并显示出来;
     将第个学生的数据修改后存回磁盘文件中的原有位置。
     从磁盘文件读入修改后的个学生的数据并显示出来。
     
     要实现以上要求,需要解决个问题：
     由于同一磁盘文件在程序中需要频繁地进行输入和输出，因此可将文件的工作方式指定为输入输出文件，即ios::in|ios::out|ios::binary。
     正确计算好每次访问时指针的定位，即正确使用seekg或seekp函数。
     正确进行文件中数据的重写(更新)。
     */
    struct student1
    {
        int num;
        char name[20];
        float score;
    };
    static int testBinaryRandomReadWrite( )
    {
        student1 stud[5]={1001,"Li",85,1002,"Fun",97.5,1004,"Wang",54,1006,"Tan",76.5,1010,"ling",96};
        fstream iofile("stud.dat",ios::in|ios::out|ios::binary);
        //用fstream类定义输入输出二进制文件流对象iofile
        if(!iofile)
        {
            cerr<<"open error!"<<endl;
            abort( );
        }
        for(int i=0;i<5;i++)  //向磁盘文件输出个学生的数据
            iofile.write((char *)&stud[i],sizeof(stud[i]));
        student1 stud1[5];  //用来存放从磁盘文件读入的数据
        for(int i=0;i<5;i=i+2)
        {
            iofile.seekg(i*sizeof(stud[i]),ios::beg);  //定位于第,2,4学生数据开头
            //先后读入个学生的数据,存放在stud1[0],stud[1]和stud[2]中
            iofile.read((char *)&stud1[i/2],sizeof(stud1[0]));
            //输出stud1[0],stud[1]和stud[2]各成员的值
            cout<<stud1[i/2].num<<" "<<stud1[i/2].name<<" "<<stud1[i/2].score<<endl;
        }
        cout<<endl;
        stud[2].num=1012;  //修改第个学生(序号为)的数据
        strcpy(stud[2].name,"Wu");
        stud[2].score=60;
        iofile.seekp(2*sizeof(stud[0]),ios::beg);  //定位于第个学生数据的开头
        iofile.write((char *)&stud[2],sizeof(stud[2]));  //更新第个学生数据
        iofile.seekg(0,ios::beg);  //重新定位于文件开头
        for(int i=0;i<5;i++)
        {
            iofile.read((char *)&stud[i],sizeof(stud[i]));  //读入个学生的数据
            cout<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].score<<endl;
        }
        iofile.close( );
        return 0;
    }
    static int main()
    {
//        testWriteOfstream();
//        testReadIfsream();
//        testWriteAndRead();
//        testBinaryWriteFile();
//        testBinaryReadFile();
        testBinaryRandomReadWrite();
        return 0;
    }
    
};