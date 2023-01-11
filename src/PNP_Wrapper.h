#ifndef PNP_WRAPPER_H
#define PNP_WRAPPER_H

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "PNP_Ana.h"

class PNP_Wrapper
{
public:
	typedef int(PNP_Wrapper::*PNPW_MMBR_FUNC)(std::vector<std::string>);
	typedef std::tuple<std::string, PNP_Wrapper*, PNPW_MMBR_FUNC> PNPW_TPL;
	typedef std::map<std::string, PNPW_TPL> PNPW_MAP;

protected:
	PNPW_MAP pnpw_map;
	void MakePNPWMap();

	std::vector<std::string> cmmnts = {"//", "#"};
	std::vector<std::string> prunes = {" ", "\t", "\n"};
	
	std::string opening_sym = "{";
	std::string closing_sym = "}";
	std::string delim = ";";

public:
	PNP_Ana pnp;

	PNP_Wrapper();
	~PNP_Wrapper();

	int Implement(std::string, std::vector<std::string>);
	int Config(std::string, bool);

	int ShowHelp(std::vector<std::string>);

	int SetPlotName(std::vector<std::string>);
	int SetPlotFile(std::vector<std::string>);
	int SetPlotBins(std::vector<std::string>);

	int SetNumSigma(std::vector<std::string>);
	int SetNumGauss(std::vector<std::string>);
	int SetDegCheby(std::vector<std::string>);

	int SetOutputFileName(std::vector<std::string>);
	int SetMassFitFileName(std::vector<std::string>);
	int SetBkgdFitFileName(std::vector<std::string>);
	int SetTrainingWeightFileDir(std::vector<std::string>);

	int SetPromptFileName(std::vector<std::string>);
	int SetPromptNtplName(std::vector<std::string>);

	int SetNprmptFileName(std::vector<std::string>);
	int SetNprmptNtplName(std::vector<std::string>);

	int SetBkgrndFileName(std::vector<std::string>);
	int SetBkgrndNtplName(std::vector<std::string>);

	int SetNtupleBDTVName(std::vector<std::string>);
	int SetNtupleMassName(std::vector<std::string>);
	int SetNtupleMassMin(std::vector<std::string>);
	int SetNtupleMassMax(std::vector<std::string>);

	int SetBDTCut(std::vector<std::string>);

	int AddCutVar(std::vector<std::string>);
	int AddCutExpr(std::vector<std::string>);
	int AddTrainingVar(std::vector<std::string>);
	//...
};

#endif
