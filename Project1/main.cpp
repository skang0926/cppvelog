

#include <iostream>
#include "pch.h"
#include "Tests.h"

int main(void)
{
	//unique_ptr<CInterface> ci = make_unique<CType>();
	//ci->Run(); // CType�� Run �Լ�

	//unique_ptr<CInterface> ci = make_unique<CPointer>();
	//ci->Run(); // CPointer�� Run �Լ�

	unique_ptr<CInterface> ci = make_unique<CMemory>();
	ci->Run();

	return 0;
}