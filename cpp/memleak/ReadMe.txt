这是一个用来测试内存泄漏的demo,
在windows linux都可以运行。
windows下使用Visual Leak Detector插件进行内存检测，使用方式非常简单，只需要在检测的文件开头加上vld.h。一般是在公用的头文件中加入，本例子是在common.h中添加

linux下使用vargrind进行检查。
valgrind --tool=memcheck --leak-check=full ./memleak