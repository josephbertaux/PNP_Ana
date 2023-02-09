#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class PNP_Ana;

class PNP_Config
{
protected:
	int static const bdt_num_cuts;

	std::string static const root_dir;			//path to the root directory for all .root files

	std::string static const mc_mass_fit_root_subdir;	//path to mc mass fit .root files, including the first part of the filename, relative to root_dir
	std::string static const mc_mass_fit_text_subdir;	//path to mc mass fit .txt files, including the first part of the filename, relative to root_dir
	std::string static const mc_mass_fit_plot_subdir;	//path to mc mass fit .png files, including the first part of the filename, relative to root_dir
	std::string static const mc_mass_fit_base_name;		//the base name of the plot and filtered ntuple

	std::string static const training_dir;			//path to training metadata relative to the directory where jobs are submitted
	std::string static const training_inc_subdir;		//ROOT is going to give us more control over training metadata soon
	std::string static const training_exc_subdir;		//however these will showup where they will and we just have to cope

	std::string static const data_mass_fit_root_subdir;	//directory for data mass fit by bdt value .root files, relative to root_dir
	std::string static const data_mass_fit_text_subdir;	//directory for data mass fit by bdt value .txt files, relative to root_dir
	std::string static const data_mass_fit_plot_subdir;	//directory for data mass fit by bdt value .png files, relative to root_dir
	std::string static const data_mass_fit_base_name;	//the base name of the plot and filtered ntuple

	int const static plot_bins;

	std::string static const prompt_file_name;		//path to the prompt mc file relative to root_dir
	std::string static const nprmpt_file_name;		//path to the nonprompt mc file relative to root_dir
	std::string static const bkgrnd_file_name;		//path to the background data file relative to root_dir

	std::string static const prompt_ntpl_name;		//name of the prompt ntuple in the prompt mc file
	std::string static const nprmpt_ntpl_name;		//name of the nonprompt ntuple in the nonprompt mc file
	std::string static const bkgrnd_ntpl_name;		//name of the background ntuple in the background data file

	std::string static const ntuple_mass_name;		//name of the mass branch in all ntuples
	float static const mass_min;
	float static const mass_max;

	std::string static const traind_ntpl_subdir;		//path to root files containing copied data with branches that show the BDT values
	std::string static const traind_ntpl_name;		//name for filtered ntuples on data which include the BDT values 
	std::string static const bdt_inc_name;			//branch for the bdt values of inclusive training
	std::string static const bdt_exc_name;			//branch for the bdt values of exclusive training (signal is nonprompt)

	int static const num_sigma;				//data between num_sigma and 2*num_sigma standard deviations away from the mean is used for sideband
	int static const num_gauss;				//number of Gaussians to use for mass fits
	int static const deg_cheby;				//degree of the Chebychev polynomial to use for background in data mass fits

	std::string static const pT;
	std::string static const cent;
	std::string static const bdt;

	std::vector<std::string> static const training_vars;
	std::vector<std::string> static const pT_cuts;
	std::vector<std::string> static const cent_cuts;

public:
	static PNP_Ana* Config(int args, int argc, char* argv[]);

	static std::string pTcentSuffix(int args, int argc, char* argv[]);
	static std::string bdtSuffix(int args, int argc, char* argv[]);
};
