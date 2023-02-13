#include "PNP_Ana.h"
#include "PNP_Config.h"

int const PNP_Config::bdt_num_cuts =				40;

std::string const PNP_Config::root_dir =			"/scratch/brown/jbertau/BD0_Ana_Fall_2022/";

std::string const PNP_Config::mc_mass_fit_root_subdir =		"mc_mass_fits/idk/fit_ntpl";
std::string const PNP_Config::mc_mass_fit_text_subdir =		"mc_mass_fits/txt/fit_prms";
std::string const PNP_Config::mc_mass_fit_plot_subdir =		"mc_mass_fits/plt/fit_plot";
std::string const PNP_Config::mc_mass_fit_base_name =		"mc_mass_fit";

std::string const PNP_Config::training_dir =			"/home/jbertau/Data/Repositories/PNP_Ana/sub/";

std::string const PNP_Config::data_mass_fit_root_subdir =	"data_mass_fits/idk/fit_ntpl";
std::string const PNP_Config::data_mass_fit_text_subdir =	"data_mass_fits/txt/fit_prms";
std::string const PNP_Config::data_mass_fit_plot_subdir =	"data_mass_fits/plt/fit_plot";
std::string const PNP_Config::data_mass_fit_base_name =		"data_mass_fit";

std::string const PNP_Config::efficiency_text_subdir =		"efficiency/txt/optimal_val";
std::string const PNP_Config::efficiency_plot_subdir =		"efficiency/plt/efficieny_curve";

int const PNP_Config::plot_bins =				50;

std::string const PNP_Config::prompt_file_name =		"prompt/target/target0_1.root";
std::string const PNP_Config::nprmpt_file_name =		"nprmpt/target/target0_1.root";
std::string const PNP_Config::bkgrnd_file_name =		"bkgrnd/target/target0_2.root";

std::string const PNP_Config::prompt_ntpl_name =		"prompt_ntpl";
std::string const PNP_Config::nprmpt_ntpl_name =		"nprmpt_ntpl";
std::string const PNP_Config::bkgrnd_ntpl_name =		"bkgrnd_ntpl";

std::string const PNP_Config::ntuple_mass_name =		"mass";
float const PNP_Config::mass_min =				1.75;
float const PNP_Config::mass_max =				1.95;

std::string const PNP_Config::inc_training_subdir =		"inc_training/metadata";
std::string const PNP_Config::exc_training_subdir =		"exc_training/metadata";
std::string const PNP_Config::traind_ntpl_subdir =		"traind/bdt_ntpl";
std::string const PNP_Config::traind_ntpl_name =		"traind_ntpl";
std::string const PNP_Config::bdt_inc_name =			"bdt_inc";
std::string const PNP_Config::bdt_exc_name =			"bdt_exc";

int const PNP_Config::num_sigma =				3;
int const PNP_Config::num_gauss = 				3;
int const PNP_Config::deg_cheby = 				3;

std::string const PNP_Config::pT =				"pT";
std::string const PNP_Config::cent =				"cent";
std::string const PNP_Config::bdt =				"bdt";

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

