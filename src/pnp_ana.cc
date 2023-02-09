#include "PNP_Ana.h"
#include "PNP_Config.h"

int main(int argc, char* argv[])
{
	PNP_Ana* pnp = PNP_Config::Config(argc, argv);
	if(!pnp)return 1;

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
	//pnp.SetBkgrndFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/bkgrnd_bdtv/bkgrnd" + suffix + ".root");
	//pnp.SetBkgrndNtplName("bkgrnd_ntpl_bdtv");
	//pnp.SetOutputFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/mass_fit/data/" + suffix + "_" + "bdtv" + std::to_string(bdt) + ".root");
	//pnp.SetBkgdFitFileName("/scratch/brown/jbertau/BD0_Ana_Fall_2022/mass_fit/fits/" + suffix + "_" + "bdtv" + std::to_string(bdt) + ".txt");
	//pnp.SetPlotFile("/scratch/brown/jbertau/BD0_Ana_Fall_2022/mass_fit/plots/" + suffix + "_" + "bdtv" + std::to_string(bdt) + ".png");
	//pnp.SetPlotName("BkgdFit" + suffix + "_bdtv" + std::to_string(bdt));
	//pnp.SetPlotBins("100");
	//pnp.DoBackgroundFit();

	if(pnp)delete pnp;
	return 0;
}
