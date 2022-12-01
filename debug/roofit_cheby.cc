void roofit_cheby()
{
	int deg_cheby = 3;
	std::string ntuple_mass_name = "mass";
	float mass_min = 2.0;
	float mass_max = 2.6;
	
	int i = 0;
	std::string s = "";

        RooRealVar* mass = nullptr;
        RooRealVar* mass_min_var = nullptr;
        RooRealVar* mass_max_var = nullptr;
        RooFormulaVar* mass_cheby = nullptr;
        RooArgList cheby;
	RooChebychev* bkgd = nullptr;

        mass = new RooRealVar(ntuple_mass_name.c_str(), ntuple_mass_name.c_str(), mass_min, mass_max);
        mass_min_var = new RooRealVar("mass_min", "mass_min", mass_min, mass_min, mass_min);
        mass_max_var = new RooRealVar("mass_max", "mass_max", mass_max, mass_max, mass_max);
        s = "(2.0*" + ntuple_mass_name + "-mass_max-mass_min)/(mass_max-mass_min)";
        mass_cheby = new RooFormulaVar((ntuple_mass_name + "_cheby").c_str(), s.c_str(), RooArgList(*mass, *mass_min_var, *mass_max_var));
        for(i = 0; i < deg_cheby; ++i)
        {
                s = "d_";
                s += std::to_string(i);
                cheby.addOwned(*(new RooRealVar(s.c_str(), s.c_str(), 0.0, -FLT_MAX, FLT_MAX)));
        }
        s = "bkgd";
	RooRealVar e1("e1", "e1", 0.0, -1.0, 1.0);
	RooRealVar e2("e2", "e2", 0.0, -1.0, 1.0);
        //bkgd = new RooChebychev(s.c_str(), s.c_str(), *mass, RooArgSet( e1 , e2));
	//bkgd = new RooChebychev(s.c_str(), s.c_str(), *mass_cheby, RooArgSet( *(new RooRealVar("e_1", "e_1", 0.0, -FLT_MAX, FLT_MAX)) ));
	bkgd = new RooChebychev(s.c_str(), s.c_str(), *mass, cheby);

	mass->setVal(2.3);
	std::cout << mass_cheby->getValV() << std::endl;
	std::cout << bkgd->getValV() << std::endl;
}
