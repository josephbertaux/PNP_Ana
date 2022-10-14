int make_dum_data()
{
	float m = 0;
	float b = 0;

	TRandom rng(1234);

	TFile* prompt_file = TFile::Open("prompt.root", "RECREATE");
	TTree* prompt_tree = new TTree("prompt", "prompt");
	prompt_tree->SetDirectory(prompt_file);
	prompt_tree->Branch("mass", &m);
	prompt_tree->Branch("b", &b);

	for(int i = 0; i < 1348; i++)
	{
		m = rng.Gaus(1.34, 2.20);
		b = rng.Gaus(2.00, 1.00);
		prompt_tree->Fill();
	}

	prompt_tree->Write();
	prompt_file->Write();
	prompt_file->Close();

	TFile* nprmpt_file = TFile::Open("nprmpt.root", "RECREATE");
	TTree* nprmpt_tree = new TTree("nprmpt", "nprmpt");
	nprmpt_tree->SetDirectory(nprmpt_file);
	nprmpt_tree->Branch("mass", &m);
	nprmpt_tree->Branch("b", &b);

	for(int i = 0; i < 762; i++)
	{
		m = rng.Gaus(1.34, 2.70);
		b = rng.Gaus(4.00, 1.00);
		nprmpt_tree->Fill();
	}

	nprmpt_tree->Write();
	nprmpt_file->Write();
	nprmpt_file->Close();

	return 0;
}
