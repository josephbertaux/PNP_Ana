int make_dum_data()
{
	float m = 0;

	TRandom rng(1234);

	TFile* prompt_file = TFile::Open("prompt.root", "RECREATE");
	TTree* prompt_tree = new TTree("prompt", "prompt");
	prompt_tree->SetDirectory(prompt_file);
	prompt_tree->Branch("mass", &m);

	for(int i = 0; i < 1348; i++)
	{
		m = rng.Gaus(1.34, 2.2);
		prompt_tree->Fill();
	}

	prompt_tree->Write();
	prompt_file->Write();
	prompt_file->Close();

	TFile* nprmpt_file = TFile::Open("nprmpt.root", "RECREATE");
	TTree* nprmpt_tree = new TTree("nprmpt", "nprmpt");
	nprmpt_tree->SetDirectory(nprmpt_file);
	nprmpt_tree->Branch("mass", &m);

	for(int i = 0; i < 762; i++)
	{
		m = rng.Gaus(1.34, 2.7);
		nprmpt_tree->Fill();
	}

	nprmpt_tree->Write();
	nprmpt_file->Write();
	nprmpt_file->Close();

	return 0;
}
