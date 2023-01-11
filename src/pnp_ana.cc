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

	int pT = 0;
	int cent = 0;
	int bdt = 20;

	int args = 4;
	if(argc > args)
	{
		try
		{
			pT = std::stoi(argv[args]);
		}
		catch(const std::invalid_argument&)
		{
			std::cout << "std::stoi failed to deduce argv[" << std::to_string(args) << "] (\"" << argv[args] << "\") as int" << std::endl;
			std::cout << "exiting" << std::endl;
			return 1;
		}
	}
	if(argc > args + 1)
	{
		try
		{
			cent = std::stoi(argv[args + 1]);
		}
		catch(const std::invalid_argument&)
		{
			std::cout << "std::stoi failed to deduce argv[" << std::to_string(args + 1) << "] (\"" << argv[args + 1] << "\") as int" << std::endl;
			std::cout << "exiting" << std::endl;
			return 1;
		}
	}
	if(argc > args + 2)
	{
		try
		{
			bdt = std::stoi(argv[args + 2]);
		}
		catch(const std::invalid_argument&)
		{
			std::cout << "std::stoi failed to deduce argv[" << std::to_string(args + 2) << "] (\"" << argv[args + 2] << "\") as int" << std::endl;
			std::cout << "exiting" << std::endl;
			return 1;
		}
	}

	if(!(0 <= pT and pT < pT_cuts.size()))
	{
		std::cout << "pT index (" << pT << ") outside of pT_cuts range" << std::endl;
		std::cout << "exiting" << std::endl;
		return 1;
	}
	if(!(0 <= cent and cent < cent_cuts.size()))
	{
		std::cout << "cent index (" << cent << ") outside of cent_cuts range" << std::endl;
		std::cout << "exiting" << std::endl;
		return 1;
	}
	if(!(0 <= bdt and bdt <= 40))
	{
		std::cout << "bdt index (" << bdt << ") outside of bdt range" << std::endl;
		std::cout << "exiting" << std::endl;
		return 1;
	}

	std::string suffix = "_pT" + std::to_string(pT) + "_cent" + std::to_string(cent);

	PNP_Ana pnp;

	pnp.SetTrainingWeightFileDir("/scratch/brown/jbertau/BD0_Ana_Fall_2022/training/training_subdirs/dir" + suffix + "/");
//	pnp.SetTrainingWeightFileDir(std::string(argv[1]) + "/dir" + suffix + "/");

	pnp.SetMassFitFileName("/home/jbertau/Data/Repositories/PNP_Ana/data/mass_fits/mass_fit" + suffix + ".txt");
	pnp.SetBkgdFitFileName("/home/jbertau/Data/Repositories/PNP_Ana/data/bkgd_fits/bkgd_fit" + suffix + ".txt");

	pnp.SetPromptFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/prompt/target/target0_1.root");
	pnp.SetPromptNtplName("prompt_ntpl");
	pnp.SetNprmptFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/nprmpt/target/target0_1.root");
	pnp.SetNprmptNtplName("nprmpt_ntpl");
	pnp.SetBkgrndFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/bkgrnd/target/target0_2.root");
	pnp.SetBkgrndNtplName("bkgrnd_ntpl");

	pnp.SetNtupleBDTVName("bdtv");
	pnp.SetBDTCut(std::to_string(bdt / 20.0 - 1.0));

	pnp.SetNtupleMassName("mass");
	pnp.SetNtupleMassMin("1.75");
	pnp.SetNtupleMassMax("1.95");

	pnp.AddCutVar("pT");
	pnp.AddCutVar("cent");
	pnp.AddCutExpr(pT_cuts[pT]);
	pnp.AddCutExpr(cent_cuts[cent]);

	pnp.AddTrainingVar("y");
	pnp.AddTrainingVar("vert_prob");
	pnp.AddTrainingVar("log_DLS");
	pnp.AddTrainingVar("log_DL");
	pnp.AddTrainingVar("pointing_angle");
	pnp.AddTrainingVar("trk_1_pt");
	pnp.AddTrainingVar("trk_2_pt");
	pnp.AddTrainingVar("xy_dca_sig_1");
	pnp.AddTrainingVar("xy_dca_sig_2");
	pnp.AddTrainingVar("z_dca_sig_1");
	pnp.AddTrainingVar("z_dca_sig_2");

	pnp.SetNumSigma("3");
	pnp.SetNumGauss("3");
	pnp.SetDegCheby("3");


	//...
	//pnp.SetOutputFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/mass_fit/out" + suffix + ".root");
	//pnp.SetPlotFile("/home/jbertau/Data/Repositories/PNP_Ana/data/mass_fits/plot" + suffix + ".png");	
	//pnp.SetPlotName("MassFit" + suffix);
	//pnp.SetPlotBins("100");
	//pnp.DoMassFit();


	//...
	//pnp.SetOutputFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/training/out" + suffix + ".root");
	//pnp.DoTraining();

	//...
	//pnp.SetOutputFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/bkgrnd_bdtv/bkgrnd" + suffix + ".root");
	//pnp.DoBackgroundCopy();

	//...
	pnp.SetBkgrndFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/bkgrnd_bdtv/bkgrnd" + suffix + ".root");
	pnp.SetBkgrndNtplName("bkgrnd_ntpl_bdtv");
	pnp.SetOutputFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/mass_fit/data/" + suffix + "_" + "bdtv" + std::to_string(bdt) + ".root");
	pnp.SetBkgdFitFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/mass_fit/fits/" + suffix + "_" + "bdtv" + std::to_string(bdt) + ".txt");
	pnp.SetPlotFile("/scratch/brown/jbertau/BD0_Ana_Fall_2022/mass_fit/plots/" + suffix + "_" + "bdtv" + std::to_string(bdt) + ".png");
	pnp.SetPlotName("BkgdFit" + suffix + "_bdtv" + std::to_string(bdt));
	pnp.SetPlotBins("100");
	pnp.DoBackgroundFit();

	return 0;
}
