#include "CClass.h"

/// 관련 문서 : 클래스, 가상함수 ///////////////////////////////////////////////////
/// https://velog.io/@skang0926/%ED%81%B4%EB%9E%98%EC%8A%A4-%EC%83%9D%EC%84%B1%EC%9E%90%EC%99%80-%EC%86%8C%EB%A9%B8%EC%9E%90-%EA%B0%80%EC%83%81-%ED%95%A8%EC%88%98
///////////////////////////////////////////////////////////////////////////////

void CClass::Run()
{
	cout << "클래스 크기 1" << endl;
	{
		class MyClass
		{
		public:
			char c;
			int val;
			double d;
		};

		int offsetC = (int)(&(((MyClass*)0)->c));
		int offsetI = (int)(&(((MyClass*)0)->val));
		int offsetD = (int)(&(((MyClass*)0)->d));

		cout << offsetC << endl;
		cout << offsetI << endl;
		cout << offsetD << endl;

		cout << sizeof(MyClass) << endl;
	}

	cout << "클래스 크기 2" << endl;
	{
		class EmptyClass
		{

		};

		class MyClassA
		{
			char c;
		};

		class MyClassB
		{
			int val1;
			int val2;
			char c;
		};

		class MyClassC
		{
			double d;
			char c;
		};

		cout << sizeof(EmptyClass) << endl;
		cout << sizeof(MyClassA) << endl;
		cout << sizeof(MyClassB) << endl;
		cout << sizeof(MyClassC) << endl;
	}

	cout << "클래스 크기 3" << endl;
	{
		class MyClassA
		{
			int val1;
			int val2;
			double d;
		};

		class MyClassB
		{
			int val1;
			double d;
			int val2;
		};
		cout << sizeof(MyClassA) << endl;
		cout << sizeof(MyClassB) << endl;
	}

	cout << "클래스 오프셋 1" << endl;
	{
		class MyClass
		{
		public:
			char c;
			int val1;
			int val2;
		};

		MyClass mc;
		mc.c = 'a';
		mc.val1 = 1;
		mc.val2 = 2;
	}


	cout << "클래스 오프셋 2" << endl;
	{
		class MyClass
		{
		public:
			char c;
			int val1;
			int val2;

			virtual void VFunc() {}
		};

		MyClass mc;
		int offsetC = (int)(&(((MyClass*)0)->c));
		int offsetV1 = (int)(&(((MyClass*)0)->val1));
		int offsetV2 = (int)(&(((MyClass*)0)->val2));

		cout << offsetC << endl;
		cout << offsetV1 << endl;
		cout << offsetV2 << endl;
	}

	cout << "기본 자료형 캐스팅" << endl;
	{
		int i = 3;

		double d1 = i;
		double d2 = (double)i;

		printf("%lf\n", d1);
		printf("%lf\n", d2);
	}

	cout << "클래스 캐스팅 1" << endl;
	{
		class MyClassA
		{
		public:
			int val;
		};

		class MyClassB
		{
		public:
			MyClassB(const MyClassA& a)
			{
				cout << "MyClassB 생성자" << endl;
				val = a.val;
			}

			int val;
		};

		MyClassA a;

		MyClassB b1 = a;
		MyClassB b2 = (MyClassB)a;
		MyClassB b3 = static_cast<MyClassB>(a);
		// MyClassB b4 = reinterpret_cast<MyClassB>(a);

	}

	cout << "클래스 캐스팅 2" << endl;
	{
		class MyClassA
		{
		public:
			int val;
		};

		class MyClassB
		{
		public:
			MyClassB(const MyClassA& a)
			{
				cout << "MyClassB 생성자" << endl;
				val = a.val;
			}

			int val;
		};

		MyClassA a;

		// MyClassB& b1 = a; // Error 
		MyClassB& b2 = (MyClassB&)a;
		// MyClassB& b3 = static_cast<MyClassB&>(a); // 상속 관계에서만 캐스팅 가능
		MyClassB& b4 = reinterpret_cast<MyClassB&>(a);

	}

	cout << "상속 관계 클래스 캐스팅 1" << endl;
	{
		class CParent 
		{
		public:
			int val1;
		};

		class CChild : public CParent
		{
		public:
			int val2;
		};

		CChild c;
		c.val1 = 1;
		c.val2 = 2;

		CParent p1 = c;
		CParent p2 = (CParent)c;
		CParent p3 = static_cast<CParent>(c);
		// CParent p4 = reinterpret_cast<CParent>(c); // Error : 값 변환 캐스팅 불가능

		CParent p;
		p.val1 = 1;

		// CChild c1 = p; // Error
		// CChild c2 = (CChild)p; // Error
		// CChild c3 = static_cast<CChild>(p); // Error
		// CChild c4 = reinterpret_cast<CChild>(p); // Error
	}

	cout << "상속 관계 클래스 캐스팅 2" << endl;
	{
		class CParent
		{
		public:
			int val1;
		};

		class CChild : public CParent
		{
		public:
			int val2;
		};

		CChild c;
		c.val1 = 1;
		c.val2 = 2;

		CParent& rp1 = c;
		CParent& rp2 = (CParent&)c;
		CParent& rp3 = static_cast<CParent&>(c);
		CParent& rp4 = reinterpret_cast<CParent&>(c); // Error : 값 변환 캐스팅 불가능

		CParent p;
		p.val1 = 1;

		// CChild& c1 = p; // Error
		CChild& rc2 = (CChild&)p;
		CChild& rc3 = static_cast<CChild&>(p);
		CChild& rc4 = reinterpret_cast<CChild&>(p);
	}

	cout << "포인터 간 캐스팅 1" << endl;
	{
		class MyClassA
		{
		public:
			int val1 = 1;
			int val2 = 2;
		};

		class MyClassB
		{
		public:
			int val2;
			int val1;
		};

		MyClassA* pA = new MyClassA;
		MyClassB* pB1 = (MyClassB*)pA;
		// MyClassB* pB2 = static_cast<MyClassB*>(pA); // Error
		MyClassB* pB3 = reinterpret_cast<MyClassB*>(pA);

		cout << pB1->val1 << endl;
		cout << pB3->val1 << endl;

		delete pA;
	}

	cout << "포인터 간 캐스팅 2" << endl;
	{
		class CParent
		{

		};

		class CChild : public CParent
		{

		};

		CChild* pC = new CChild;

		CParent* pP1 = pC;
		CParent* pP2 = (CParent*)pC;
		CParent* pP3 = static_cast<CParent*>(pC);
		CParent* pP4 = reinterpret_cast<CParent*>(pC);


		CParent* pP = new CParent;

		// CChild* pC1 = pP; // Error
		CChild* pC2 = (CChild*)pP;
		CChild* pC3 = static_cast<CChild*>(pP);
		CChild* pC4 = reinterpret_cast<CChild*>(pP);


		delete pC;
		delete pP;
	}

	cout << "캐스팅과 오프셋" << endl;
	{	
		int i = 3;
		float f = float(i);

		printf("%f\n", f);
	}

	cout << "다중 상속 캐스팅" << endl;
	{
		class CParentA
		{
			int valA;
		};

		class CParentB
		{
			int valB;
		};

		class CChild : public CParentA, public CParentB
		{

		};

		CChild* pC = new CChild;

		CParentA* pA1 = pC;
		CParentA* pA2 = (CParentA*)pC;
		CParentA* pA3 = static_cast<CParentA*>(pC);
		CParentA* pA4 = reinterpret_cast<CParentA*>(pC);

		cout << pC << endl;
		cout << pA1 << endl;
		cout << pA2 << endl;
		cout << pA3 << endl;
		cout << pA4 << endl << endl;

		CParentB* pB1 = pC;
		CParentB* pB2 = (CParentB*)pC;
		CParentB* pB3 = static_cast<CParentB*>(pC);
		CParentB* pB4 = reinterpret_cast<CParentB*>(pC);

		cout << pC << endl;
		cout << pB1 << endl;
		cout << pB2 << endl;
		cout << pB3 << endl;
		cout << pB4 << endl;

		delete pC;
	}

	cout << "생성자 호출 순서" << endl;
	{
		class CParent
		{
		public:
			CParent()
			{
				cout << "CParent 생성자" << endl;
			}

			~CParent()
			{
				cout << "CParent 소멸자" << endl;
			}
		};

		class CChild : public CParent
		{
		public:
			CChild()
			{
				cout << "CChild 생성자" << endl;
			}

			~CChild()
			{
				cout << "CChild 소멸자" << endl;
			}
		};


		CChild c;

	}

	cout << "초기화 리스트" << endl;
	{
		class CParent
		{
		public:
			CParent()
			{
				cout << "CParent 기본 생성자" << endl;
			}

			CParent(int n1) : val1(n1)
			{
				cout << "CParent(int)" << endl;
			}
		private:
			int val1;
		};

		class CChild : public CParent
		{
		public:
			CChild()
			{
				cout << "CChild 기본 생성자" << endl;
			}

			CChild(int n1) : val2(n1)
			{
				cout << "CChild(int)" << endl;
			}

			CChild(int n1, int n2) : CParent(n1), val2(n2)
			{
				cout << "CChild(int,int)" << endl;
			}
		private:
			int val2;
		};

		CChild c;
		CChild c1(1);
		CChild c2(1,2);
	}

	cout << "가상 함수 1 " << endl;
	{
		class CAnimal
		{
		public:
			virtual void Bark()
			{
				cout << "Animal Bark" << endl;
			}
		};

		class CDog : public CAnimal
		{
		public:
			virtual void Bark() final
			{
				cout << "Dog Bark" << endl;
			}
		};

		class CCat : public CAnimal
		{
		public:
			virtual void Bark() final
			{
				cout << "Cat Bark" << endl;
			}
		};

		cout << "가상 함수2" << endl;

		CAnimal* pAnimal;

		CDog dog;
		CCat cat;

		srand((unsigned int)time(NULL));
		int n = rand() % 2;

		if (n == 0)
		{
			pAnimal = &dog;
		}
		else
		{
			pAnimal = &cat;
		}

		pAnimal->Bark();

	}
	cout << "가상함수 작동 원리" << endl;
	{
		class CAnimal
		{
		public:
			virtual void Bark()
			{
				cout << "Animal Bark" << endl;
			}

			virtual void Walk()
			{
				cout << "Animal Walk" << endl;
			}

			void Jump()
			{
				cout << "Animal Jump" << endl;
			}
		};

		class CDog : public CAnimal
		{
		public:
			virtual void Bark() final
			{
				cout << "Dog Bark" << endl;
			}
		};

		class CCat : public CAnimal
		{
		public:
			virtual void Bark() final
			{
				cout << "Cat Bark" << endl;
			}

			virtual void Walk() final
			{
				cout << "Cat Walk" << endl;
			}

			virtual void Run()
			{
				cout << " Cat Run" << endl;
			}
		};

		CAnimal* pAnimal;
		CCat cat;

		pAnimal = &cat;

		pAnimal->Bark();
		pAnimal->Walk();
		pAnimal->Jump();

		CDog dog;
		pAnimal = &dog;
		pAnimal->Walk();
	}
	
	cout << "생성자에서 가상함수" << endl;
	{
		class CParent
		{
		public:
			CParent()
			{
				VFunc();
			}
			virtual void VFunc()
			{
				cout << "CParent VFunc" << endl;
			}
		};

		class CChild : public CParent
		{
		public:
			CChild()
			{
				VFunc();
			}

			virtual void VFunc() final
			{
				cout << "CChild VFunc" << endl;
			}
		};

		CChild c;
	}

	cout << "가상 소멸자 1" << endl;
	{
		class CParent
		{
		public:
			~CParent()
			{
				cout << "CParent 소멸자" << endl;
			}
		};

		class CChild : public CParent
		{
		public:
			~CChild()
			{
				cout << "CChild 소멸자" << endl;
			}
		};

		CParent* pP = new CChild;

		delete pP;
	}

	cout << "가상 소멸자 2" << endl;
	{
		class CParent
		{
		public:
			virtual ~CParent()
			{
				cout << "CParent 소멸자" << endl;
			}
		};

		class CChild : public CParent
		{
		public:
			virtual ~CChild()
			{
				cout << "CChild 소멸자" << endl;
			}
		};

		CParent* pP = new CChild;

		delete pP;
	}
}
