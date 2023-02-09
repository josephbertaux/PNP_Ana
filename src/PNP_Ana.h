#ifndef PNP_ANA_H
#define PNP_ANA_H

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

#include "TFile.h"
#include "TTree.h"
#include "TNtuple.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TROOT.h"

#include "RooFit.h"
#include "RooPlot.h"
#include "RooDataSet.h"
#include "RooFitResult.h"
#include "RooArgList.h"
#include "RooArgSet.h"
#include "RooRealVar.h"
#include "RooFormulaVar.h"
#include "RooGenericPdf.h"
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"

#include "TMVA/Config.h"
#include "TMVA/Tools.h"
#include "TMVA/Factory.h"
#include "TMVA/Reader.h"
#include "TMVA/DataLoader.h"

class PNP_Config;

class PNP_Ana
{
protected:
	std::string mc_mass_fit_root_file_name = "";	//possibly vestegial
	std::string mc_mass_fit_text_file_name = "";
	std::string mc_mass_fit_plot_file_name = "";
	std::string mc_mass_fit_base_name = "";

	std::string training_dir = "";
	std::string training_inc_subdir = "";
	std::string training_exc_subdir = "";

	std::string data_mass_fit_root_file_name = "";	//possibly vestegial
	std::string data_mass_fit_text_file_name = "";
	std::string data_mass_fit_plot_file_name = "";
	std::string data_mass_fit_base_name = "";

	int plot_bins = -1;

	std::string prompt_file_name = "";
	std::string nprmpt_file_name = "";
	std::string bkgrnd_file_name = "";

	std::string prompt_ntpl_name = "";
	std::string nprmpt_ntpl_name = "";
	std::string bkgrnd_ntpl_name = "";

	std::string ntuple_mass_name = "";
	float mass_min = -1.0;
	float mass_max = -1.0;

	std::string traind_file_name = "";
	std::string traind_ntpl_name = "";
	std::string bdt_inc_name = "";
	std::string bdt_exc_name = "";
	float bdt_cut = 0.0;

	int num_sigma = -1;
	int num_gauss = -1;
	int deg_cheby = -1;

	std::vector<std::string> cut_vars;
	std::vector<std::string> cut_exprs;

	std::vector<std::string> training_vars;

	friend PNP_Config;
public:
	PNP_Ana();
	~PNP_Ana();

	int AddCutVar(std::string);
	int AddCutExpr(std::string);
	int AddTrainingVar(std::string);
	//...

	int TouchOutput(std::string, TFile*&);
	int TouchSource(std::string, std::string, TFile*&, TTree*&);

	int DoMassFit();
	int DoInclusiveTraining();
	int DoExclusiveTraining();
	int ApplyTraining();
	int DoBackgroundFit();
};

#endif
