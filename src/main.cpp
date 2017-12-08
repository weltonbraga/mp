/**************************************
 *                                    *
 *  https://github.com/nlohmann/json  *
 *                                    *
 **************************************/

#ifndef TEST

#include <iostream>
#include <string>
#include "Usuario.hpp"
#include "GerenteBD.hpp"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	GerenteBD::Run();
	return 0;
}

#endif // TEST
