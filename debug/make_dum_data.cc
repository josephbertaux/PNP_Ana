int make_dum_data()
{
	float m = 0;
	float a = 0;
	float b = 0;
	float c = 0;
	float d = 0;

	TRandom rng(1234);

	TFile* prompt_file = TFile::Open("prompt.root", "RECREATE");
	TTree* prompt_tree = new TTree("prompt", "prompt");
	prompt_tree->SetDirectory(prompt_file);
	prompt_tree->Branch("mass", &m);
	prompt_tree->Branch("a", &a);
	prompt_tree->Branch("b", &b);
	prompt_tree->Branch("c", &c);
	prompt_tree->Branch("d", &d);

	for(int i = 0; i < 1348; i++)
	{
		m = rng.Gaus(1.34, 2.20);
		a = rng.Gaus(0.00, 1.00);
		b = rng.Gaus(2.00, 1.00);
		c = rng.Gaus(4.00, 1.00);
		d = rng.Gaus(6.00, 1.00);
		prompt_tree->Fill();
	}

	prompt_tree->Write();
	prompt_file->Write();
	prompt_file->Close();

	TFile* nprmpt_file = TFile::Open("nprmpt.root", "RECREATE");
	TTree* nprmpt_tree = new TTree("nprmpt", "nprmpt");
	nprmpt_tree->SetDirectory(nprmpt_file);
	nprmpt_tree->Branch("mass", &m);
	nprmpt_tree->Branch("a", &a);
	nprmpt_tree->Branch("b", &b);
	nprmpt_tree->Branch("c", &c);
	nprmpt_tree->Branch("d", &d);

	for(int i = 0; i < 762; i++)
	{
		m = rng.Gaus(1.34, 2.70);
		a = rng.Gaus(0.00, 1.00);
		b = rng.Gaus(1.00, 1.00);
		c = rng.Gaus(3.00, 1.00);
		d = rng.Gaus(5.00, 1.00);
		nprmpt_tree->Fill();
	}

	nprmpt_tree->Write();
	nprmpt_file->Write();
	nprmpt_file->Close();

	TFile* bkgrnd_file = TFile::Open("bkgrnd.root", "RECREATE");
	TTree* bkgrnd_tree = new TTree("bkgrnd", "bkgrnd");
	bkgrnd_tree->SetDirectory(bkgrnd_file);
	bkgrnd_tree->Branch("mass", &m);
	bkgrnd_tree->Branch("a", &a);
	bkgrnd_tree->Branch("b", &b);
	bkgrnd_tree->Branch("c", &c);
	bkgrnd_tree->Branch("d", &d);

	for(int i = 0; i < 7620; i++)
	{
		m = rng.Gaus(-7.00, 0.20);
		a = rng.Gaus(0.00, 1.00);
		b = rng.Gaus(-2.00, 1.00);
		c = rng.Gaus(-3.00, 1.00);
		d = rng.Gaus(5.00, 1.00);
		bkgrnd_tree->Fill();
	}

	bkgrnd_tree->Write();
	bkgrnd_file->Write();
	bkgrnd_file->Close();

	return 0;
}
