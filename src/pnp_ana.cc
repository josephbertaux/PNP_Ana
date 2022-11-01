#include "PNP_Ana.h"
#include "PNP_Wrapper.h"

int main(int argc, char* argv[])
{
	PNP_Ana pnp;

	pnp.SetOutputFileName("output.root");

	pnp.SetPromptFileName("debug/prompt.root");
	pnp.SetPromptNtplName("prompt");
	pnp.SetNprmptFileName("debug/nprmpt.root");
	pnp.SetNprmptNtplName("nprmpt");

	pnp.SetNtupleMassName("mass");

//	pnp.AddCutVar("b");
//	pnp.AddCutExpr("b>3");

	pnp.DoMassFit(2);

	return 0;
}
