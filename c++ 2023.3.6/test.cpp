#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
using namespace std;

//class tests
//{
//public:
//
//	tests()
//	{
//
//	}
//	tests(int ss)
//	{
//		b = new int(ss);
//	}
//	~tests()
//	{
//		double b;
//	}
//	int* b;
//	int a;
//};
//
//void tesss()
//{
//
//}
//void t()
//{
//	tests test1(10);
//	tests test2(test1);
//	std::cout << *test1.b << "\n";
//	std::cout << "hailo wode" << "\n";
//	std::cout << *test2.b << "\n";
//
//}
//int main()
//{
//	t();
//
//	return 0;
//}


//class wdfangjian
//{
//	friend class haojy;
//	friend void hans(wdfangjian& dt);
//public:
//	wdfangjian();
//
//public:
//	string kt;
//
//private:
//	string ws;
//};
//
//class haojy
//{
//public:
//	haojy();
//	void haojyfw();
//
//public:
//	wdfangjian* bding;
//};
//
//haojy::haojy()
//{
//	bding = new wdfangjian;
//}
//wdfangjian::wdfangjian()
//{
//	this->kt = "����";
//	this->ws = "����";
//}
//void haojy::haojyfw()
//{
//	cout <<"�û������ڲιۣ�" << bding->kt << "\n";
//	cout << "�û������ڲιۣ�" << bding->ws << "\n";
//}
//
//void hans(wdfangjian &dt)
//{
//	//cout << dt.kt << "\n";
//	//cout << dt.ws << "\n";
//	haojy ss;
//	ss.haojyfw();
//}
//void test01()
//{
//	wdfangjian ss;
//	hans(ss);
//}
//int main()
//{
//	test01();
//	return 0;
//}

class hpy
{
	friend class jy;
	friend void test01();
public:
	hpy();

public:
	string kt;
private:
	string ws;
};
hpy::hpy()
{
	kt = "����";
	ws = "����";
}

class jy
{
public:
	jy();
	void testls();
public:
	hpy* ss;
};

jy::jy()
{
	ss = new hpy;
}
void jy::testls()
{
	cout << "�û������ڷ���:" << ss->kt << "\n";
	cout << "�û������ڷ���:" << ss->ws << "\n";
}
void hasn(jy& ss)
{
	ss.testls();
}
void test01()
{
	jy ss;
	//cout << ss.kt << "\n";
	//cout << ss.ws << "\n";
	hasn(ss);
}
int main()
{
	test01();
	return 0;
}