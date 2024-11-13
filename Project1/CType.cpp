#include "CType.h"

/// ���� ���� : Ÿ�� ///////////////////////////////////////////////////
/// https://velog.io/@skang0926/%ED%83%80%EC%9E%85
///////////////////////////////////////////////////////////////////////////////

void CType::Run()
{
	{
		cout << "float�� ���� �޸� ī��" << endl;

		float f = 0;
		int i = 1;
		memcpy(&f, &i, 4);

		cout << f << endl;  // 00000000 00000000 00000000 00000001 �� ��Ʈ�� flaot�� ó���ϸ�?
	}
	
	{
		cout << endl << "int�� ǥ�� ����" << endl;

		unsigned int uimin = 0x00000000; // 00000000 00000000 00000000 00000000
		unsigned int uimax = 0xFFFFFFFF; // 11111111 11111111 11111111 11111111;

		int min = 0x80000000; // 10000000 00000000 00000000 00000000
		int max = 0x7FFFFFFF; // 00000000 00000000 00000000 00000000

		cout << "ui  min = " << uimin << endl;
		cout << "ui  max = " << uimax << endl;

		cout << "int min = " << min << endl;
		cout << "int max = " << max << endl;
	}

	{
		cout << endl << "��Ʈ�� float ǥ���ϱ� 1" << endl;
		unsigned int ui = 0x81B40000; // 1000 0001 1011 0100 0000 0000 0000 0000
		float f; 
		memcpy(&f, &ui, 4);

		cout << "f value is : " << f << endl;
	}

	{
		cout << endl << "��Ʈ�� float ǥ���ϱ� 2" << endl;

		unsigned int ui = 0xC1340000; // 1100 0001 0011 0100 0000 0000 0000 0000
		float f;
		memcpy(&f, &ui, 4);

		cout << "f value is : " << f << endl;
	}

	{
		cout << endl << "�ε� �Ҽ��� ǥ�� �Ѱ�" << endl;
		float f[10];
		f[0] = 8388608.0;
		f[1] = 8388608.1;
		f[2] = 8388608.2;
		f[3] = 8388608.3;
		f[4] = 8388608.4;

		f[5] = 8388608.5;
		f[6] = 8388608.6;
		f[7] = 8388608.7;
		f[8] = 8388608.8;
		f[9] = 8388608.9;
		
		cout.precision(32);
		for (int i = 0; i < 10; i++)
		{
			cout << f[i] << endl;
		}
	}

	{
		float f[8];
		f[0] = 33554432;
		f[1] = 33554433;
		f[2] = 33554434;
		f[3] = 33554435;
		f[4] = 33554436;
		f[5] = 33554437;
		f[6] = 33554438;
		f[7] = 33554439;

		cout.precision(32);
		for (int i = 0; i < 8; i++)
		{
			cout << f[i] << endl;
		}
	}

	{
		cout << endl << "�ε��Ҽ����� ���Ѱ� NaN" << endl;
		unsigned int ui1 = 0x7f800000; // 0111 1111 1000 0000 0000 0000 0000 0000
		unsigned int ui2 = 0x7f800001;
		float f1;
		float f2;
		memcpy(&f1, &ui1, 4);
		memcpy(&f2, &ui2, 4);
		cout << f1 << endl;
		cout << f2 << endl;
	}
	
}
