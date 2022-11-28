#include "PNP_Ana.h"
#include "PNP_Wrapper.h"

int main(int argc, char* argv[])
{
	PNP_Ana pnp;

	pnp.SetOutputFileName("output.root");
	pnp.SetMassFitFileName("mass_fit.txt");

	pnp.SetPromptFileName("debug/prompt.root");
	pnp.SetPromptNtplName("prompt");
	pnp.SetNprmptFileName("debug/nprmpt.root");
	pnp.SetNprmptNtplName("nprmpt");
	pnp.SetBkgrndFileName("debug/bkgrnd.root");
	pnp.SetBkgrndNtplName("bkgrnd");

	pnp.SetNtupleMassName("mass");

	pnp.AddCutVar("d");
	pnp.AddCutExpr("d>7");

	pnp.AddTrainingVar("a");
	pnp.AddTrainingVar("b");
	pnp.AddTrainingVar("c");
	pnp.AddTrainingVar("d");

	pnp.SetNumSigma("3");
	pnp.SetNumGauss("2");

	//pnp.DoMassFit();
	pnp.DoTraining();
	//pnp.DoBackgroundFit();

	return 0;
}
