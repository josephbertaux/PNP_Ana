#include "PNP_Ana.h"
#include "PNP_Config.h"

int main(int argc, char* argv[])
{
	//this is submitted with 1 command line arguments before the pT and cent indexes appear
	int args = 1;

	std::cout << PNP_Config::pTcentSuffix(args, argc, argv) << std::endl; //for debugging

	PNP_Ana* pnp = PNP_Config::Config(args, argc, argv);
	if(!pnp)return 1;
	pnp->DoExclusiveTraining();
	delete pnp;
	return 0;
}
