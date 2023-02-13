#include "PNP_Ana.h"
#include "PNP_Config.h"

int main(int argc, char* argv[])
{
	//this is submitted with 3 command line arguments before the pT and cent indexes appear
	int args = 3;

	std::cout << PNP_Config::bdtSuffix(args, argc, argv) << std::endl; //for debugging

	PNP_Ana* pnp = PNP_Config::Config(args, argc, argv);
	if(!pnp)return 1;
	pnp->GetOptimalCut();
	delete pnp;
	return 0;
}
