int make_dum_data()
{
	float m = 0;

	TFile* prompt_file = TFile::Open("prompt.root", "RECREATE");
	TTree* prompt_tree = new TTree("prompt", "prompt");
	prompt_tree->SetDirectory(prompt_file);
	prompt_tree->Branch("mass", &m);

	for(int i = 0; i < 100; i++)
	{
		m = i;
		prompt_tree->Fill();
	}

	prompt_tree->Write();
	prompt_file->Write();
	prompt_file->Close();

	TFile* nprmpt_file = TFile::Open("nprmpt.root", "RECREATE");
	TTree* nprmpt_tree = new TTree("nprmpt", "nprmpt");
	nprmpt_tree->SetDirectory(nprmpt_file);
	nprmpt_tree->Branch("mass", &m);

	for(int i = 0; i < 100; i++)
	{
		m = i;
		nprmpt_tree->Fill();
	}

	nprmpt_tree->Write();
	nprmpt_file->Write();
	nprmpt_file->Close();

	return 0;
}
