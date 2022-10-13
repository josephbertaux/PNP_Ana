#include "PNP_Ana.h"

//protected member functions

//public member functions

PNP_Ana::PNP_Ana()
{
	//Do nothing
}

PNP_Ana::~PNP_Ana()
{
	//Do nothing
}

int PNP_Ana::SetOutputFileName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetOutputFileName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	output_file_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetPromptFileName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetPromptFileName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	prompt_file_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetPromptListName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetPromptListName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	prompt_list_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetPromptNtplName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetPromptNtplName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	prompt_ntpl_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetNprmptFileName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNprmptFileName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	nprmpt_file_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetNprmptListName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNprmptListName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	nprmpt_list_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetNprmptNtplName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNprmptNtplName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	nprmpt_ntpl_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetNtupleMassName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNtupleMassName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	ntuple_mass_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::TouchOutput(TFile*& output_file)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::TouchOutput(TFile* output_file):" << std::endl;
	output_file = nullptr;

	if(output_file_name == "")
	{
		output_str << "\tMember 'output_file_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	output_file = TFile::Open(output_file_name.c_str(), "UPDATE");
	if(!output_file)
	{
		output_str << "\tCould not get file:" << std::endl;
		output_str << "\t" << output_file_name << std::endl;
		output_str << "\tRecreating..." << std::endl;

		output_file = TFile::Open(output_file_name.c_str(), "RECREATE");
	}
	if(!output_file)
	{
		output_str << "\tFailed to recreate file:" << std::endl;
		output_str << "\t" << output_file_name << std::endl;
		return_val = 1;
		goto label;
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::TouchPrompt(TFile*& prompt_file, TTree*& prompt_tree)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::TouchPrompt(TFile* prompt_file, TTree* prompt_tree):" << std::endl;
	prompt_file = nullptr;
	prompt_tree = nullptr;

	if(prompt_file_name == "")
	{
		output_str << "\tMember 'prompt_file_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	prompt_file = TFile::Open(prompt_file_name.c_str(), "READ");
	if(!prompt_file)
	{
		output_str << "\tCould not get file:" << std::endl;
		output_str << "\t" << prompt_file_name << std::endl;
		return_val = 1;
		goto label;
	}

	if(prompt_ntpl_name == "")
	{
		output_str << "\tMember 'prompt_ntpl_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	prompt_tree = (TTree*)prompt_file->Get(prompt_ntpl_name.c_str());
	if(!prompt_tree)
	{
		output_str << "\tCould not get tree:" << std::endl;
		output_str << "\t" << prompt_ntpl_name << std::endl;
		return_val = 1;
		goto label;
	}


	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::TouchNprmpt(TFile*& nprmpt_file, TTree*& nprmpt_tree)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::TouchNprmpt(TFile* nprmpt_file, TTree* nprmpt_tree):" << std::endl;
	nprmpt_file = nullptr;
	nprmpt_tree = nullptr;

	if(nprmpt_file_name == "")
	{
		output_str << "\tMember 'nprmpt_file_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	nprmpt_file = TFile::Open(nprmpt_file_name.c_str(), "READ");
	if(!nprmpt_file)
	{
		output_str << "\tCould not get file:" << std::endl;
		output_str << "\t" << nprmpt_file_name << std::endl;
		return_val = 1;
		goto label;
	}

	if(nprmpt_ntpl_name == "")
	{
		output_str << "\tMember 'nprmpt_ntpl_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	nprmpt_tree = (TTree*)nprmpt_file->Get(nprmpt_ntpl_name.c_str());
	if(!nprmpt_tree)
	{
		output_str << "\tCould not get tree:" << std::endl;
		output_str << "\t" << nprmpt_ntpl_name << std::endl;
		return_val = 1;
		goto label;
	}


	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::DoMassFit(int num_pdf)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::DoMassFit():" << std::endl;

	int i = 0;
	float mu = 0.0;
	float sigma = 1.0;
	std::string s = "";
	std::string t = "";

	TFile* output_file = nullptr;

	TFile* prompt_file = nullptr;
	TTree* prompt_tree = nullptr;

	TFile* nprmpt_file = nullptr;
	TTree* nprmpt_tree = nullptr;

	RooDataSet data_set;
	RooDataSet prompt_data_set;
	RooDataSet nprmpt_data_set;

	RooArgList base_params;
	RooArgList meta_params;
	RooGenericPdf* pdf = nullptr;

	return_val = TouchOutput(output_file);
	if(return_val)goto label;

	return_val = TouchPrompt(prompt_file, prompt_tree);
	if(return_val)goto label;

	return_val = TouchNprmpt(nprmpt_file, nprmpt_tree);
	if(return_val)goto label;

	if(ntuple_mass_name == "")
	{
		output_str << "\tMember 'ntuple_mass_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	base_params.addOwned(*(new RooRealVar(ntuple_mass_name.c_str(), ntuple_mass_name.c_str(), 0.0, -FLT_MAX, FLT_MAX)));
	for(i = 0; i < num_pdf; i++)
	{
		s = "mu_";
		s += std::to_string(i);
		base_params.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), 0.0, -FLT_MAX, FLT_MAX)));

		s = "sigma_";
		s += std::to_string(i);
		base_params.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), sigma / (1 << i), 0.0, FLT_MAX)));
	}

	for(i = 0; i < num_pdf; i++)
	{
		s = "c_";
		s += std::to_string(i);
		if(i)	meta_params.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), 0.0, -FLT_MAX, FLT_MAX)));
		else	meta_params.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), 1.0, -FLT_MAX, FLT_MAX)));

		s = "gauss_";
		s += std::to_string(i);

		t = "0.3989422804*exp(-0.5*pow((";
		t += ntuple_mass_name;
		t += "-mu_";
		t += std::to_string(i);
		t += ")/sigma_";
		t += std::to_string(i);
		t += ",2))/sigma_";
		t += std::to_string(i);

		meta_params.addOwned(*(new RooFormulaVar(s.c_str(), s.c_str(), t.c_str(), base_params)));
	}

	s = "sum_";
	s += std::to_string(num_pdf);
	s += "_gauss";

	t = "(";
	i = 0;
	while(true)
	{
		t += "c_";
		t += std::to_string(i);
		t += "*";
		t += "gauss_";
		t += std::to_string(i);

		i++;
		if(i >= num_pdf)break;

		t += "+";
	}
	t += ")/(";
	i = 0;
	while(true)
	{
		t += "c_";
		t += std::to_string(i);

		i++;
		if(i >= num_pdf)break;

		t += "+";
	}
	t += ")";

	pdf = new RooGenericPdf(s.c_str(), s.c_str(), t.c_str(), meta_params);

	data_set = RooDataSet("data_set", "data_set", RooArgSet(base_params[0]));
	prompt_data_set = RooDataSet("prompt_data_set", "prompt_data_set", prompt_tree, RooArgSet(base_params[0]));
	nprmpt_data_set = RooDataSet("nprmpt_data_set", "nprmpt_data_set", nprmpt_tree, RooArgSet(base_params[0]));

	data_set.append(prompt_data_set);
	data_set.append(nprmpt_data_set);

	std::cout << data_set.sumEntries() << std::endl;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	if(output_file)
	{
		output_file->cd();
		if(pdf)pdf->Write();		
		output_file->Write();
		output_file->Close();
	}
	return return_val;
}
