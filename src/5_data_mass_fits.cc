#include "PNP_Ana.h"
#include "PNP_Config.h"

int main(int argc, char* argv[])
{
	//this is submitted with 4 command line arguments before the pT, cent, and bdt indexes appear
	int args = 4;

	std::cout << PNP_Config::bdtSuffix(args, argc, argv) << std::endl; //for debugging

	PNP_Ana* pnp = PNP_Config::Config(args, argc, argv);
	if(!pnp)return 1;
	pnp->DoBackgroundFit();
	delete pnp;
	return 0;
}
