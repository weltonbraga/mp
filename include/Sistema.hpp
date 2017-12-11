#include "Usuario.hpp"
#include "GerenteBD.hpp"
#include "json.hpp"
#include <locale>

using json = nlohmann::json;
using namespace std;

class Sistema
{
private:
	GerenteBD gBD;
	Usuario uLogado;
public:
	//Sistema();
	//~Sistema();
	void Run();

	bool Sair();

	bool EfetuaLogin();

	void NavegaConta();

	void GerenciarListas();

};