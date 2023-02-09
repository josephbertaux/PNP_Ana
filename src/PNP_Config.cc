#include "PNP_Config.h"

std::string const PNP_Config::scratch_dir =		"/scratch/brown/jbertau/BD0_Ana_Fall_2022/";
std::string const PNP_Config::prompt_file_name =	"prompt/target/target0_1.root";
std::string const PNP_Config::nprmpt_file_name =	"nprmpt/target/target0_1.root";
std::string const PNP_Config::bkgrnd_file_name =	"bkgrnd/target/target0_2.root";
std::string const PNP_Config::prompt_ntpl_name =	"prompt_ntpl";
std::string const PNP_Config::nprmpt_ntpl_name =	"nprmpt_ntpl";
std::string const PNP_Config::bkgrnd_ntpl_name =	"bkgrnd_ntpl";

std::string const PNP_Config::ntuple_mass_name =	"mass";
std::string const PNP_Config::ntuple_mass_min =		"1.75";
std::string const PNP_Config::ntuple_mass_max =		"1.95";

std::string const PNP_Config::traind_ntpl_name =	"traind_ntpl";
std::string const PNP_Config::ntuple_bdt_inc_name =	"bdt_inc";
std::string const PNP_Config::ntuple_bdt_exc_name =	"bdt_exc";
std::string const PNP_Config::training_dir =		"dataset/weights/";
std::string const PNP_Config::training_inc_subdir =	"inc/";
std::string const PNP_Config::training_exc_subdir =	"exc/";

std::string const PNP_Config::num_sigma = "3";
std::string const PNP_Config::num_gauss = "3";
std::string const PNP_Config::deg_cheby = "3";

std::string const PNP_Config::pT = "pT";
std::string const PNP_Config::cent = "cent";

std::vector<std::string> const PNP_Config::training_vars =
{
	"y",
	"vert_prob",
	"log_DLS",
	"log_DL",
	"pointing_angle",
	"trk_1_pt",
	"trk_2_pt",
	"xy_dca_sig_1",
	"xy_dca_sig_2",
	"z_dca_sig_1",
	"z_dca_sig_2"
};

std::vector<std::string> const PNP_Config::pT_cuts =
{
	"(6.0<="+PNP_Config::pT+")&&("+PNP_Config::pT+"<40.0)",
	"(6.0<="+PNP_Config::pT+")&&("+PNP_Config::pT+"<8.0)",
	"(8.0<="+PNP_Config::pT+")&&("+PNP_Config::pT+"<10.0)",
	"(10.0<="+PNP_Config::pT+")&&("+PNP_Config::pT+"<12.5)",
	"(12.5<="+PNP_Config::pT+")&&("+PNP_Config::pT+"<15.0)",
	"(15.0<="+PNP_Config::pT+")&&("+PNP_Config::pT+"<20.0)",
	"(20.0<="+PNP_Config::pT+")&&("+PNP_Config::pT+"<30.0)",
	"(30.0<="+PNP_Config::pT+")&&("+PNP_Config::pT+"<40.0)"
};

std::vector<std::string> const PNP_Config::cent_cuts =
{
	"(0.0<="+PNP_Config::cent+")&&("+PNP_Config::cent+"<90.0)",
	"(0.0<="+PNP_Config::cent+")&&("+PNP_Config::cent+"<10.0)",
	"(10.0<="+PNP_Config::cent+")&&("+PNP_Config::cent+"<30.0)",
	"(30.0<="+PNP_Config::cent+")&&("+PNP_Config::cent+"<50.0)",
	"(50.0<="+PNP_Config::cent+")&&("+PNP_Config::cent+"<90.0)",
};

PNP_Ana* PNP_Config::Config(int argc, char* argv[])
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Config::config(int argc, char* argv[]):" << std::endl;

	PNP_Ana* pnp_ana = nullptr;
	int i = 0;
	int arg[3] = {0, 0, bdt_num_cuts / 2};
	std::string s = "";

	for(i = 0; i < 3; ++i)
	{
		if(argc > args + i)
		{
			try
			{
				arg[i] = std::stoi(argv[args + i]);
			}
			catch(const std::invalid_argument&)
			{
				output_str << "\tstd::stoi failed to deduce argv[" << std::to_string(args + i) << "]" << std::endl;
				output_str << "\t(value \"" << argv[args + i] << "\")" << std::endl;
				output_str << "\tas int" << std::endl;
				return_val = 1;
				goto label;
			}
		}
	}

	pnp_ana = new PNP_Ana();

	if(pnp_ana->SetPromptFileName(scratch_dir + prompt_file_name))	{return_val = 1; goto label;}
	if(pnp_ana->SetNprmptFileName(scratch_dir + nprmpt_file_name))	{return_val = 1; goto label;}
	if(pnp_ana->SetBkgrndFileName(scratch_dir + bkgrnd_file_name))	{return_val = 1; goto label;}

	if(pnp_ana->SetPromptNtplName(prompt_ntpl_name))		{return_val = 1; goto label;}
	if(pnp_ana->SetNprmptNtplName(nprmpt_ntpl_name))		{return_val = 1; goto label;}
	if(pnp_ana->SetBkgrndNtplName(bkgrnd_ntpl_name))		{return_val = 1; goto label;}

	if(pnp_ana->SetNtupleMassName(ntuple_mass_name))		{return_val = 1; goto label;}
	if(pnp_ana->SetNtupleMassMin(ntuple_mass_min))			{return_val = 1; goto label;}
	if(pnp_ana->SetNtupleMassMax(ntuple_mass_max))			{return_val = 1; goto label;}

	if(pnp_ana->SetTrainingDir(training_dir))			{return_val = 1; goto label;}
	if(pnp_ana->SetTrainingIncSubdir(training_inc_subdir))		{return_val = 1; goto label;}
	if(pnp_ana->SetTrainingExcSubdir(training_exc_subdir))		{return_val = 1; goto label;}

	if(pnp_ana->SetNtupleBDTIncName(ntuple_bdt_inc_name))		{return_val = 1; goto label;}
	if(pnp_ana->SetNtupleBDTExcName(ntuple_bdt_exc_name))		{return_val = 1; goto label;}

	if(pnp_ana->AddCutVar(pT))					{return_val = 1; goto label;}
	if(pnp_ana->AddCutVar(cent))					{return_val = 1; goto label;}
	if(pnp_ana->AddCutExpr(pT_cuts[arg[0]]))			{return_val = 1; goto label;}
	if(pnp_ana->AddCutExpr(cent_cuts[arg[1]]))			{return_val = 1; goto label;}

	for(i = 0; i < training_vars.size(); ++i)
	{
		if(pnp_ana->AddTrainingVar(training_vars[i]))		{return_val = 1; goto label;}
	}
	//...

	label:
	output_str << std::endl << std::ends;
	if(return_val)
	{
		std::cout << output_str.str();
		if(pnp_ana)delete pnp_ana;
		pnp_ana = nullptr;
	}
	return pnp_ana;
}
