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

int PNP_Ana::AddCutVar(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::AddCutVar(std::string s):" << std::endl;

	uint u;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	for(u = 0; u < cut_vars.size(); u++)
	{
		if(cut_vars[u] == s)
		{
			output_str << "\tPassed argument '" << s << "' has already been added" << std::endl;
			return_val = 1;
			goto label;
		}
	}

	cut_vars.push_back(s);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::AddCutExpr(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::AddCutExpr(std::string s):" << std::endl;

	uint u;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	for(u = 0; u < cut_exprs.size(); u++)
	{
		if(cut_exprs[u] == s)
		{
			output_str << "\tPassed argument '" << s << "' has already been added" << std::endl;
			return_val = 1;
			goto label;
		}
	}

	cut_exprs.push_back(s);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

//member access functions

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

	if(ntuple_mass_name == "")
	{
		output_str << "\tMember 'ntuple_mass_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	if(!prompt_tree->GetBranch(ntuple_mass_name.c_str()))
	{
		output_str << "\tCould not get branch:" << std::endl;
		output_str << "\t" << ntuple_mass_name << std::endl;
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

	if(ntuple_mass_name == "")
	{
		output_str << "\tMember 'ntuple_mass_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	if(!nprmpt_tree->GetBranch(ntuple_mass_name.c_str()))
	{
		output_str << "\tCould not get branch:" << std::endl;
		output_str << "\t" << ntuple_mass_name << std::endl;
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
	Long64_t n;
	float m = 0.0;
	float mu = 0.0;
	float sigma = 0.0;
	std::string s = "";

	TFile* output_file = nullptr;
	TFile* prompt_file = nullptr;
	TTree* prompt_tree = nullptr;
	TFile* nprmpt_file = nullptr;
	TTree* nprmpt_tree = nullptr;

	RooRealVar* mass = nullptr;
	RooRealVar* mean = nullptr;
	std::vector<RooRealVar*> sgmas = {};
	RooArgList coefs;
	RooArgList gsses;
	RooArgList cvars;
	RooAddPdf* sgnl = nullptr;

	RooDataSet* data_set = nullptr;
	RooDataSet* prompt_data_set = nullptr;
	RooDataSet* nprmpt_data_set = nullptr;
	RooFitResult* result = nullptr;

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

	mu = 0.0;
	sigma = 0.0;

	prompt_tree->SetBranchAddress(ntuple_mass_name.c_str(), &m);
	for(n = 0; n < prompt_tree->GetEntriesFast(); n++)
	{
		prompt_tree->GetEntry(n);
		mu += m;
		sigma += m*m;
	}
	nprmpt_tree->SetBranchAddress(ntuple_mass_name.c_str(), &m);
	for(n = 0; n < nprmpt_tree->GetEntriesFast(); n++)
	{
		nprmpt_tree->GetEntry(n);
		mu += m;
		sigma += m*m;
	}

	n = prompt_tree->GetEntriesFast() + nprmpt_tree->GetEntriesFast();
	if(n == 0)
	{
		output_str << "\tNo entries found in either prompt or nprmpt tree" << std::endl;
		return_val = 1;
		goto label;
	}
	mu /= n;
	sigma /= n;

	sigma = sqrt(sigma - mu * mu);

	mass = new RooRealVar(ntuple_mass_name.c_str(), ntuple_mass_name.c_str(), -FLT_MAX, FLT_MAX);
	mean = new RooRealVar("mu", "mu", mu, mu - 3.0 * sigma, mu + 3.0 * sigma);
	for(i = 0; i < num_pdf; i++)
	{
		s = "sigma_";
		s += std::to_string(i);
		sgmas.push_back(new RooRealVar(s.c_str(), s.c_str(), sigma / (1 << i), 0.0, 3.0 * sigma));

		s = "c_";
		s += std::to_string(i);
		coefs.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), n / num_pdf, 0.0, n)));

		s = "gauss_";
		s += std::to_string(i);
		gsses.addOwned(*(new RooGaussian(s.c_str(), s.c_str(), *mass, *mean, *sgmas.back())));
	}
	s = "sgnl";
	sgnl = new RooAddPdf(s.c_str(), s.c_str(), gsses, coefs);

	cvars.addOwned(*mass);
	for(i = 0; i < cut_vars.size(); i++)
	{
		cvars.addOwned(*(new RooRealVar(cut_vars[i].c_str(), cut_vars[i].c_str(), -FLT_MAX, FLT_MAX)));
	}

	s = "";
	i = 0;
	while(cut_exprs.size() > 0)
	{
		s += "(";
		s += cut_exprs[i];
		s += ")";

		i++;
		if(i >= cut_exprs.size())break;

		s += "&&";
	}

	data_set = new RooDataSet("data_set", "data_set", cvars);
	
	if(s != "")
	{
		prompt_data_set = new RooDataSet("prompt_data_set", "prompt_data_set", cvars, RooFit::Import(*prompt_tree), RooFit::Cut(s.c_str()));
		nprmpt_data_set = new RooDataSet("nprmpt_data_set", "nprmpt_data_set", cvars, RooFit::Import(*nprmpt_tree), RooFit::Cut(s.c_str()));
	}
	else
	{
		prompt_data_set = new RooDataSet("prompt_data_set", "prompt_data_set", cvars, RooFit::Import(*prompt_tree));
		nprmpt_data_set = new RooDataSet("nprmpt_data_set", "nprmpt_data_set", cvars, RooFit::Import(*nprmpt_tree));
	}
	data_set->append(*prompt_data_set);
	data_set->append(*nprmpt_data_set);

	result = sgnl->fitTo(*data_set);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	if(output_file)
	{
		output_file->cd();
		if(sgnl)sgnl->Write();
		if(result)result->Write();
		output_file->Write();
		output_file->Close();
	}
	if(mean)delete mean;
	for(i = 0; i < sgmas.size(); i++)if(sgmas[i])delete sgmas [i];
	if(data_set)delete data_set;
	if(prompt_data_set)delete prompt_data_set;
	if(nprmpt_data_set)delete nprmpt_data_set;

	return return_val;
}
