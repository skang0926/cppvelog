#include "CPointer.h"

/// 관련 문서 : 포인터와 스마트포인터 ///////////////////////////////////////////////////
/// https://velog.io/@skang0926/%ED%8F%AC%EC%9D%B8%ED%84%B0-%EC%8A%A4%EB%A7%88%ED%8A%B8%ED%8F%AC%EC%9D%B8%ED%84%B0
///////////////////////////////////////////////////////////////////////////////

struct CStruct
{
	int arr[10];
};

void PrintCStruct(CStruct* cstruct)
{
	for (int i = 0; i < 10; i++)
	{
		cout << cstruct->arr[i] << endl;
	}
	return;
}
#pragma optimize("", off)
void CPointer::Run()
{
	cout << "강제 캐스팅" << endl;
	{
		class CTest1
		{
		public:
			CTest1()
			{
				val1 = 1;
				val2 = 2;
			}
			int val1;
			int val2;
		};

		class CTest2
		{
		public:
			int val2;
			int val1;
		};

		CTest1 a;
		CTest2* pb = (CTest2*)&a;

		cout << pb->val1 << endl;
		cout << pb->val2 << endl;
	}


	cout << endl << "강제 캐스팅에 따른 액세스 위반" << endl;
	{
		class CTest1
		{
		public:
			CTest1()
			{
				val = 1;
			}
			long long val;
		};

		class CTest2
		{
		public:
			long long* val;
		};

		CTest1 a;
	//	CTest2* pb = (CTest2*)&a;

	//	cout << *(pb->val) << endl;
	}


	cout << endl << "데이터 참조" << endl;
	{
		CStruct st;

		for (int i = 0; i < 10; i++)
		{
			st.arr[i] = i+1;
		}

		PrintCStruct(&st);
	}

	cout << endl << "동적할당" << endl;
	{	
		int* a = new int(2);
		int b = 1;
		
		cout << a << endl;
		cout << &b << endl;
		delete a;
	}


	cout << endl << "참조와 포인터" << endl;
	{
		

		int a = 1;
		int* pA = &a;
		int& rA = a;

		cout << *pA << endl;
		cout << rA << endl;
	}


	cout << endl << "동적할당으로 인한 댕글링 포인터" << endl;
	{	
		int* a = new int(10);
		cout << a << endl;
		delete a;
		// cout << a << endl;
		// *a = 2; // 해제된 메모리 a에 접근
		a = nullptr;
		// cout << *a << endl; // 예외발생 엑세스 위반
	}


	cout << endl << "지역변수 참조로 인한 댕글링 포인터" << endl;
	{
		
		int* a;
		{
			int b = 1;
			a = &b;
			cout << a << endl;
		} // b는 더이상 유효하지 않음
		cout << a << endl;
		cout << *a << endl;
		*a = 2;
		cout << *a << endl;
	}

	cout << endl << "unique_ptr 1" << endl;
	{	
		unique_ptr<int> pA = make_unique<int>(3);
		//unique_ptr<int> pB = pA; // error 
		//unique_ptr<int> pC;
		//pC = pA// error

		cout << pA.get() << endl;
	}


	cout << endl << "unique_ptr 2" << endl;	
	{		
		class MyClass
		{
		public:
			MyClass(int val) : n(val){}

			~MyClass()
			{
				cout << "Destroy" << endl;
			}
			int n;
		};

		unique_ptr<MyClass> pA = make_unique<MyClass>(3);
		cout << pA.get() << endl;

		unique_ptr<MyClass> pB = move(pA);
		cout << pA.get() << endl; // nullptr
		cout << pB.get() << endl;
	} // pB 해제

	cout << endl << "shared_ptr 1" << endl;
	{
		class MyClass
		{
		public:
			MyClass(int val) : n(val) {}

			~MyClass()
			{
				cout << "Destroy" << endl;
			}
			int n;
		};

		shared_ptr<MyClass> pA = make_shared<MyClass>(2);
		cout << pA.get() << endl;
		cout << pA.use_count() << endl;
		{
			shared_ptr<MyClass> pB = pA;
			cout << pB.get() << endl;
			cout << pB.use_count() << endl;
		}
		weak_ptr<MyClass> pC = pA;
		cout << pC.lock() << endl;
		cout << pA.use_count() << endl;
	} // pA 소멸로 use_count 0, 객체 삭제


	cout << endl << "shared_ptr 2" << endl;
	{
		class MyClassB;
		class MyClassA
		{
		public:
			~MyClassA()
			{
				cout << "Destroy A" << endl;
			}

			shared_ptr<MyClassB> bPtr;
		};

		class MyClassB
		{
		public:
			~MyClassB()
			{
				cout << "Destroy B" << endl;
			}
			shared_ptr<MyClassA> aPtr;
		};

		shared_ptr<MyClassA> pA = make_shared<MyClassA>();
		shared_ptr<MyClassB> pB = make_shared<MyClassB>();

		pA.get()->bPtr = pB;
		pB.get()->aPtr = pA;

		cout << pA.use_count() << endl;
		cout << pB.use_count() << endl;
	}

	cout << "weak_ptr" << endl;
	{
		class MyClass
		{
		public:
			~MyClass()
			{
				cout << "Destroy" << endl;
			}
		};

		{
			shared_ptr<MyClass> sp1 = make_shared<MyClass>();
			shared_ptr<MyClass> sp2 = sp1;
			weak_ptr<MyClass> wp1 = sp2;
		}
	}
}
#pragma optimize("", on)