#include "PNP_Ana.h"
#include "PNP_Wrapper.h"

int main(int argc, char* argv[])
{
	std::vector<std::string> pT_cuts =
	{
		"(6.0<=pT)&&(pT<40.0)",
		"(6.0<=pT)&&(pT<8.0)",
		"(8.0<=pT)&&(pT<10.0)",
		"(10.0<=pT)&&(pT<12.5)",
		"(12.5<=pT)&&(pT<15.0)",
		"(15.0<=pT)&&(pT<20.0)",
		"(20.0<=pT)&&(pT<30.0)",
		"(30.0<=pT)&&(pT<40.0)"
	};

	std::vector<std::string> cent_cuts =
	{
		"(0.0<=cent)&&(cent<90.0)",
		"(0.0<=cent)&&(cent<10.0)",
		"(10.0<=cent)&&(cent<30.0)",
		"(30.0<=cent)&&(cent<50.0)",
		"(50.0<=cent)&&(cent<90.0)",
	};

	PNP_Ana pnp;

	pnp.SetOutputFileName("output.root");
	//pnp.SetPromptFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/prompt/target/target0_1.root");
	//pnp.SetPromptNtplName("prompt_ntpl");
	//pnp.SetNprmptFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/nprmpt/target/target0_1.root");
	//pnp.SetNprmptNtplName("nprmpt_ntpl");
	//pnp.SetNprmptFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/bkgrnd/target/target.root");
	//pnp.SetNprmptNtplName("bkgrnd_ntpl");

	pnp.SetPromptFileName("/home/jbertau/Data/Repositories/PNP_Ana/debug/prompt_for_debug.root");
	pnp.SetPromptNtplName("prompt_for_debug");
	pnp.SetNprmptFileName("/home/jbertau/Data/Repositories/PNP_Ana/debug/nprmpt_for_debug.root");
	pnp.SetNprmptNtplName("nprmpt_for_debug");
	pnp.SetBkgrndFileName("/home/jbertau/Data/Repositories/PNP_Ana/debug/bkgrnd_for_debug.root");
	pnp.SetBkgrndNtplName("bkgrnd_for_debug");

	pnp.SetMassFitFileName("mass_fit.txt");
	pnp.SetNtupleMassName("mass");
	pnp.SetNtupleMassMin("-86.4838");
	pnp.SetNtupleMassMax("88.6556");

	//pnp.AddCutVar("pT");
	//pnp.AddCutVar("cent");
	//pnp.AddCutExpr(pT_cuts[0]);
	//pnp.AddCutExpr(cent_cuts[0]);

	//pnp.AddTrainingVar("a");
	//pnp.AddTrainingVar("b");
	//pnp.AddTrainingVar("c");
	//pnp.AddTrainingVar("d");

	pnp.SetNumSigma("3");
	pnp.SetNumGauss("2");
	pnp.SetDegCheby("3");

	pnp.DoMassFit();
	//pnp.DoBackgroundFit();
	//pnp.DoTraining();

	return 0;
}
