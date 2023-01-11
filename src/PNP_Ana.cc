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

int PNP_Ana::SetMassFitFileName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetMassFitFileName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	mass_fit_file_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetBkgdFitFileName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetBkgdFitFileName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	bkgd_fit_file_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetTrainingWeightFileDir(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetTrainingWeightFileDir(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	training_weight_file_dir = s;

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

int PNP_Ana::SetBkgrndFileName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetBkgrndFileName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	bkgrnd_file_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetBkgrndNtplName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetBkgrndNtplName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	bkgrnd_ntpl_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetNtupleBDTVName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNtupleTMVAName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	ntuple_bdtv_name = s;

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

int PNP_Ana::SetNtupleMassMin(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNtupleMassMin(std::string s):" << std::endl;

	try
	{
		mass_min = std::stof(s);
	}
	catch(const std::invalid_argument&)
	{
		output_str << "\tstd::stof falled to cast argument \"" << s << "\" as float" << std::endl;
		return_val = 1;
		goto label;
	}

	mass_min_set = true;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetNtupleMassMax(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNtupleMassMax(std::string s):" << std::endl;

	try
	{
		mass_max = std::stof(s);
	}
	catch(const std::invalid_argument&)
	{
		output_str << "\tstd::stof falled to cast argument \"" << s << "\" as float" << std::endl;
		return_val = 1;
		goto label;
	}

	mass_max_set = true;

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

int PNP_Ana::AddTrainingVar(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::AddTrainingVar(std::string s):" << std::endl;

	uint u;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	for(u = 0; u < training_vars.size(); u++)
	{
		if(training_vars[u] == s)
		{
			output_str << "\tPassed argument '" << s << "' has already been added" << std::endl;
			return_val = 1;
			goto label;
		}
	}

	training_vars.push_back(s);

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetPlotName(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetPlotName(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	plot_name = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetPlotFile(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetPlotFile(std::string s):" << std::endl;

	if(s == "")
	{
		output_str << "\tPassed argument 's' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	plot_file = s;

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetPlotBins(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetPlotBins(std::string s):" << std::endl;

	try
	{
		plot_bins = std::stoi(s);
	}
	catch(const std::invalid_argument&)
	{
		output_str << "\tstd::stoi falled to cast argument \"" << s << "\" as int" << std::endl;
		return_val = 1;
		goto label;
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetBDTCut(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetBDTCut(std::string s):" << std::endl;

	try
	{
		bdt_cut = std::stof(s);
	}
	catch(const std::invalid_argument&)
	{
		output_str << "\tstd::stof falled to cast argument \"" << s << "\" as float" << std::endl;
		return_val = 1;
		goto label;
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetNumSigma(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNumSigma(std::string s):" << std::endl;

	try
	{
		num_sigma = std::stoi(s);
	}
	catch(const std::invalid_argument&)
	{
		output_str << "\tstd::stoi falled to cast argument \"" << s << "\" as int" << std::endl;
		return_val = 1;
		goto label;
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetNumGauss(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetNumGauss(std::string s):" << std::endl;

	try
	{
		num_gauss = std::stoi(s);
	}
	catch(const std::invalid_argument&)
	{
		output_str << "\tstd::stoi falled to cast argument \"" << s << "\" as int" << std::endl;
		return_val = 1;
		goto label;
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::SetDegCheby(std::string s)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::SetDegCheby(std::string s):" << std::endl;

	try
	{
		deg_cheby = std::stoi(s);
	}
	catch(const std::invalid_argument&)
	{
		output_str << "\tstd::stoi falled to cast argument \"" << s << "\" as int" << std::endl;
		return_val = 1;
		goto label;
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

//member access functions

int PNP_Ana::TouchOutput(std::string file_name, TFile*& file)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::TouchOutput(std::string file_name, TFile*& file):" << std::endl;
	file = nullptr;

	if(file_name == "")
	{
		output_str << "\tArgument 'file_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	file = nullptr;//= TFile::Open(file_name.c_str(), "UPDATE");
	if(!file)
	{
		output_str << "\tCould not get file:" << std::endl;
		output_str << "\t" << file_name << std::endl;
		output_str << "\tRecreating..." << std::endl;

		file = TFile::Open(file_name.c_str(), "RECREATE");
	}
	if(!file)
	{
		output_str << "\tFailed to recreate file:" << std::endl;
		output_str << "\t" << file_name << std::endl;
		return_val = 1;
		goto label;
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::TouchSource(std::string file_name, std::string tree_name, TFile*& file, TTree*& tree)
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::TouchSource(std::string file_name, std::string tree_name, TFile*& file, TTree*& tree):" << std::endl;
	file = nullptr;
	tree = nullptr;

	if(file_name == "")
	{
		output_str << "\tArgument 'file_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	file = TFile::Open(file_name.c_str(), "READ");
	if(!file)
	{
		output_str << "\tCould not get file:" << std::endl;
		output_str << "\t" << file_name << std::endl;
		return_val = 1;
		goto label;
	}

	if(tree_name == "")
	{
		output_str << "\tArgument 'tree_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	tree = (TTree*)file->Get(tree_name.c_str());
	if(!tree)
	{
		output_str << "\tCould not get tree:" << std::endl;
		output_str << "\t" << tree_name << std::endl;
		return_val = 1;
		goto label;
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	return return_val;
}

int PNP_Ana::DoMassFit()
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

	RooArgList sgmas;
	RooArgList coefs;
	RooArgList gsses;
	RooArgList cvars;

	RooAddPdf* sgnl = nullptr;

	RooDataSet* data_set = nullptr;
	RooDataSet* prompt_data_set = nullptr;
	RooDataSet* nprmpt_data_set = nullptr;
	RooFitResult* result = nullptr;

	RooPlot* plot = nullptr;
	TCanvas* cnvs = nullptr;

	std::ofstream mass_fit_file;

	return_val = TouchOutput(output_file_name, output_file);
	if(return_val)goto label;

	return_val = TouchSource(prompt_file_name, prompt_ntpl_name, prompt_file, prompt_tree);
	if(return_val)goto label;

	return_val = TouchSource(nprmpt_file_name, nprmpt_ntpl_name, nprmpt_file, nprmpt_tree);
	if(return_val)goto label;

	if(ntuple_mass_name == "")
	{
		output_str << "\tMember 'ntuple_mass_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}

	mu = 0.0;
	sigma = 0.0;

	n = prompt_tree->GetEntriesFast() + nprmpt_tree->GetEntriesFast();
	if(n == 0)
	{
		output_str << "\tNo entries found in either prompt or nprmpt tree" << std::endl;
		return_val = 1;
		goto label;
	}

	prompt_tree->SetBranchAddress(ntuple_mass_name.c_str(), &m);
	nprmpt_tree->SetBranchAddress(ntuple_mass_name.c_str(), &m);

	for(n = 0; n < prompt_tree->GetEntriesFast(); n++)
	{
		prompt_tree->GetEntry(n);
		mu += m;
	}
	for(n = 0; n < nprmpt_tree->GetEntriesFast(); n++)
	{
		nprmpt_tree->GetEntry(n);
		mu += m;
	}
	n = prompt_tree->GetEntriesFast() + nprmpt_tree->GetEntriesFast();
	mu /= n;

	for(n = 0; n < prompt_tree->GetEntriesFast(); n++)
	{
		prompt_tree->GetEntry(n);
		m -= mu;
		sigma += m * m;
	}
	for(n = 0; n < nprmpt_tree->GetEntriesFast(); n++)
	{
		nprmpt_tree->GetEntry(n);
		m -= mu;
		sigma += m * m;
	}
	sigma /= n;
	sigma = sqrt(sigma);

	if(num_sigma == -1)
	{
		output_str << "\tMember \"num_sigma\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(num_gauss == -1)
	{
		output_str << "\tMember \"num_gauss\" not set" << std::endl;
		return_val = 1;
		goto label;
	}

	if(!mass_min_set)
	{
		mass_min = mu - num_sigma * sigma;
		mass_min_set = true;
	}
	if(!mass_max_set)
	{
		mass_max_set = mu + num_sigma * sigma;
		mass_max_set = true;
	}
	mass = new RooRealVar(ntuple_mass_name.c_str(), ntuple_mass_name.c_str(), mass_min, mass_max);
	mean = new RooRealVar("mu", "mu", mu, mu - num_sigma * sigma, mu + num_sigma * sigma);
	for(i = 0; i < num_gauss; i++)
	{
		s = "s_";
		s += std::to_string(i);
		sgmas.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), sigma / (1 << i), 0.0, num_sigma * sigma)));

		s = "c_";
		s += std::to_string(i);
		coefs.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), n / num_gauss, 0.0, n)));

		s = "g_";
		s += std::to_string(i);
		gsses.addOwned(*(new RooGaussian(s.c_str(), s.c_str(), *mass, *mean, (RooRealVar&)(sgmas[sgmas.getSize() - 1]))));
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

	if(plot_name == "")
	{
		output_str << "\tMember \"plot_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(plot_file == "")
	{
		output_str << "\tMember \"plot_file\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(plot_bins == -1)
	{
		output_str << "\tMember \"plot_bins\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	cnvs = new TCanvas((plot_name + "_cnvs").c_str(), (plot_name + "_cnvs").c_str());
	cnvs->cd();
	plot = new RooPlot(plot_name.c_str(), plot_name.c_str(), *mass, mass_min, mass_max, plot_bins);
	sgnl->plotOn
	(
		plot,
		RooFit::LineColor(kRed),
		RooFit::LineStyle(1),
		RooFit::LineWidth(3),
		RooFit::Normalization(data_set->sumEntries())
	);
	data_set->plotOn
	(
		plot,
		RooFit::Binning(plot_bins, mass_min, mass_max),
		//RooFit::DataError(),	//default is fine
		RooFit::RefreshNorm(),
		RooFit::MarkerColor(kBlack),
		RooFit::MarkerStyle(8)
	);
	plot->Draw();
	cnvs->SaveAs(plot_file.c_str());

	if(mass_fit_file_name == "")
	{
		output_str << "\tMember \"mass_fit_file_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	mass_fit_file.open(mass_fit_file_name, std::ios_base::out | std::ios_base::trunc);
	if(mass_fit_file.is_open())
	{
		mass_fit_file << "mu:\t" << mean->getValV() << std::endl;
		for(i = 0; i < num_gauss; i++)
		{
			mass_fit_file << ((RooRealVar*)&(sgmas[i]))->GetName() << ":\t";
			mass_fit_file << ((RooRealVar*)&(sgmas[i]))->getValV() << "\t";
			mass_fit_file << ((RooRealVar*)&(coefs[i]))->GetName() << ":\t";
			mass_fit_file << ((RooRealVar*)&(coefs[i]))->getValV() << std::endl;
		}
	}
	mass_fit_file.close();

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
	if(data_set)delete data_set;
	if(prompt_data_set)delete prompt_data_set;
	if(nprmpt_data_set)delete nprmpt_data_set;
	if(plot)delete plot;
	if(cnvs)delete cnvs;

	return return_val;
}

int PNP_Ana::DoTraining()
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::DoTraining():" << std::endl;

	int i = 0;
	Long64_t n;
	float mu = 0.0;
	float var = 0.0;
	float norm = 0.0;
	float sigma = 0.0;
	float coef = 0.0;
	std::string s = "";

	TFile* output_file = nullptr;

	TFile* prompt_file = nullptr;
	TTree* prompt_tree = nullptr;
	TFile* nprmpt_file = nullptr;
	TTree* nprmpt_tree = nullptr;
	TFile* bkgrnd_file = nullptr;
	TTree* bkgrnd_tree = nullptr;

	TMVA::Factory *factory = nullptr;;
	TMVA::DataLoader *dataloader = nullptr;

	std::ifstream mass_fit_file;

	if(output_file_name == "")
	{
		output_str << "\tMember \"output_file_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	return_val = TouchOutput(output_file_name.c_str(), output_file);
	if(return_val)goto label;

	factory = new TMVA::Factory("factory", output_file, "!V:!Silent:AnalysisType=Classification");
	dataloader = new TMVA::DataLoader("dataloader");
	if(training_weight_file_dir == "")
	{
		output_str << "\tMember \"training_weight_file_dir\" not set" << std::endl;
		return_val = 1;
		goto label;
	}

	if(!std::filesystem::exists(training_weight_file_dir.c_str()))
	{
		if(!std::filesystem::create_directories(training_weight_file_dir.c_str()))
		{
			output_str << "\tFailed to find or create dir:" << std::endl;
			output_str << "\t" << training_weight_file_dir << std::endl;
			return_val = 1;
			goto label;
		}
	}
	(TMVA::gConfig().GetIONames()).fWeightFileDirPrefix = training_weight_file_dir.c_str();
	//(TMVA::gConfig().GetIONames()).fWeightFileExtension = "root"; //changes the middle part, not the extension

	if(mass_fit_file_name == "")
	{
		output_str << "\tMember \"mass_fit_file_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	mass_fit_file.open(mass_fit_file_name, std::ios_base::in);
	if(!mass_fit_file.is_open())
	{
		output_str << "\tCouldn't open file" << std::endl;
		output_str << "\t" << mass_fit_file_name << std::endl;
		return_val = 1;
		goto label;
	}
	std::getline(mass_fit_file, s);
	sscanf(s.c_str(), "%*s %f", &mu);
	for(s; std::getline(mass_fit_file, s);)
	{
		sscanf(s.c_str(), "%*s %f %*s %f", &sigma, &coef);

		norm += coef;
		var += coef * sigma * sigma;
	}
	mass_fit_file.close();
	var /= norm;
	sigma = sqrt(var);

	std::cout << mu << "\t" << sigma << std::endl;

	return_val = TouchSource(prompt_file_name, prompt_ntpl_name, prompt_file, prompt_tree);
	if(return_val)goto label;

	return_val = TouchSource(nprmpt_file_name, nprmpt_ntpl_name, nprmpt_file, nprmpt_tree);
	if(return_val)goto label;

	return_val = TouchSource(bkgrnd_file_name, bkgrnd_ntpl_name, bkgrnd_file, bkgrnd_tree);
	if(return_val)goto label;

	for(i = 0; i < training_vars.size(); ++i)
	{
		dataloader->AddVariable(training_vars[i].c_str(), 'F');
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

	if(s != "")
	{
		dataloader->AddCut(TCut(s.c_str(), s.c_str()), "Signal");
		dataloader->AddCut(TCut(s.c_str(), s.c_str()), "Background");
	}

	s = "";
	s += "((" + std::to_string(mu - 2.0 * num_sigma * sigma) + "<" + ntuple_mass_name + ")";
	s += "&&";
	s += "(" + ntuple_mass_name + "<" + std::to_string(mu - num_sigma * sigma) + "))";
	s += "||";
	s += "((" + std::to_string(mu + num_sigma * sigma) + "<" + ntuple_mass_name + ")";
	s += "&&";
	s += "(" + ntuple_mass_name + "<" + std::to_string(mu + 2.0 * num_sigma * sigma) + "))";

	dataloader->AddCut(TCut(s.c_str(), s.c_str()), "Background");

	dataloader->AddSignalTree(prompt_tree);
	dataloader->AddSignalTree(nprmpt_tree);

	dataloader->AddBackgroundTree(bkgrnd_tree);

	factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT", "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20");

	factory->TrainAllMethods();
	factory->TestAllMethods();
	factory->EvaluateAllMethods();

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	if(output_file)
	{
		output_file->Write();
		output_file->Close();
	}

	return return_val;
}

int PNP_Ana::DoBackgroundCopy()
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::DoBackgroundCopy():" << std::endl;

	bool b;
	int i = 0;
	Long64_t n = 0;
	std::string s = "";

	TFile* output_file = nullptr;
	TTree* output_tree = nullptr;

	TFile* bkgrnd_file = nullptr;
	TTree* bkgrnd_tree = nullptr;

	TMVA::Reader* reader = nullptr;

	float mass = 0.0;
	float bdtv = 0.0;

	float cvars[cut_vars.size()];
	float tvars[training_vars.size()];

	RooArgList cargs;
	RooArgList cexprs;

	return_val = TouchOutput(output_file_name, output_file);
	if(return_val)goto label;

	return_val = TouchSource(bkgrnd_file_name, bkgrnd_ntpl_name, bkgrnd_file, bkgrnd_tree);
	if(return_val)goto label;

	output_tree = new TTree((bkgrnd_ntpl_name + "_bdtv").c_str(), (bkgrnd_ntpl_name + "_bdtv").c_str());
	output_tree->SetDirectory(output_file);

	reader = new TMVA::Reader("!Color:!Silent");

	if(ntuple_mass_name == "")
	{
		output_str << "\tMember \"ntuple_mass_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(ntuple_bdtv_name == "")
	{
		output_str << "\tMember \"ntuple_bdtv_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(!(bkgrnd_tree->GetBranch(ntuple_mass_name.c_str())))
	{
		output_str << "\tFailed to get branch \"" << ntuple_mass_name << "\"" << std::endl;
		output_str << "\tFrom tree \"" << bkgrnd_ntpl_name << "\"" << std::endl;
		output_str << "\tFrom file \"" << bkgrnd_file_name << "\"" << std::endl;
		return_val = 1;
		goto label;
	}
	output_tree->Branch(ntuple_mass_name.c_str(), &mass);
	bkgrnd_tree->SetBranchAddress(ntuple_mass_name.c_str(), &mass);

	for(i = 0; i < cut_vars.size(); i++)
	{
		if(!(bkgrnd_tree->GetBranch(cut_vars[i].c_str())))
		{
			output_str << "\tFailed to get branch \"" << cut_vars[i] << "\"" << std::endl;
			output_str << "\tFrom tree \"" << bkgrnd_ntpl_name << "\"" << std::endl;
			output_str << "\tFrom file \"" << bkgrnd_file_name << "\"" << std::endl;
			return_val = 1;
			goto label;
		}

		bkgrnd_tree->SetBranchAddress(cut_vars[i].c_str(), &(cvars[i]));
		output_tree->Branch(cut_vars[i].c_str(), &(cvars[i]));

		std::cout << &(cvars[i]) << std::endl;

		cargs.addOwned(*(new RooRealVar(cut_vars[i].c_str(), cut_vars[i].c_str(), -FLT_MAX, FLT_MAX)));
	}


	output_tree->Branch(ntuple_bdtv_name.c_str(), &bdtv);

	for(i = 0; i < training_vars.size(); i++)
	{
		if(!(bkgrnd_tree->GetBranch(training_vars[i].c_str())))
		{
			output_str << "\tFailed to get branch \"" << training_vars[i] << "\"" << std::endl;
			output_str << "\tFrom tree \"" << bkgrnd_ntpl_name << "\"" << std::endl;
			output_str << "\tFrom file \"" << bkgrnd_file_name << "\"" << std::endl;
			return_val = 1;
			goto label;
		}

		bkgrnd_tree->SetBranchAddress(training_vars[i].c_str(), &(tvars[i]));
		output_tree->Branch(training_vars[i].c_str(), &(tvars[i]));

		reader->AddVariable(training_vars[i].c_str(), &(tvars[i]));
	}

	if(training_weight_file_dir == "")
	{
		output_str << "\tMember \"training_weight_file_dir\" not set" << std::endl;
		return_val = 1;
		goto label;
	}

	s = training_weight_file_dir + "dataloader/weights/factory_BDT.weights.xml";
	if(!std::filesystem::exists(s.c_str()))
	{
		output_str << "\tCould not load weights file:" << std::endl;
		output_str << "\t" << s << std::endl;
		return_val = 1;
		goto label;
	}

	reader->BookMVA("BDT", s.c_str());

	for(i = 0; i < cut_exprs.size(); i++)
	{
		s = "c_";
		s += std::to_string(i);
		cexprs.addOwned(*(new RooFormulaVar(s.c_str(), s.c_str(), cut_exprs[i].c_str(), cargs)));
	}

	bkgrnd_tree->Print();

	for(n = 0; n < bkgrnd_tree->GetEntriesFast(); n++)
	{
		bkgrnd_tree->GetEntry(n);

		for(i = 0; i < cut_vars.size(); i++)
		{
			((RooRealVar*)&(cargs[i]))->setVal(cvars[i]);
			if(n < 50)
			{
				std::cout << ((RooRealVar*)&(cargs[i]))->GetName() << ":\t" << ((RooRealVar*)&(cargs[i]))->getVal() << "\t" << cvars[i] << std::endl;
			}
		}
		if(n < 50)std::cout << std::endl;

		b = false;

		for(i = 0; i < cut_exprs.size(); i++)
		{
			if(((RooFormulaVar*)&(cexprs[i]))->evaluate() == 0.0)
			{
				b = true;
			}

		}

		if(b)continue;

		bdtv = reader->EvaluateMVA("BDT");
		output_tree->Fill();
	}

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	if(output_file)
	{
		output_file->Write();
		output_file->Close();
	}
	if(reader)delete reader;

	return return_val;
}

int PNP_Ana::DoBackgroundFit()
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Ana::DoBackgroundFit():" << std::endl;

	int i = 0;
	Long64_t n;
	float a = 0.0;
	float b = 0.0;
	std::string s = "";

	TFile* output_file = nullptr;
	TFile* bkgrnd_file = nullptr;
	TTree* bkgrnd_tree = nullptr;

	RooRealVar* mass = nullptr;
	RooRealVar* bdtv = nullptr;
	RooRealVar* mean = nullptr;
	RooRealVar* wdth = nullptr;
	RooRealVar* sgnl_count = nullptr;
	RooRealVar* bkgd_count = nullptr;

	RooArgList sgmas;
	RooArgList wdths;
	RooArgList coefs;
	RooArgList gsses;
	RooArgList cvars;
	RooArgList cheby;
	RooArgList count;
	RooArgList sgnl_bkgd;

	RooAddPdf* sgnl = nullptr;
	RooChebychev* bkgd = nullptr;
	RooAddPdf* model = nullptr;

	RooDataSet* data_set = nullptr;
	RooFitResult* result = nullptr;

	TCanvas* cnvs = nullptr;
	RooPlot* plot = nullptr;

	std::ifstream mass_fit_file;
	std::ofstream bkgd_fit_file;

	return_val = TouchOutput(output_file_name, output_file);
	if(return_val)goto label;

	return_val = TouchSource(bkgrnd_file_name, bkgrnd_ntpl_name, bkgrnd_file, bkgrnd_tree);
	if(return_val)goto label;

	if(ntuple_mass_name == "")
	{
		output_str << "\tMember 'ntuple_mass_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	if(ntuple_bdtv_name == "")
	{
		output_str << "\tMember 'ntuple_bdtv_name' is empty string" << std::endl;
		return_val = 1;
		goto label;
	}
	if(!mass_min_set)
	{
		output_str << "\tMember \"mass_min\" not set" << std::endl;
		output_str << "\tCall \"PNP_Ana::SetMassMin(std::string)\"" << std::endl;
		return_val = 1;
		goto label;
	}
	if(!mass_max_set)
	{
		output_str << "\tMember \"mass_max\" not set" << std::endl;
		output_str << "\tCall \"PNP_Ana::SetMassMax(std::string)\"" << std::endl;
		return_val = 1;
		goto label;
	}

	n = bkgrnd_tree->GetEntriesFast();
	if(n == 0)
	{
		output_str << "\tNo entries found in bkgrnd tree" << std::endl;
		return_val = 1;
		goto label;
	}

	if(num_sigma == -1)
	{
		output_str << "\tMember \"num_sigma\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(num_gauss == -1)
	{
		output_str << "\tMember \"num_gauss\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(deg_cheby == -1)
	{
		output_str << "\tMember \"deg_cheby\" not set" << std::endl;
		return_val = 1;
		goto label;
	}

	if(mass_fit_file_name == "")
	{
		output_str << "\tMember \"mass_fit_file_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	mass_fit_file.open(mass_fit_file_name, std::ios_base::in);
	if(!mass_fit_file.is_open())
	{
		output_str << "\tCouldn't open file" << std::endl;
		output_str << "\t" << mass_fit_file_name << std::endl;
		return_val = 1;
		goto label;
	}
	std::getline(mass_fit_file, s);
	sscanf(s.c_str(), "%*s %f", &a);
	mass = new RooRealVar(ntuple_mass_name.c_str(), ntuple_mass_name.c_str(), mass_min, mass_max);
	bdtv = new RooRealVar(ntuple_bdtv_name.c_str(), ntuple_bdtv_name.c_str(), -FLT_MAX, FLT_MAX);
	wdth = new RooRealVar("w", "w", 1.0, 1.0 / num_sigma, num_sigma);
	mean = new RooRealVar("mu", "mu", a, a, a);
	i = 0;
	for(s; std::getline(mass_fit_file, s);)
	{
		sscanf(s.c_str(), "%*s %f %*s %f", &a, &b);

		s = "s_";
		s += std::to_string(i);
		sgmas.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), a, a, a)));

		s = "w_";
		s += std::to_string(i);
		wdths.addOwned(*(new RooFormulaVar(s.c_str(), s.c_str(), ("s_" + std::to_string(i) + "*w").c_str(), RooArgList(*wdth, sgmas[sgmas.getSize() - 1]))));

		s = "c_";
		s += std::to_string(i);
		coefs.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), b, b, b)));

		s = "g_";
		s += std::to_string(i);
		gsses.addOwned(*(new RooGaussian(s.c_str(), s.c_str(), *mass, *mean, (RooFormulaVar&)(wdths[wdths.getSize() - 1]))));

		++i;
	}
	mass_fit_file.close();

	s = "sgnl";
	sgnl = new RooAddPdf(s.c_str(), s.c_str(), gsses, coefs);
	sgnl_bkgd.addOwned(*sgnl);

	for(i = 1; i < deg_cheby; ++i)
	{
		s = "d_";
		s += std::to_string(i);
		cheby.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), 0.0, 0.0, 0.0)));
	}
	s = "bkgd";
	bkgd = new RooChebychev(s.c_str(), s.c_str(), *mass, cheby);
	sgnl_bkgd.addOwned(*bkgd);

	sgnl_count = new RooRealVar("sgnl_count", "sgnl_count", 0.0, 0.0, n);
	bkgd_count = new RooRealVar("bkgd_count", "bkgd_count", n, 0.0, n);
	count.addOwned(*sgnl_count);
	count.addOwned(*bkgd_count);

	model = new RooAddPdf("model", "model", sgnl_bkgd, count);

	cvars.addOwned(*mass);
	cvars.addOwned(*bdtv);
	for(i = 0; i < cut_vars.size(); i++)
	{
		cvars.addOwned(*(new RooRealVar(cut_vars[i].c_str(), cut_vars[i].c_str(), 0.0, -FLT_MAX, FLT_MAX)));
	}

	s = "";
	s += "(";
	s += ntuple_bdtv_name;
	s += ">";
	s += std::to_string(bdt_cut);
	s += ")";
	i = 0;
	while(cut_exprs.size() > 0)
	{
		s += "&&";
		s += "(";
		s += cut_exprs[i];
		s += ")";

		++i;
		if(i >= cut_exprs.size())break;
	}

	data_set = new RooDataSet("data_set", "data_set", cvars, RooFit::Import(*bkgrnd_tree), RooFit::Cut(s.c_str()));

	for(i = 0; i < deg_cheby; ++i)
	{
		if(i > 0)((RooRealVar*)&(cheby[i-1]))->setRange(-FLT_MAX, FLT_MAX);

		result = model->fitTo(*data_set);
	}

	if(bkgd_fit_file_name == "")
	{
		output_str << "\tMember \"bkgd_fit_file_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	bkgd_fit_file.open(bkgd_fit_file_name, std::ios_base::out | std::ios_base::app);
	if(!bkgd_fit_file.is_open())
	{
		output_str << "\tCouldn't open file" << std::endl;
		output_str << "\t" << bkgd_fit_file_name << std::endl;
		return_val = 1;
		goto label;
	}
	bkgd_fit_file << "bdt_cut:\t" << bdt_cut << "\t";
	bkgd_fit_file << "sgnl_counts:\t" << sgnl_count->getValV() << "\t";
	bkgd_fit_file << "efficiency:\t" << sgnl_count->getValV() / sqrt(sgnl_count->getValV() + bkgd_count->getValV()) << std::endl;

	if(plot_name == "")
	{
		output_str << "\tMember \"plot_name\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(plot_file == "")
	{
		output_str << "\tMember \"plot_file\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	if(plot_bins == -1)
	{
		output_str << "\tMember \"plot_bins\" not set" << std::endl;
		return_val = 1;
		goto label;
	}
	cnvs = new TCanvas((plot_name + "_cnvs").c_str(), (plot_name + "_cnvs").c_str());
	cnvs->cd();
	plot = new RooPlot(plot_name.c_str(), plot_name.c_str(), *mass, mass_min, mass_max, plot_bins);
	model->plotOn
	(
		plot,
		RooFit::LineColor(kRed),
		RooFit::LineStyle(1),
		RooFit::LineWidth(3),
		RooFit::Normalization(data_set->sumEntries())
	);
	model->plotOn
	(
		plot,
		RooFit::Components(*bkgd),
		RooFit::LineColor(kBlue),
		RooFit::LineStyle(1),
		RooFit::LineWidth(3),
		RooFit::Normalization(data_set->sumEntries())
	);
	data_set->plotOn
	(
		plot,
		RooFit::Binning(plot_bins, mass_min, mass_max),
		//RooFit::DataError(),	//default is fine
		RooFit::RefreshNorm(),
		RooFit::MarkerColor(kBlack),
		RooFit::MarkerStyle(8)
	);
	plot->Draw();
	cnvs->SaveAs(plot_file.c_str());

	label:
	output_str << std::ends;
	if(return_val)std::cout << output_str.str();
	if(output_file)
	{
		output_file->cd();
		output_file->Close();
	}
	if(plot)delete plot;
	if(cnvs)delete cnvs;

	return return_val;
}
