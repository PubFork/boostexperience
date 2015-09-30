结合boost,c++11,到现在完全可以写出跨平台(win,linux)的服务端程序。(win不必保证性能，只需要保证可以运行，用来调试即可。把和系统相关的概念(文件，网络，锁，线程等）在底层封装起来，
上层的业务逻辑和系统相关的部分使用底层模块，自身的业务只使用c++，stl,boost等组件，这种低耦合，高内聚的模式可以写出很健壮的代码，可以单独对底层模块和业务模块进行单独测试。
同时调试非常方便(visual studio是最好的c/c++代码编写，调试IDE)



包含3个工程 ：
	lexical_cast 包含几乎所有对boost库的使用例子;
		headers
			common.h------------------------一些公用的必要头文件
			demo.h--------------------------有关boost组件的测试函数声明文件
			alqaz_lexical_cast.h------------有关lexical_cast测试包装类的声明文件
		sources
			cpp.cpp-------------------------main函数文件
			demo.cpp------------------------有关boost组件的测试函数实现文件
			alqaz_lexical_cast.cpp----------有关lexical_cast测试包装类的实现文件
			
	libraryDemo  包含一个可以被其他模块引用的模块(win-dll, linux-so)
		所有导出的函数声明都在头文件commonLibraryDemo.h中
	unitTest	 包含一个由boost Unit Test Adapter创建的单元测试程序，测试libraryDemo模块。它只能在windows下运行。
		所有的函数测试都是在alqaz.cpp 文件中完成。
		
		

注意：
	注意lexical_cast和libraryDemo中的头文件分布
	
使用之前，需要先安装Python，并且配好python环境变量，编译boost(版本:boost_1_57_0),并配好boost的包含路径和库路径

Linux下只需要安装好python,编译好boost,并把boost的头文件路径和库路径设置到系统即可。
编译方式为找到对应的Makefile文件，直接make clean && make 即可，生成的库和可执行文件目录是 /trunk/cpp/x64/Debug下面
	