����3������ ��
	lexical_cast �����������ж�boost���ʹ������;
		headers
			common.h------------------------һЩ���õı�Ҫͷ�ļ�
			demo.h--------------------------�й�boost����Ĳ��Ժ��������ļ�
			alqaz_lexical_cast.h------------�й�lexical_cast���԰�װ��������ļ�
		sources
			cpp.cpp-------------------------main�����ļ�
			demo.cpp------------------------�й�boost����Ĳ��Ժ���ʵ���ļ�
			alqaz_lexical_cast.cpp----------�й�lexical_cast���԰�װ���ʵ���ļ�
			
	libraryDemo  ����һ�����Ա�����ģ�����õ�ģ��(win-dll, linux-so)
		���е����ĺ�����������ͷ�ļ�commonLibraryDemo.h��
	unitTest	 ����һ����boost Unit Test Adapter�����ĵ�Ԫ���Գ��򣬲���libraryDemoģ�顣��ֻ����windows�����С�
		���еĺ������Զ�����alqaz.cpp �ļ�����ɡ�
		
		

ע�⣺
	ע��lexical_cast��libraryDemo�е�ͷ�ļ��ֲ�
	
ʹ��֮ǰ����Ҫ�Ȱ�װPython���������python��������������boost(�汾:boost_1_57_0),�����boost�İ���·���Ϳ�·��

Linux��ֻ��Ҫ��װ��python,�����boost,����boost��ͷ�ļ�·���Ϳ�·�����õ�ϵͳ���ɡ�
���뷽ʽΪ�ҵ���Ӧ��Makefile�ļ���ֱ��make clean && make ���ɣ����ɵĿ�Ϳ�ִ���ļ�Ŀ¼�� /trunk/cpp/x64/Debug����
	