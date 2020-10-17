/*
From:ITC
14
Object orientedness defects
14.2
Memset class
14.2.1
memset class errors
*/
#include<iostream>
using namespace std;

class CMemsetVirtualTest // ���� �����࣬��memsetΪ0������Ƿ�ʧЧ
{
public:
	CMemsetVirtualTest()
	{
		memset(this, 0, sizeof(CMemsetVirtualTest));
	}
	virtual void NormalFun()
	{

		cout << "test�� NormalFun() ���ָ����Ч" << endl;
	}
	virtual ~CMemsetVirtualTest()
	{

		cout << "test�� ~CMemsetVirtualTest() ���ָ����Ч" << endl;

	}

};

void testFun1() // ���ԣ�ջ�Ͻ����Ķ���
{
	CMemsetVirtualTest Ctest;
	Ctest.NormalFun();
}
void testFun2() // ���ԣ����Ͻ����Ķ���
{

	CMemsetVirtualTest* Ptest = new CMemsetVirtualTest();

	Ptest->NormalFun(); // ������һ���ᱩ��?


	delete Ptest;  // ��������Ͼ䣬������Ҳһ���ᱩ��?


}

int memset_class_001()
{

	CMemsetVirtualTest Ctest;// ���ԣ�ջ�Ͻ����Ķ���?

	Ctest.NormalFun();// ����������


	CMemsetVirtualTest* Ptest = new CMemsetVirtualTest(); // ���ԣ����Ͻ����Ķ���


	Ptest->NormalFun(); // ������һ���ᱩ��?


	delete Ptest;  // ��������Ͼ䣬������Ҳһ���ᱩ��?

}
