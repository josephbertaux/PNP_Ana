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

	int SetPromptFileName(std::vector<std::string>);
	//...
};

#endif
