

#include <iostream>
#include "pch.h"
#include "Tests.h"


int main(void)
{
	unique_ptr<CInterface> ci = make_unique<CType>();


	ci->Run();


	return 0;
}