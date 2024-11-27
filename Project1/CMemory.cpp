#include "CMemory.h"

/// 관련 문서 : 메모리 ///////////////////////////////////////////////////
/// https://velog.io/@skang0926/%EB%A9%94%EB%AA%A8%EB%A6%AC%EC%99%80-%EA%B0%80%EC%83%81-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EC%8A%A4%ED%83%9D%EA%B3%BC-%ED%9E%99
///////////////////////////////////////////////////////////////////////////////

#pragma optimize("", off)
void CMemory::Run()
{
	{
	//	char c[1024][1025] = { 0 };
	}

	cout << "스택과 힙 메모리 위치" << endl;
	{
		int a = 10;
		int b = 20;
		int* pA = new int(10);
		int* pB = new int(20);

		cout << &a << endl;
		cout << &b << endl;
		cout << pA << endl;
		cout << pB << endl;

		delete pA;
		delete pB;
	}

	cout << "malloc, free" << endl;
	{
		int* pA = (int*)malloc(sizeof(int));
		int* pB = pA;
		free(pB);
		//	free(pA);
	}

	cout << "new, delete" << endl;
	{
		class MyClass
		{
		public:
			MyClass()
			{
				cout << "생성자 호출" << endl;
			}
			~MyClass()
			{
				cout << "소멸자 호출" << endl;
			}
		};

		MyClass* pA = (MyClass*)malloc(sizeof(MyClass));
		MyClass* pB = new MyClass();

		free(pA);
		//delete pA;
		delete pB;
	}

	cout << "placement new" << endl;
	{
		class MyClass
		{
		public:
			MyClass()
			{
				cout << "생성자 호출" << endl;
			}
			~MyClass()
			{
				cout << "소멸자 호출" << endl;
			}
		};

		void* pBlock = (MyClass*)malloc(sizeof(MyClass));

		MyClass* pA = new (pBlock) MyClass();
		delete pA;
	}

	{
		auto start = std::chrono::high_resolution_clock::now();

		int a[128][128] = { 0 };

		for (int i = 0; i < 128; i++)
		{
			for (int j = 0; j < 128; j++)
			{
				a[i][j] = 1;
			}
		}

		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		std::cout << duration.count() << " nano seconds" << std::endl;
	}

	{
		auto start = std::chrono::high_resolution_clock::now();

		int a[128][128] = { 0 };

		for (int i = 0; i < 128; i++)
		{
			for (int j = 0; j < 128; j++)
			{
				a[j][i] = 1;
			}
		}

		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		std::cout << duration.count() << " nano seconds" << std::endl;
	}
}
#pragma optimize("", on)