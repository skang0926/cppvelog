

#include <iostream>
#include "pch.h"
#include "Tests.h"

int main(void)
{
	unique_ptr<CInterface> ci = make_unique<CDD>();

	ci->Run();


	return 0;
}