PNP_Ana* PNP_Config::Config(int args, int argc, char* argv[])
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Config::Config(int argc, char* argv[]):" << std::endl;

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

	s = pTcentSuffix(args, argc, argv);
	if(!s.empty())
	{
		pnp_ana->mc_mass_fit_root_file_name = root_dir + mc_mass_fit_root_subdir + s + ".root";
		pnp_ana->mc_mass_fit_text_file_name = root_dir + mc_mass_fit_text_subdir + s + ".txt";
		pnp_ana->mc_mass_fit_plot_file_name = root_dir + mc_mass_fit_plot_subdir + s + ".png";
		pnp_ana->mc_mass_fit_base_name = mc_mass_fit_base_name + s;
	}

	pnp_ana->training_dir = training_dir;

	pnp_ana->inc_factory_name = "factory_inc" + s;
	pnp_ana->exc_factory_name = "factory_exc" + s;

	pnp_ana->inc_training_weights = "dataloader/weights/" + pnp_ana->inc_factory_name + "_BDT.weights.xml";
	pnp_ana->exc_training_weights = "dataloader/weights/" + pnp_ana->exc_factory_name + "_BDT.weights.xml";

	s = bdtSuffix(args, argc, argv);
	if(!s.empty())
	{
		pnp_ana->data_mass_fit_root_file_name = root_dir + data_mass_fit_root_subdir + s + ".root";
		pnp_ana->data_mass_fit_text_file_name = root_dir + data_mass_fit_text_subdir + s + ".txt";
		pnp_ana->data_mass_fit_plot_file_name = root_dir + data_mass_fit_plot_subdir + s + ".png";
		pnp_ana->data_mass_fit_base_name = data_mass_fit_base_name + s;
	}
	else
	{
		s = pTcentSuffix(args, argc, argv);
		if(!s.empty())
		{
			pnp_ana->data_mass_fit_text_file_name = root_dir + data_mass_fit_text_subdir + s + "_*.txt";
		}
	}

	s = pTcentSuffix(args, argc, argv);
	pnp_ana->efficiency_plot_file_name = root_dir + efficiency_plot_subdir + s + ".png";
	pnp_ana->efficiency_text_file_name = root_dir + efficiency_text_subdir + s + ".txt";

	pnp_ana->plot_bins = plot_bins;

	pnp_ana->prompt_file_name = root_dir + prompt_file_name;
	pnp_ana->nprmpt_file_name = root_dir + nprmpt_file_name;
	pnp_ana->bkgrnd_file_name = root_dir + bkgrnd_file_name;

	pnp_ana->prompt_ntpl_name = prompt_ntpl_name;
	pnp_ana->nprmpt_ntpl_name = nprmpt_ntpl_name;
	pnp_ana->bkgrnd_ntpl_name = bkgrnd_ntpl_name;

	pnp_ana->ntuple_mass_name = ntuple_mass_name;
	pnp_ana->mass_min = mass_min;
	pnp_ana->mass_max = mass_max;

	s = pTcentSuffix(args, argc, argv);
	if(!s.empty())
	{
		pnp_ana->inc_training_file_name = root_dir + inc_training_subdir + s + ".root";
		pnp_ana->exc_training_file_name = root_dir + exc_training_subdir + s + ".root";
		pnp_ana->traind_file_name = root_dir + traind_ntpl_subdir + s + ".root";
	}
	pnp_ana->traind_ntpl_name = traind_ntpl_name;
	pnp_ana->bdt_inc_name = bdt_inc_name;
	pnp_ana->bdt_exc_name = bdt_exc_name;
	pnp_ana->bdt_cut = (arg[2] - bdt_num_cuts / 2.0) / bdt_num_cuts;

	pnp_ana->num_sigma = num_sigma;
	pnp_ana->num_gauss = num_gauss;
	pnp_ana->deg_cheby = deg_cheby;

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

std::string PNP_Config::pTcentSuffix(int args, int argc, char* argv[])
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Config::pTcentSuffix(int argc, char* argv[]):" << std::endl;

	int i = 0;
	int arg[2] = {0, 0};
	std::string s = "";

	for(i = 0; i < 2; ++i)
	{
		if(argc <= args + i)
		{
			output_str << "\tinsufficient arguments" << std::endl;
			output_str << "\texpected at least " << args + i + 1 << " arguments" << std::endl;
			return_val = 1;
			goto label;
		}

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
	s = "_"+pT+std::to_string(arg[0])+"_"+cent+std::to_string(arg[1]);

	label:
	output_str << std::endl << std::ends;
	if(return_val)
	{
		std::cout << output_str.str();
		s = "";
	}
	return s;
}

std::string PNP_Config::bdtSuffix(int args, int argc, char* argv[])
{
	int return_val = 0;
	std::stringstream output_str;
	output_str << "PNP_Config::bdtSuffix(int argc, char* argv[]):" << std::endl;

	int i = 0;
	int arg[3] = {0, 0, bdt_num_cuts / 2};
	std::string s = "";

	for(i = 0; i < 3; ++i)
	{
		if(argc <= args + i)
		{
			output_str << "\tinsufficient arguments" << std::endl;
			output_str << "\texpected at least " << args + i + 1 << " arguments" << std::endl;
			return_val = 1;
			goto label;
		}

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
	s = "_"+bdt+std::to_string(arg[2]);
	s = "_"+pT+std::to_string(arg[0])+"_"+cent+std::to_string(arg[1])+"_"+bdt+std::to_string(arg[2]);

	label:
	output_str << std::endl << std::ends;
	if(return_val)
	{
		std::cout << output_str.str();
		s = "";
	}
	return s;
}
