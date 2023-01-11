#include "PNP_Wrapper.h"

//protected member functions

void PNP_Wrapper::MakePNPWMap()
{
	pnpw_map.clear();
	std::string s = "\n";

	pnpw_map["-h"] = 			PNPW_TPL
						{
							s +
							"./pnp_ana ...\n" +
							"\t\n" +
							"\t\n" +
							"\t\n" +
							"\t\n" +
							"\t\n" +
							s,
							this,
							&PNP_Wrapper::ShowHelp
						};

	pnpw_map["SetPlotName"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetPlotName\n" +
							s,
							this,
							&PNP_Wrapper::SetPlotName
						};

	pnpw_map["SetPlotFile"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetPlotFile\n" +
							s,
							this,
							&PNP_Wrapper::SetPlotFile
						};

	pnpw_map["SetPlotBins"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetPlotBins\n" +
							s,
							this,
							&PNP_Wrapper::SetPlotBins
						};

	pnpw_map["SetNumSigma"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetNumSigma\n" +
							s,
							this,
							&PNP_Wrapper::SetNumSigma
						};

	pnpw_map["SetNumGauss"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetNumGauss\n" +
							s,
							this,
							&PNP_Wrapper::SetNumGauss
						};

	pnpw_map["SetDegCheby"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetDegCheby\n" +
							s,
							this,
							&PNP_Wrapper::SetDegCheby
						};

	pnpw_map["SetOutputFileName"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetOutputFileName\n" +
							s,
							this,
							&PNP_Wrapper::SetOutputFileName
						};

	pnpw_map["SetMassFitFileName"] =	PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetMassFitFileName\n" +
							s,
							this,
							&PNP_Wrapper::SetMassFitFileName
						};

	pnpw_map["SetBkgdFitFileName"] =	PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetBkgdFitFileName\n" +
							s,
							this,
							&PNP_Wrapper::SetBkgdFitFileName
						};

	pnpw_map["SetTrainingWeightFileDir"] =	PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetTrainingWeightFileDir\n" +
							s,
							this,
							&PNP_Wrapper::SetTrainingWeightFileDir
						};

	pnpw_map["SetPromptFileName"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetPromptFileName\n" +
							s,
							this,
							&PNP_Wrapper::SetPromptFileName
						};

	pnpw_map["SetPromptNtplName"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetPromptNtplName\n" +
							s,
							this,
							&PNP_Wrapper::SetPromptNtplName
						};

	pnpw_map["SetNprmptFileName"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetNprmptFileName\n" +
							s,
							this,
							&PNP_Wrapper::SetNprmptFileName
						};

	pnpw_map["SetNprmptNtplName"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetNprmptNtplName\n" +
							s,
							this,
							&PNP_Wrapper::SetNprmptNtplName
						};

	pnpw_map["SetBkgrndFileName"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetBkgrndFileName\n" +
							s,
							this,
							&PNP_Wrapper::SetBkgrndFileName
						};

	pnpw_map["SetBkgrndNtplName"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetBkgrndNtplName\n" +
							s,
							this,
							&PNP_Wrapper::SetBkgrndNtplName
						};

	pnpw_map["SetBDTCut"] =			PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tSetBDTCut\n" +
							s,
							this,
							&PNP_Wrapper::SetBDTCut
						};

	pnpw_map["AddCutVar"] =			PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tAddCutVar\n" +
							s,
							this,
							&PNP_Wrapper::AddCutVar
						};

	pnpw_map["AddCutExpr"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tAddCutExpr\n" +
							s,
							this,
							&PNP_Wrapper::AddCutExpr
						};

	pnpw_map["AddTrainingVar"] =		PNPW_TPL
						{
							s +
							"Implements\n" +
							"\tAddTrainingVar\n" +
							s,
							this,
							&PNP_Wrapper::AddTrainingVar
						};

}

//public member functions

PNP_Wrapper::PNP_Wrapper()
{
	MakePNPWMap();
}

PNP_Wrapper::~PNP_Wrapper()
{
	//Do nothing
}

