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

class CMemsetVirtualTest // 测试 带虚类，被memset为0后，虚表是否失效
{
public:
	CMemsetVirtualTest()
	{
		memset(this, 0, sizeof(CMemsetVirtualTest));
	}
	virtual void NormalFun()
	{

		cout << "test： NormalFun() 虚表指针有效" << endl;
	}
	virtual ~CMemsetVirtualTest()
	{

		cout << "test： ~CMemsetVirtualTest() 虚表指针有效" << endl;

	}

};

void testFun1() // 测试：栈上建立的对象
{
	CMemsetVirtualTest Ctest;
	Ctest.NormalFun();
}
void testFun2() // 测试：堆上建立的对象
{

	CMemsetVirtualTest* Ptest = new CMemsetVirtualTest();

	Ptest->NormalFun(); // 到这里一定会暴掉?


	delete Ptest;  // 如果屏蔽上句，到这里也一定会暴掉?


}

int memset_class_001()
{

	CMemsetVirtualTest Ctest;// 测试：栈上建立的对象?

	Ctest.NormalFun();// 测试正常：


	CMemsetVirtualTest* Ptest = new CMemsetVirtualTest(); // 测试：堆上建立的对象


	Ptest->NormalFun(); // 到这里一定会暴掉?


	delete Ptest;  // 如果屏蔽上句，到这里也一定会暴掉?

}
