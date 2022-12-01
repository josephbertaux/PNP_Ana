std::string write_gauss(std::string& s, int i)
{
	char buff[128];
	sprintf(buff, "[%d]*(0.398942280401432678/[%d])*exp(-0.5*((x-[%d])/[%d])**2)", i, i+2, i+1, i+2);
	s = buff;

	return s;
}

std::string write_cheby(std::string& s, float min, float max, int d)
{
	char buff[128];
	sprintf(buff, "cos(%d*acos((2.0*x-%f-%f)/(%f-%f)))", d, max, min, max, min);
	s = buff;

	return s;
}

int make_dum_data()
{
	Long64_t prompt_counts = 2242;
	Long64_t nprmpt_counts = 1142;
	Long64_t sgnl_counts = 31042;
	Long64_t bkgd_counts = 12351;

	std::ofstream parameters_file("dum_data_parameters", std::ios_base::out | std::ios_base::trunc);
	parameters_file << "prompt_counts:\t" << prompt_counts << std::endl;
	parameters_file << "nprmpt_counts:\t" << nprmpt_counts << std::endl;
	parameters_file << "sgnl_counts:\t" << sgnl_counts << std::endl;
	parameters_file << "bkgd_counts:\t" << bkgd_counts << std::endl;

	Long64_t n;

	float m = 0;
	float m_min;
	float m_max;
	float a = 0;
	float b = 0;

	int num_gauss = 2;
	int deg_cheby = 3;

	TRandom rng(1234);

	std::string str;
	std::string t;

	//=========GAUSS==============//

	t = "";
	n = 0;
	while(true)
	{
		write_gauss(str, n * num_gauss);
		t += str;

		++n;
		if(n >= num_gauss)break;

		t += "+";
	}

	float mu = 10 + 10 * rng.Rndm();
	float c[num_gauss];
	float s[num_gauss];

	b = 0;
	for(n = 0; n < num_gauss; ++n)
	{
		c[n] = rng.Rndm();
		s[n] = 10 + 10 * rng.Rndm();
		b += c[n];
	}
	for(n = 0; n < num_gauss; ++n)
	{
		c[n] /= b;
	}

	b = 0;
	for(n = 0; n < num_gauss; ++n)
	{
		b += c[n]*s[n]*s[n];
	}
	b = sqrt(b);
	m_min = mu - 5.0 * b;
	m_max = mu + 5.0 * b;

	TF1* mc = new TF1("mc", t.c_str(), m_min, m_max);
	for(n = 0; n < num_gauss; ++n)
	{
		mc->SetParameter(3*n+0, c[n]);
		mc->SetParameter(3*n+1, mu);
		mc->SetParameter(3*n+2, s[n]);
	}

	parameters_file << "mu:\t" << mu << std::endl;
	for(n = 0; n < num_gauss; ++n)
	{
		parameters_file << "c[" << n << "]:\t" << c[n] << "\t";
		parameters_file << "s[" << n << "]:\t" << s[n] << std::endl;
	}
	parameters_file << "s_eff:\t" << b << std::endl;
	parameters_file << "m_min:\t" << m_min << std::endl;
	parameters_file << "m_max:\t" << m_max << std::endl;

	//=========CHEBYCHEV==========//

	float d[deg_cheby];

	t = "";
	n = 0;
	while(true)
	{
		write_cheby(str, m_min, m_max, n);
		t += "[";
		t += std::to_string(n);
		t += "]*";
		t += str;

		++n;
		if(n >= deg_cheby)break;

		t += "+";
	}
	TF1* bk = new TF1("bk", t.c_str(), m_min, m_max);
	for(n = 0; n < deg_cheby; ++n)
	{
		d[n] = rng.Rndm();
		bk->SetParameter(n, d[n]);
		parameters_file << "d[" << n << "]:\t" << d[n] << std::endl;
	}

	//===============FILL PROMPT=========//

	TFile* prompt_file = TFile::Open("prompt_for_debug.root", "RECREATE");
	TTree* prompt_tree = new TTree("prompt_for_debug", "prompt_for_debug");
	prompt_tree->SetDirectory(prompt_file);
	prompt_tree->Branch("mass", &m);
	for(n = 0; n < prompt_counts; ++n)
	{
		m = mc->GetRandom();
		prompt_tree->Fill();
	}
	prompt_tree->Write();
	prompt_file->Write();
	prompt_file->Close();

	//===============FILL NPRMPT=========//

	TFile* nprmpt_file = TFile::Open("nprmpt_for_debug.root", "RECREATE");
	TTree* nprmpt_tree = new TTree("nprmpt_for_debug", "nprmpt_for_debug");
	nprmpt_tree->SetDirectory(nprmpt_file);
	nprmpt_tree->Branch("mass", &m);
	for(n = 0; n < nprmpt_counts; ++n)
	{
		m = mc->GetRandom();
		nprmpt_tree->Fill();
	}
	nprmpt_tree->Write();
	nprmpt_file->Write();
	nprmpt_file->Close();

	//===============FILL BKGRND=========//

	TFile* bkgrnd_file = TFile::Open("bkgrnd_for_debug.root", "RECREATE");
	TTree* bkgrnd_tree = new TTree("bkgrnd_for_debug", "bkgrnd_for_debug");
	bkgrnd_tree->SetDirectory(bkgrnd_file);
	bkgrnd_tree->Branch("mass", &m);
	for(n = 0; n < sgnl_counts; ++n)
	{
		m = mc->GetRandom();
		bkgrnd_tree->Fill();
	}
	for(n = 0; n < bkgd_counts; ++n)
	{
		m = bk->GetRandom();
		bkgrnd_tree->Fill();
	}
	bkgrnd_tree->Write();
	bkgrnd_file->Write();
	bkgrnd_file->Close();

	return 0;
}

/*
	a = 0.0;
	for(n = 0; n < mc_tree->GetEntriesFast(); ++n)
	{
		mc_tree->GetEntry(n);
		a += m;
	}
	a /= n;

	b = 0.0;
	for(n = 0; n < mc_tree->GetEntriesFast(); ++n)
	{
		mc_tree->GetEntry(n);
		m -= a;
		b += m * m;
	}
	b /= n;
	b = sqrt(b);

	std::cout << std::endl;
	std::cout << "mu:\t\t" << mu << std::endl;
	std::cout << "measured:\t" << a << std::endl;
	std::cout << std::endl;
	a = 0.0;
	for(n = 0; n < num_gauss; ++n)
	{
		a += c[n]*s[n]*s[n];
	}
	a = sqrt(a);
	std::cout << "s_eff:\t\t" << a << std::endl;
	std::cout << "measured:\t" << b << std::endl;
	std::cout << std::endl;
*/
