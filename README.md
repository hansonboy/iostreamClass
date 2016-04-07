#####C++ 输入输出理解
1. C++ 的io 分三大块

		- 是标准输入输出(iostream)cin,cout，cerr,clog 
		- 是文件输入输出流,(fstream,ofstream,ifstream)
		- 是字符串输入输出流（strstream,istrstream,ostrstream）
1. 对cin ，cout 的理解

	cin:
		
		-cin是istream类的对象，它从标准输入设备(键盘)获取数据，程序中的变量通过流提取符“>>”从流中提取数据,提取的时候会根据变量的类型从输入流中提取相应长度的字节，流提取符“>>”从流中提取数据时通常跳过输入流中的空格、tab键、换行符等空白字符。
		-当输入流cin处于出错状态时，如果测试cin的值，可以发现它的值为false(假)，即cin为0值。如果输入流在正常状态，cin的值为true(真)，即cin为 一个非0值。可以通过测试cin的值，判断流对象是否处于正常状态和提取操作是否成功。如：if(!cn) //流cin处于出销状态，无法正常提取数据cout<<"error";
	cout:

		- 注意：只有在输入完数据再按回车键后，该行数据才被送入键盘缓冲区，形成输入流，提取运算符“>>”才能从中提取数据。需要注意保证从流中读取数据能正常进行。遇到endl,或者是flush方法才会将数据缓冲区中进行输出。
		
	>实际上，在内存中为每一个数据流开辟一个内存缓冲区，用来存放流中的数据。当用cout和插入运算符“<<”向显示器输出数据时，先将这些数据送到程序中的输出缓冲区保存，直到缓冲区满了或遇到endl，就将缓冲区中的全部数据送到显示器显示出来。在输入时，从键盘输入的数据先放在键盘的缓冲区中，当按回车键时，键盘缓冲区中的数据输入到程序中的输入缓冲区，形成cin流，然后用提取运算符“ >>”从输入缓冲区中提取数据送给程序中的有关变量。总之，流是与内存缓冲区相对应的，或者说，缓冲区中的数据就是流。

3.	  C++提供了低级的I/O功能和高级的I/O功能。

	>高级的I/O功能是把若干个字节组合为一个有意义的单位（如整数、单精度数、双精度数、字符串或用户自定义的类型的数据），然后以ASCII字符形式输入和输出。例如将数据从内存送到显示器输出，就属于高级I/O功能，先将内存中的数据转换为ASCII字符，然后分别按整数、单精度数、双精度数等形式输出。这种面向类型的输入输出在程序中用得很普遍，用户感到方便。但在传输大容量的文件时由于数据格式转换，速度较慢，效率不高。
	> 
	>所谓低级的I/O功能是以字节为单位输入和输出的，在输入和输出时不进行数据格式的转换。这种输入输出是以二进制形式进行的。通常用来在内存和设备之间传输一批字节。这种输入输出速度快、效率高，一般大容量的文件传输用无格式转换的I/O。但使用时会感到不大方便。

		
		低级IO叫做二进制流输入输出
		高级IO叫做ASCII流输入输出
4.  [详细的c++ 输入输出流教程在这里](http://c.biancheng.net/cpp/biancheng/cpp/rumen_13/)
5.  [代码在github上面](https://github.com/hansonboy/iostreamClass)
