#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "PNP_Ana.h"

class PNP_Config
{
protected:
	int static const args = 4;
	int static const bdt_num_cuts = 40;

	std::string static const scratch_dir;
	std::string static const prompt_file_name;
	std::string static const nprmpt_file_name;
	std::string static const bkgrnd_file_name;
	std::string static const prompt_ntpl_name;
	std::string static const nprmpt_ntpl_name;
	std::string static const bkgrnd_ntpl_name;

	std::string static const ntuple_mass_name;
	std::string static const ntuple_mass_min;
	std::string static const ntuple_mass_max;

	std::string static const traind_ntpl_name;
	std::string static const ntuple_bdt_inc_name;
	std::string static const ntuple_bdt_exc_name;
	std::string static const training_dir;
	std::string static const training_inc_subdir;
	std::string static const training_exc_subdir;

	std::string static const num_sigma;
	std::string static const num_gauss;
	std::string static const deg_cheby;

	std::string static const pT;
	std::string static const cent;

	std::vector<std::string> static const training_vars;
	std::vector<std::string> static const pT_cuts;
	std::vector<std::string> static const cent_cuts;

public:
	static PNP_Ana* Config(int argc, char* argv[]);
};