int PNP_Wrapper::Implement(std::string func, std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::Implement(std::string fucn, std::vector<std::string> args):" << std::endl;

	PNPW_MAP::const_iterator itr = pnpw_map.find(func);
	if(itr == pnpw_map.end())
	{
		output_str << "\tCould not find function '" << func << "'" << std::endl;
		return_val = 1;
		goto label;
	}
	if((std::get<1>(itr->second)->*std::get<2>(itr->second))(args))
	{
		output_str << "\tErrors implementing function '" << func << "'" << std::endl;
		return_val = 1;
		goto label;
	}
	
	label:
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::Config(std::string config_file_name, bool v)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::Config(std::string config_file_name, bool v):" << std::endl;

	uint u;
	size_t pos;
	int line_num = 0;
	std::string line_str = "";
	std::string config_str = "";
	std::ifstream config_file;

	std::string func;
	std::vector<std::string> args;

	if(config_file_name == "")
	{
		output_str << "\tPassed argument 'config_file_name' was empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	config_file.open(config_file_name, std::ifstream::in);
	if(!config_file.is_open())
	{
		output_str << "\tCould not get list:" << std::endl;
		output_str << "\t" << config_file_name << std::endl;
		return_val = 1;
		goto label;
	}

	output_str << "\tIn file:" << std::endl;
	output_str << "\t" << config_file_name << std::endl;

	config_str = "";
	line_str = "";
	while(true)
	{
		while(true)
		{
			if(config_file.bad())
			{
				output_str << "\tBad bit set" << std::endl;
				return_val = 1;
				goto label;
			}

			config_str += line_str;

			pos = config_str.find(closing_sym);
			if(pos != std::string::npos)
			{
				config_str = config_str.substr(0, pos + closing_sym.length());
				line_str = config_str.substr(pos + closing_sym.length());
				break;
			}

			std::getline(config_file, line_str);
			for(u = 0; u < cmmnts.size(); u++)
			{
				line_str = line_str.substr(0, line_str.find(cmmnts[u]));
			}
			line_num++;

			if(config_file.eof())
			{
				if(return_val)output_str << std::endl;
				output_str << "Reached end of config file" << std::endl;
				goto label;
			}
		}

		for(u = 0; u < prunes.size(); u++)
		{
			pos = config_str.find(prunes[u]);
			while(pos < config_str.length())
			{
				config_str.erase(pos, prunes[u].length());
				pos = config_str.find(prunes[u]);
			}
		}

		if(config_str.find(opening_sym) == std::string::npos)
		{
			output_str << "\tNo opening '" << opening_sym << "' found (line " << line_num << ")" << std::endl;
			return_val = 1;
		}
		if(config_str.find(closing_sym) == std::string::npos)
		{
			output_str << "\tNo closing '" << closing_sym << "' found (line " << line_num << ")" << std::endl;
			return_val = 1;
		}
		func = config_str.substr(0, config_str.find(opening_sym));
		config_str = config_str.substr(config_str.find(opening_sym) + opening_sym.length());
		config_str = config_str.substr(0, config_str.find(closing_sym));

		args.clear();
		pos = config_str.find(delim);
		while(pos < config_str.length())
		{
			args.push_back(config_str.substr(0, pos));
			config_str = config_str.substr(pos + delim.length());
			pos = config_str.find(delim);
		}
		if(config_str != "")args.push_back(config_str);

		if(v)
		{
			std::cout << "line " << line_num << ":" << std::endl;
			std::cout << "\t" << func;
			for(u = 0; u < args.size(); u++)
			{
				std::cout << " " << args[u];
			}
			std::cout << std::endl;
		}

		if(Implement(func, args))
		{
			std::cout << "\tline " << line_num << ":" << std::endl;
			std::cout << "\t" << func;
			for(u = 0; u < args.size(); u++)
			{
				std::cout << " " << args[u];
			}
			std::cout << std::endl;
			std::cout << std::endl;

			output_str << "\tProblem with config block ending on line: " << line_num << std::endl;
			return_val = 1;
		}

		config_str = "";
	}

	label:
	if(config_file.is_open())config_file.close();
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::ShowHelp(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::ShowHelp(std::vector<std::string> args):" << std::endl;

	bool flag = false;
	PNPW_MAP::const_iterator itr;

	if(args.size() >= 1)if(args[0] != "-h")goto label;

	return_val = 1;
	itr = pnpw_map.find("-h");
	if(args.size() >= 2)itr = pnpw_map.find(args[1]);
	if(itr == pnpw_map.end())
	{
		if(args.size() >= 2)
		{
			output_str << "\tCould not find requested help option:" << std::endl;
			output_str << "\t'" << args[1] << "'" << std::endl;
			output_str << "\tTry" << std::endl;
			output_str << "\t\t ./pnp_ana -h" << std::endl;
			output_str << "\tfor a full list of options" << std::endl;
		}
		flag = true;
		goto label;
	}
	std::cout << std::get<0>(itr->second);

	label:
	output_str << std::ends;
	if(flag)std::cout << output_str.str();
	return return_val;
}


//base function
int PNP_Wrapper::SetPlotName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetPlotName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetPlotName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetPlotFile(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetPlotFile(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetPlotFile(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetPlotBins(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetPlotBins(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetPlotBins(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetNumSigma(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetNumSigma(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetNumSigma(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetNumGauss(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetNumGauss(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetNumGauss(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetDegCheby(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetDegCheby(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetDegCheby(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetOutputFileName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetOutputFileName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetOutputFileName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetMassFitFileName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetMassFitFileName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetMassFitFileName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetBkgdFitFileName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetBkgdFitFileName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetBkgdFitFileName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetTrainingWeightFileDir(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetTrainingWeightFileDir(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetTrainingWeightFileDir(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetPromptFileName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetPromptFileName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetPromptFileName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetPromptNtplName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetPromptNtplName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetPromptNtplName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetNprmptFileName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetNprmptFileName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetNprmptFileName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetNprmptNtplName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetNprmptNtplName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetNprmptNtplName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetBkgrndFileName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetBkgrndFileName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetBkgrndFileName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetBkgrndNtplName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetBkgrndNtplName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetBkgrndNtplName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetNtupleBDTVName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetNtupleBDTVName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetNtupleBDTVName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetNtupleMassName(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetNtupleMassName(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetNtupleMassName(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetNtupleMassMin(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetNtupleMassMin(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetNtupleMassMin(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetNtupleMassMax(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetNtupleMassMax(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetNtupleMassMax(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::SetBDTCut(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::SetBDTCut(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.SetBDTCut(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::AddCutVar(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::AddCutVar(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.AddCutVar(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::AddCutExpr(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::AddCutExpr(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.AddCutExpr(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Wrapper::AddTrainingVar(std::vector<std::string> args)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Wrapper::AddTrainingVar(std::vector<std::string> args):" << std::endl;

	if(args.size() == 0)
	{
		output_str << "\tPassed argument 'args' is empty" << std::endl;
		return_val = 1;
		goto label;
	}

	return_val = pnp.AddTrainingVar(args[0]);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}
