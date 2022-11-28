#ifndef PNP_ANA_H
#define PNP_ANA_H

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "TFile.h"
#include "TTree.h"
#include "TNtuple.h"

#include "RooFit.h"
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

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"

class PNP_Ana
{
protected:
	std::string output_file_name = "";

	int num_sigma;
	int num_gauss;
	int deg_cheby;

	std::string mass_fit_file_name = "";

	std::string prompt_file_name = "";
	std::string prompt_ntpl_name = "";

	std::string nprmpt_file_name = "";
	std::string nprmpt_ntpl_name = "";

	std::string bkgrnd_file_name = "";
	std::string bkgrnd_ntpl_name = "";

	std::string ntuple_mass_name = "";

	std::vector<std::string> cut_vars;
	std::vector<std::string> cut_exprs;

	std::vector<std::string> training_vars;
public:
	PNP_Ana();
	~PNP_Ana();

	int SetNumSigma(std::string);
	int SetNumGauss(std::string);
	int SetDegCheby(std::string);

	int SetOutputFileName(std::string);
	int SetMassFitFileName(std::string);

	int SetPromptFileName(std::string);
	int SetPromptNtplName(std::string);

	int SetNprmptFileName(std::string);
	int SetNprmptNtplName(std::string);

	int SetBkgrndFileName(std::string);
	int SetBkgrndNtplName(std::string);

	int SetNtupleMassName(std::string);

	int AddCutVar(std::string);
	int AddCutExpr(std::string);
	int AddTrainingVar(std::string);
	//...

	int TouchOutput(std::string, TFile*&);
	int TouchSource(std::string, std::string, TFile*&, TTree*&);

	int DoMassFit();
	int DoTraining();
	int DoBackgroundFit();
};

#endif
