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

class PNP_Ana
{
protected:
	std::string output_file_name = "";

	std::string plot_name = "";
	std::string plot_file = "";
	int plot_bins = -1;

	int num_sigma = -1;
	int num_gauss = -1;
	int deg_cheby = -1;

	std::string mass_fit_file_name = "";
	std::string bkgd_fit_file_name = "";
	std::string training_weight_file_dir = "";

	std::string prompt_file_name = "";
	std::string prompt_ntpl_name = "";

	std::string nprmpt_file_name = "";
	std::string nprmpt_ntpl_name = "";

	std::string bkgrnd_file_name = "";
	std::string bkgrnd_ntpl_name = "";

	std::string ntuple_bdtv_name = "";
	std::string ntuple_mass_name = "";

	float bdt_cut = 0.0;

	float mass_min;
	float mass_max;
	bool mass_min_set = false;
	bool mass_max_set = false;

	std::vector<std::string> cut_vars;
	std::vector<std::string> cut_exprs;

	std::vector<std::string> training_vars;
public:
	PNP_Ana();
	~PNP_Ana();

	int SetPlotName(std::string);
	int SetPlotFile(std::string);
	int SetPlotBins(std::string);

	int SetNumSigma(std::string);
	int SetNumGauss(std::string);
	int SetDegCheby(std::string);

	int SetOutputFileName(std::string);
	int SetMassFitFileName(std::string);
	int SetBkgdFitFileName(std::string);
	int SetTrainingWeightFileDir(std::string);

	int SetPromptFileName(std::string);
	int SetPromptNtplName(std::string);

	int SetNprmptFileName(std::string);
	int SetNprmptNtplName(std::string);

	int SetBkgrndFileName(std::string);
	int SetBkgrndNtplName(std::string);

	int SetNtupleBDTVName(std::string);
	int SetNtupleMassName(std::string);
	int SetNtupleMassMin(std::string);
	int SetNtupleMassMax(std::string);

	int SetBDTCut(std::string);

	int AddCutVar(std::string);
	int AddCutExpr(std::string);
	int AddTrainingVar(std::string);
	//...

	int TouchOutput(std::string, TFile*&);
	int TouchSource(std::string, std::string, TFile*&, TTree*&);

	int DoMassFit();
	int DoInclusiveTraining();
	int DoExclusiveTraining();
	int DoBackgroundCopy();
	int DoBackgroundFit();
};

#endif
