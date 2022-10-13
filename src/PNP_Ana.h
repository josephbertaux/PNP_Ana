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

#include "RooArgList.h"
#include "RooRealVar.h"
#include "RooFormulaVar.h"
#include "RooGenericPdf.h"
#include "RooDataSet.h"

class PNP_Ana
{
protected:
	std::string output_file_name = "";

	std::string prompt_file_name = "";
	std::string prompt_list_name = "";
	std::string prompt_ntpl_name = "";

	std::string nprmpt_file_name = "";
	std::string nprmpt_list_name = "";
	std::string nprmpt_ntpl_name = "";

	std::string ntuple_mass_name = "";
public:
	PNP_Ana();
	~PNP_Ana();

	int SetOutputFileName(std::string);

	int SetPromptFileName(std::string);
	int SetPromptListName(std::string);
	int SetPromptNtplName(std::string);

	int SetNprmptFileName(std::string);
	int SetNprmptListName(std::string);
	int SetNprmptNtplName(std::string);

	int SetNtupleMassName(std::string);
	//...
	int TouchOutput(TFile*&);
	int TouchPrompt(TFile*&, TTree*&);
	int TouchNprmpt(TFile*&, TTree*&);

	int DoMassFit(int);
};

#endif
