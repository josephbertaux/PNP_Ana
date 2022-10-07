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

#include "RooRealVar.h"
#include "RooFormulaVar.h"
#include "RooArgList.h"

class PNP_Ana
{
protected:
	std::string prompt_file_name = "";
	std::string prompt_list_name = "";
	std::string prompt_ntpl_name = "";

	std::string nprmpt_file_name = "";
	std::string nprmpt_list_name = "";
	std::string nprmpt_ntpl_name = "";

public:
	PNP_Ana();
	~PNP_Ana();

	int SetPromptFileName(std::string);
	int SetPromptListName(std::string);
	int SetPromptNtplName(std::string);

	int SetNprmptFileName(std::string);
	int SetNprmptListName(std::string);
	int SetNprmptNtplName(std::string);

	//...
};

#endif
