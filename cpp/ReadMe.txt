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
	