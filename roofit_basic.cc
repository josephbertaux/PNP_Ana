#include "TFile.h"
#include "TTree.h"

#include "RooFit.h"
#include "RooRealVar.h"
#include "RooGaussian.h"
#include "RooArgSet.h"
#include "RooDataSet.h"

void roofit_basic()
{
	TFile* file = TFile::Open("prompt.root", "READ");
	if(!file)
	{
		std::cout << "file" << std::endl;
		return;
	}
	TTree* tree = (TTree*)file->Get("prompt");
	if(!tree)
	{
		std::cout << "tree" << std::endl;
	}

	RooRealVar mass("mass", "mass", -10.0, 10.0);
	RooRealVar mean("mean", "mean", 1.0, -10.0, 10.0);
	RooRealVar sgma("sgma", "sgma", 2.3, 0.1, 10.0);

	RooGaussian gss("gaus", "gaus", mass, mean, sgma);

	RooDataSet* data = gss.generate(mass, 1000);
	RooDataSet foo;
	foo = RooDataSet("foo", "foo", RooArgSet(mass), RooFit::Import(*tree));

	//gss.fitTo(*data);
	gss.fitTo(foo);
}
