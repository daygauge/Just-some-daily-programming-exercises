#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include "test.h"
using namespace std;
class test02;
//const double PI = 3.14;
//class Circle
//{
//public:
//	int Radius;
//
//	double girth()
//	{
//		return 2 * PI * Radius;
//	}
//};
//int main()
//{
//	Circle ls;
//	ls.Radius = 5;
//	cout << ls.girth() << endl;
//	return 0;
//}


//class student
//{
//public:
//	void setname(string names)
//	{
//		name = names;
//	}
//	void setid(int ids)
//	{
//		id = ids;
//	}
//	void show()
//	{
//		cout <<"����:" << name <<" ѧ��:"<< id << endl;
//	}
//
//	string name;
//	int id = 0;
//};
//
//int main()
//{
//	student ls;
//	ls.setname("����");
//	ls.setid(23);
//	ls.show();
//	return 0;
//}


//class house
//{
//public:
//	int n1;
//
//	void ls()
//	{
//		cout << n1 << n2 << n3 << endl;
//	}
//
//protected:
//	int n2;
//private:
//	int n3;
//};
//
//int main()
//{
//	house ls;
//	ls.n1;
//	return 0;
//}
//struct test1
//{
//	int n1;
//};
//class  test2
//{
//	int n2;
//};
//
//int main()
//{
//	return 0;
//}
//

//class test1
//{
//public:
//	//ֻд  ����
//	void setname(string Name)
//	{
//		name = Name;
//	}
//
//	//ֻ��  ����
//	int ages()
//	{
//		return age;
//	}
//
//	//�ɶ���д   ѧ��
//	int ids()
//	{
//		return id;
//	}
//	void setid(int ids)
//	{
//		id = ids;
//	}
//
//	void test(string n1,int n2,int n3)
//	{
//		name = n1;
//		age = n2;
//		id = n3;
//	}
//
//private:
//	string name;//ֻд  ����
//	int age;//ֻ��  ����
//	int id;//�ɶ���д   ѧ��
//};
//int main()
//{
//
//	return 0;
//}
//
//
//
//
//class test
//{
//public:
//	test()
//	{
//		cout << "���캯������" << endl;
//	}
//
//	~test()
//	{
//		cout << "������������" << endl;
//	}
//};
//
//
//void test1()
//{
//	test ls;
//	cout << "1" << endl;
//
//}
//int main()
//{
//	test1();
//	cout << "1" << endl;
//	return 0;
//}
//void test01()
//{
//	//test ls1;
//	//test ls2(10);
//	//test ls3(ls2);
//
//	//test ls4 = test(10);
//	//test ls5 = test(ls4);
//
//	//test ls6 = 10;
//	//test ls7 = ls6;
//
//}
//int main()
//{
//	test01();
//	return 0;
//}
//class test
//{
//public:
//	test()
//	{
//		cout << "���캯��" << endl;
//	}
//
//	test(int a)
//	{
//		n1 = a;
//		cout << "�вι��캯��" << endl;
//	}
//
//	test(const test& ls)
//	{
//		n1 = ls.n1;
//		cout << "�������캯��" << endl;
//	}
//
//	~test()
//	{
//		cout << "��������" << endl;
//	}
//
//private:
//	int n1;
//};
//
//test test02()
//{
//	test ls;
//	return ls;
//}
//void test01()
//{
//	//test ls;
//	//test ls1(ls);
//
//	test ls(test02());
//}
//int main()
//{
//	test01();
//	return 0;
//}
//void test01()
//{
//
//}
//int main()
//{
//	test01();
//	return 0;
//}
//class test
//{
//public:
//	test()
//	{
//		cout << "�޲ι��캯��" << endl;
//	}
//	test(int n1s,int n2s)
//	{
//		n1 = n1s;
//		n2 = new int(n2s);
//		cout << "�вι��캯��" << endl;
//	}
//	test(test &tests)
//	{
//		n1 = tests.n1;
//		n2 = new int(*tests.n2);
//		cout << "�������캯��" << endl;
//	}
//	~test()
//	{
//		cout << "��������" << endl;
//		if (n2 != NULL)
//		{
//			delete n2;
//		}
//	}
//private:
//	int n1;
//	int* n2;
//};
//
//void test01()
//{
//	test ls(10, 20);
//	test ls1(ls);
//}
//int main()
//{
//	test01();
//	return 0;
//}

//class test
//{
//public:
//	test(int as, int bs, int cs) :a(as), b(bs), c(cs) 
//	{
//
//	}
//	void dy()
//	{
//		cout <<"a=" << a <<" b=" << b << " c=" << c << endl;
//	}
//
//private:
//	int a;
//	int b;
//	int c;
//};
//void test01()
//{
//	test ls(10, 20, 30);
//	ls.dy();
//}
//int main()
//{
//	test01();
//	return 0;
//}
//class test1
//{
//public:
//	test1(string cs):c(cs)
//	{
//		cout << "test1����" << endl;
//	}
//	~test1()
//	{
//		cout << "test1����" << endl;
//	}
//	string c;
//};
//class test
//{
//public:
//	test(string as,string bs):a(as),b(bs)
//	{
//		cout << "test����" << endl;
//	}
//	~test()
//	{
//		cout << "test����" << endl;
//	}
//	void lss()
//	{
//		cout << a <<"ʹ��" << b.c << endl;
//	}
//
//private:
//	string a;
//	test1 b;
//};
//void test01()
//{
//	test ls("����", "��Ϊ");
//	ls.lss();
//}
//int main()
//{
//	test01();
//	return 0;
//}

//void test01()
//{
//	test ls;
//	cout << sizeof(ls) << endl;
//
//	cout << ls.a << endl;
//	test ls2;
//	ls2.a = 200;
//	cout << ls.a << endl;
//}
//class test
//{
//public:
//	static void cs()
//	{
//		 b = 100;//�޷�����
//		 a = 100;
//	}
//public:
//	int b;
//	static int a;
//};
//int test::a = 100;
//
//void test01()
//{
//
//}
//int main()
//{
//	test01();
//	return 0;
//}

//class test
//{
//public:
//	static int a;
//private:
//	static int b;
//};
//int test::a = 100;
//int test::b = 100;
//
//void test01()
//{
//	test ls;
//	cout << sizeof(ls) << endl;
//
//	cout << ls.a << endl;
//	cout << test::a << endl;
//	test ls2;
//	ls2.a = 200;
//	cout << ls.a << endl;
//	//cout << ls.b << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}

//class test
//{
//public:
//	static void tests()
//	{
//
//	}
//
//public:
//	int a;
//	static int b;
//};
//int test::b = 100;
//
//void test01()
//{
//	test ls;
//	ls.tests();
//
//	test::tests();
//
//}
//int main()
//{
//	test01();
//	return 0;
//}

//class test
//{
//public:
//	void ls(int a)
//	{
//		this->a = a;
//	}
//
//	int a;
//};

//class test
//{
//public:
//	test& hans(test ls)
//	{
//		 this->a += ls.a;
//		 return *this;
//	}
//	int a = 0;
//};
//
//void test01()
//{
//	test ls;
//	ls.a = 10;
//
//	test ls2;
//	ls2.hans(ls);
//	//ls2.hans(ls).hans(ls).hans(ls).hans(ls);
//	cout << ls2.a << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}
//class Person {
//public:
//
//	void ShowClassName() {
//		cout << "����Person��!" << endl;
//	}
//
//	void ShowPerson() {
//		if (this == NULL) {
//			return;
//		}
//		cout << mAge << endl;
//	}
//public:
//	int mAge;
//};
//
//void test01()
//{
//	Person* p = NULL;
//	p->ShowClassName();
//	p->ShowPerson(); 
//}
//
//int main() {
//
//	test01();//	return 0;
//}

//class test
//{
//public:
//	void tests() const
//	{
//		//const���γ�Ա��������ʾָ��ָ����ڴ�ռ�����ݲ����޸ģ�����mutable���εı���
//		//this->a = 100;//���ɱ��޸�
//		this->b = 100;
//	}
//
//
//	int a;
//	mutable int b;//����muable����޸�
//};
//
//int main()
//{
//    const test ls;
//	ls.a = 100;
//	cout << ls.a << endl;
//
//
//	return 0;
//}
//class Building;
//class goodGay
//{
//public:
//
//	goodGay()
//	{
//		building = new Building;
//	}
//	void visit()
//	{
//
//	}
//private:
//	Building* building;
//};
//
//class Building
//{
//public:
//	Building()
//	{
//		this->m_SittingRoom = "����";
//		this->m_BedRoom = "����";
//	}
//
//public:
//	string m_SittingRoom; //����
//private:
//	string m_BedRoom;//����
//};
//
//void test01()
//{
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}
//class test
//{
//	friend void test01(test& ls);
//public:
//	test()
//	{
//		n1 = "����";
//		n2 = "����";
//	}
//
//	string n1;
//private:
//	string n2;
//};
//void test01(test &ls)
//{
//	cout << ls.n1 << endl;
//	cout << ls.n2 << endl;
//}
//int main()
//{
//	test ls;
//	test01(ls);
//	return 0;
//}
//class test02
//{
//	friend class test01;
//
//public:
//	test02()
//	{
//		this->n1 = "����";
//		this->n2 = "����";
//	}
//private:
//	string n1;
//	string n2;
//};
//class test01
//{
//public:
//	test01()
//	{
//		this->test = new test02;
//	}
//	void ss()
//	{
//		cout << test->n1 << endl;
//		cout << test->n2 << endl;
//	}
//private:
//	test02* test;
//};
//
//
//int main()
//{
//	test01 ls;
//	ls.ss();
//
//	return 0;
//}

class test1;
class test
{
public:
	test();
	void t1();
private:
	test1* ls;
};

class test1
{
	friend void test::t1();
public:
	test1()
	{
		a = 100;
	}
private:
	int a;
};

test::test()
{
	ls = new test1;
}
void test::t1()
{
	cout << ls->a << endl;
}

int main()
{
	test ls;
	ls.t1();
	return 0;
}