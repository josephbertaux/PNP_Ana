#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TFileCollection.h"
#include "TH1.h"

#include "TMath.h"
#include "TComplex.h"
#include "TH2.h"
#include "TH3.h"

#include "initAnalysisBinning_pt_tmp.h" ///IMPORTANT: here I define analysis binnning

//Histograms for BDT selection: use optimized cuts for BDT, done using mass scan in (centrality, y, pT)


Double_t GetBDTCut(Double_t pt, Int_t centrality) {
  Double_t bdtcut = -1.;

//  Double_t bdtcut_0_10[11] = {0.3, 0.4, 0.35, 0.27, 0.15, 0.125, 0.180, 0.18, -0.12, -0.2, -0.4}; //0-10% centrality
//  Double_t bdtcut_10_30[11] = {0.3, 0.4, 0.3, 0.25, 0.1, 0.13, 0.08, 0.05, 0.0, -0.2, -0.4}; //10-30% 
//  Double_t bdtcut_30_50[11] = {0.37, 0.3, 0.3, 0.25, 0.13, 0.08, 0.026, -0.025, -0.11, -0.2, -0.4}; // 30-50%

//  Double_t bdtcut_0_10[11] = {0.3, 0.4, 0.35, 0.27, 0.15, 0.125, 0.180, 0.18, 0.12, 0.05, 0.05}; //0-10% centrality
//  Double_t bdtcut_10_30[11] = {0.3, 0.4, 0.3, 0.25, 0.1, 0.13, 0.08, 0.05, 0.05, 0.05, 0.05}; //10-30% 
//  Double_t bdtcut_30_50[11] = {0.37, 0.3, 0.3, 0.25, 0.13, 0.1, 0.1, 0.08, 0.05, 0.05, 0.025}; // 30-50%

//cut v2
  Double_t bdtcut_0_10[11] = {0.3, 0.5, 0.4, 0.265987, 0.258249, 0.142969, 0.127459, 0.0788772, -0.132497, -0.2265, -0.4};
  Double_t bdtcut_10_30[11] = {0.318694, 0.5, 0.313588, 0.261772, 0.17, 0.11, 0.07, 0.03, 0, -0.3, -0.4};
  Double_t bdtcut_30_50[11] = {0.5, 0.317762, 0.29961, 0.226, 0.159684, 0.112256, 0.07, 0.02, -0.040774, -0.1, -0.4};

  Double_t ptBDTbin[11] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 10.0, 15.0, 20.0, 30.0};

  if (centrality < 20) {
        for (int i=0; i<10; i++)  if (ptBDTbin[i]<pt && ptBDTbin[i+1]>pt) bdtcut = bdtcut_0_10[i];

  }
  if (centrality >= 20 && centrality < 60) {
        for (int i=0; i<10; i++)  if (ptBDTbin[i]<pt && ptBDTbin[i+1]>pt) bdtcut = bdtcut_10_30[i];

  }
  if (centrality >= 60 && centrality < 100) {
        for (int i=0; i<10; i++)  if (ptBDTbin[i]<pt && ptBDTbin[i+1]>pt) bdtcut = bdtcut_30_50[i];

  }

  return bdtcut;
}

//B->D0 eff table
//TFile *file_eff = TFile::Open("/home/mstojano/d0/v2/macros/BtoDpt/outputcenteff.root");

//TH2D *hist_eff = (TH2D*)file_eff->Get("centpteff");

bool istest = true;
void build_2DmassvnHisto_template(TString inputfile="inputFileList.txt", TString outfile1=""  ){

        if(istest)
        {
                inputfile="/scratch/halstead/m/mstojano/d0outputs/dataoutputMiniAODwBDT/MinimumBias00/Dntuple_Dntuple_d0ana_PbPb2018_00.root_0.root_0.root";
                outfile1="output.root";
        }

TH1::StatOverflows(kTRUE);

TFile *file = TFile::Open(inputfile);

TTree *tree = (TTree *)file->Get("mvaTree");
Int_t MAXD0CandSize=10000;

tree->SetBranchStatus("*",0);     // disable all branches
tree->SetBranchStatus("candSize",1);
tree->SetBranchStatus("centrality",1);
tree->SetBranchStatus("ephfpAngle",1);
tree->SetBranchStatus("ephfmAngle",1);
tree->SetBranchStatus("ephfpQ",1);
tree->SetBranchStatus("ephfmQ",1);
tree->SetBranchStatus("pT",1);
tree->SetBranchStatus("phi",1);
//tree->SetBranchStatus("mva",1);
tree->SetBranchStatus("BDT_weight",1);
tree->SetBranchStatus("y",1);
tree->SetBranchStatus("mass",1);
tree->SetBranchStatus("dca",1);
tree->SetBranchStatus("ImpactParameter3Derror",1);
tree->SetBranchStatus("ImpactParameter3Dsignificance",1);
tree->SetBranchStatus("eptkAngle",1);
tree->SetBranchStatus("eptkQ",1);
tree->SetBranchStatus("Dtrk1Chi2n",1);
tree->SetBranchStatus("Dtrk2Chi2n",1);
tree->SetBranchStatus("3DPointingAngle", 1);
tree->SetBranchStatus("2DPointingAngle", 1);

// SetBranchAddress
Int_t candSize;
Int_t centrality;
Float_t ephfpAngle[3];
Float_t ephfmAngle[3];
Float_t ephfpQ[3];
Float_t ephfmQ[3];
Float_t pT[MAXD0CandSize];
Float_t phi[MAXD0CandSize];
Float_t mva[MAXD0CandSize];
Double_t mvaNp[MAXD0CandSize];
Float_t y[MAXD0CandSize];
Float_t flavor[MAXD0CandSize];
Float_t mass[MAXD0CandSize];
Float_t dca[MAXD0CandSize];
Float_t dcaer[MAXD0CandSize];
Float_t eptkAngle[2];
Float_t eptkQ[2];
Float_t Dtrk1Chi2n[MAXD0CandSize];
Float_t Dtrk2Chi2n[MAXD0CandSize];
Float_t ip3d[MAXD0CandSize];
Float_t ip3derr[MAXD0CandSize];
Float_t alpha[MAXD0CandSize];
Float_t alpha2D[MAXD0CandSize];

tree->SetBranchAddress("candSize", &candSize);
tree->SetBranchAddress("centrality", &centrality);
tree->SetBranchAddress("ephfpAngle", &ephfpAngle);
tree->SetBranchAddress("ephfmAngle", &ephfmAngle);
tree->SetBranchAddress("ephfpQ", &ephfpQ);
tree->SetBranchAddress("ephfmQ", &ephfmQ);
tree->SetBranchAddress("pT", &pT);
tree->SetBranchAddress("phi", &phi);
tree->SetBranchAddress("mva", &mva);
tree->SetBranchAddress("BDT_weight", &mvaNp);
tree->SetBranchAddress("y", &y);
tree->SetBranchAddress("mass", &mass);
tree->SetBranchAddress("ImpactParameter3Derror", &dcaer);
tree->SetBranchAddress("ImpactParameter3Dsignificance", &dca);
tree->SetBranchAddress("eptkAngle", &eptkAngle);
tree->SetBranchAddress("eptkQ", &eptkQ);
tree->SetBranchAddress("Dtrk1Chi2n", &Dtrk1Chi2n);
tree->SetBranchAddress("Dtrk2Chi2n", &Dtrk2Chi2n);
tree->SetBranchAddress("3DPointingAngle", &alpha);
tree->SetBranchAddress("2DPointingAngle", &alpha2D);

TString BDTcut = "pt_allcent";// "check2";
// array for vn denominator for each centrality classification
TFile* file1 = TFile::Open("/depot/cms/users/mstojano/D0ESE/resolution/resolution.root");

Double_t vn_den = -99999999.9;
Double_t v2_den[N_CENTBIN];
Double_t v3_den[N_CENTBIN];
/*
        if(isV2){
          TH1D *hQnQn_HFmHFp = (TH1D*)file1->Get("Q2Q2_HFmHFp_Re_"+label_centbin);
          TH1D *hQnQn_HFmTrk = (TH1D*)file1->Get("Q2Q2_HFmTrk_Re_"+label_centbin);
          TH1D *hQnQn_HFpTrk = (TH1D*)file1->Get("Q2Q2_HFpTrk_Re_"+label_centbin);
          vn_den = TMath::Sqrt( (hQnQn_HFmHFp->GetMean()*hQnQn_HFmTrk->GetMean()) / (hQnQn_HFpTrk->GetMean()) );
        }
        else if(isV3){
          TH1D *hQnQn_HFmHFp = (TH1D*)file1->Get("Q3Q3_HFmHFp_Re_"+label_centbin);
          TH1D *hQnQn_HFmTrk = (TH1D*)file1->Get("Q3Q3_HFmTrk_Re_"+label_centbin);
          TH1D *hQnQn_HFpTrk = (TH1D*)file1->Get("Q3Q3_HFpTrk_Re_"+label_centbin);
          vn_den = TMath::Sqrt( (hQnQn_HFmHFp->GetMean()*hQnQn_HFmTrk->GetMean()) / (hQnQn_HFpTrk->GetMean()) );
          cout <<"Mean1 = "<<hQnQn_HFmHFp->GetMean()<< " #pm "<<hQnQn_HFmHFp->GetMeanError()<< " Mean 2 = "<<hQnQn_HFmTrk->GetMean()<< " #pm "<<hQnQn_HFmTrk->GetMeanError()<< " Mean 3 = "<<hQnQn_HFpTrk->GetMean()<< " #pm "<<hQnQn_HFpTrk->GetMeanError()<<endl;
        }
*/


TH1D *hQ2Q2_HFmHFp[N_CENTBIN];
TH1D *hQ2Q2_HFmTrk[N_CENTBIN];
TH1D *hQ2Q2_HFpTrk[N_CENTBIN];

TH1D *hQ3Q3_HFmHFp[N_CENTBIN];
TH1D *hQ3Q3_HFmTrk[N_CENTBIN];
TH1D *hQ3Q3_HFpTrk[N_CENTBIN];

for(Int_t i=0; i<N_CENTBIN; i++){
          hQ2Q2_HFmHFp[i] = (TH1D*)file1->Get("Q2Q2_HFmHFp_Re_"+label_centbin[i]);
          hQ2Q2_HFmTrk[i] = (TH1D*)file1->Get("Q2Q2_HFmTrk_Re_"+label_centbin[i]);
          hQ2Q2_HFpTrk[i] = (TH1D*)file1->Get("Q2Q2_HFpTrk_Re_"+label_centbin[i]);

          hQ3Q3_HFmHFp[i] = (TH1D*)file1->Get("Q3Q3_HFmHFp_Re_"+label_centbin[i]);
          hQ3Q3_HFmTrk[i] = (TH1D*)file1->Get("Q3Q3_HFmTrk_Re_"+label_centbin[i]);
          hQ3Q3_HFpTrk[i] = (TH1D*)file1->Get("Q3Q3_HFpTrk_Re_"+label_centbin[i]);
          v2_den[i] = TMath::Sqrt( (hQ2Q2_HFmHFp[i]->GetMean()*hQ2Q2_HFmTrk[i]->GetMean()) / (hQ2Q2_HFpTrk[i]->GetMean()) );
          v3_den[i] = TMath::Sqrt( (hQ3Q3_HFmHFp[i]->GetMean()*hQ3Q3_HFmTrk[i]->GetMean()) / (hQ3Q3_HFpTrk[i]->GetMean()) );
}

TFile* fout = new TFile(outfile1,"RECREATE");
fout->cd();


TH2D *h_D0_mass = new TH2D("D0_mass",";m_{inv};QQ_{A}^{*}",52,1.74,2.0,N_VNBIN,vnbinning);

TH2D *h_D0_mass_v2[N_CENTBIN][N_PTBIN][N_YBIN];//pT,y,centrality
TH2D *h_D0_mass_v3[N_CENTBIN][N_PTBIN][N_YBIN];//pT,y,centrality

for(Int_t i_centbin=0; i_centbin<N_CENTBIN; i_centbin++){
  for(Int_t i_pTbin=0; i_pTbin<N_PTBIN; i_pTbin++){
    for(Int_t i_ybin=0; i_ybin<N_YBIN; i_ybin++){
        //cout<<i_centbin<<" "<<i_pTbin<<" "<<i_ybin<<endl;
        h_D0_mass_v2[i_centbin][i_pTbin][i_ybin] = (TH2D*)h_D0_mass->Clone("hist_D0_mass_v2_"+label_centbin[i_centbin]+"_"+label_pTbin[i_pTbin]+"_"+label_ybin[i_ybin]);
        h_D0_mass_v3[i_centbin][i_pTbin][i_ybin] = (TH2D*)h_D0_mass->Clone("hist_D0_mass_v3_"+label_centbin[i_centbin]+"_"+label_pTbin[i_pTbin]+"_"+label_ybin[i_ybin]);

    }
  }
}

double weight =1.0;
TH3D *h_binning = new TH3D("centbins","",N_CENTBIN,centbinning,N_PTBIN,ptbinning,N_YBIN,dcabinning);
Long64_t n_entries = tree->GetEntriesFast();
//n_entries = 100000;

for(Long64_t ii=0; ii<n_entries; ii++){//loop in events

  tree->GetEntry(ii);
  if(ii % 5000 == 0)
    printf("current entry = %lld out of %lld : %.3f %%\n", ii, n_entries, (Double_t)ii / n_entries * 100);
  
   if (centrality >= max_centbin[N_CENTBIN-1]) continue;
   TComplex aux_Q2_HFm(ephfmQ[1]*TMath::Cos(2.0*ephfmAngle[1]),ephfmQ[1]*TMath::Sin(2.0*ephfmAngle[1]),0);
   TComplex aux_Q2_HFp(ephfpQ[1]*TMath::Cos(2.0*ephfpAngle[1]),ephfpQ[1]*TMath::Sin(2.0*ephfpAngle[1]),0);
   TComplex aux_Q2_Trk(eptkQ[0]*TMath::Cos(2.0*eptkAngle[0]),eptkQ[0]*TMath::Sin(2.0*eptkAngle[0]),0);

   TComplex aux_Q3_HFm(ephfmQ[2]*TMath::Cos(3.0*ephfmAngle[2]),ephfmQ[2]*TMath::Sin(3.0*ephfmAngle[2]),0);
   TComplex aux_Q3_HFp(ephfpQ[2]*TMath::Cos(3.0*ephfpAngle[2]),ephfpQ[2]*TMath::Sin(3.0*ephfpAngle[2]),0);
   TComplex aux_Q3_Trk(eptkQ[1]*TMath::Cos(3.0*eptkAngle[1]),eptkQ[1]*TMath::Sin(3.0*eptkAngle[1]),0);


   Int_t i_centbin = h_binning->GetXaxis()->FindBin(centrality)-1;

   for(Int_t i=0; i<candSize; i++){//loop in D0 + D0bar Candidates

   	    if (pT[i] >= max_pTbin[N_PTBIN-1] || pT[i] <= min_pTbin[0]) continue;
            if (dca[i] >= max_ybin[N_YBIN-1] || dca[i] <= min_ybin[0]) continue;

            if(mvaNp[i]<GetBDTCut(pT[i],centrality)) continue;
            if(fabs(y[i])>1.0)continue;
            if(Dtrk1Chi2n[i]>0.18   ) continue;  
            if(Dtrk2Chi2n[i]>0.18   ) continue;
            Int_t i_pTbin = h_binning->GetYaxis()->FindBin(pT[i])-1;
            Int_t i_ybin = h_binning->GetZaxis()->FindBin(dca[i])-1;
            //weight = 1.0/hist_eff->GetBinContent(hist_eff->GetXaxis()->FindBin(centrality),hist_eff->GetYaxis()->FindBin(pT[i]));
	    //if (hist_eff->GetBinContent(hist_eff->GetXaxis()->FindBin(centrality),hist_eff->GetYaxis()->FindBin(pT[i])) <0.0005) weight =1;
	    weight = 1.0;
            
            if(y[i]>0){
                  TComplex aux_Q2_D0(TMath::Cos(2.0*phi[i]),TMath::Sin(2.0*phi[i]),0);
                  Double_t aux_Q2Q2_D0HF_Re_centbin_pTbin_ybin_massbin = (aux_Q2_D0*TComplex::Conjugate(aux_Q2_HFm)).Re();
		  h_D0_mass_v2[i_centbin][i_pTbin][i_ybin]->Fill(mass[i],aux_Q2Q2_D0HF_Re_centbin_pTbin_ybin_massbin/v2_den[i_centbin],weight);

                  TComplex aux_Q3_D0(TMath::Cos(3.0*phi[i]),TMath::Sin(3.0*phi[i]),0);
                  Double_t aux_Q3Q3_D0HF_Re_centbin_pTbin_ybin_massbin = (aux_Q3_D0*TComplex::Conjugate(aux_Q3_HFm)).Re();
                  h_D0_mass_v3[i_centbin][i_pTbin][i_ybin]->Fill(mass[i],aux_Q3Q3_D0HF_Re_centbin_pTbin_ybin_massbin/v3_den[i_centbin],weight);

	    }	
            else{

                  TComplex aux_Q2_D0(TMath::Cos(2.0*phi[i]),TMath::Sin(2.0*phi[i]),0);
                  Double_t aux_Q2Q2_D0HF_Re_centbin_pTbin_ybin_massbin = (aux_Q2_D0*TComplex::Conjugate(aux_Q2_HFp)).Re();
                  h_D0_mass_v2[i_centbin][i_pTbin][i_ybin]->Fill(mass[i],aux_Q2Q2_D0HF_Re_centbin_pTbin_ybin_massbin/v2_den[i_centbin],weight);

                  TComplex aux_Q3_D0(TMath::Cos(3.0*phi[i]),TMath::Sin(3.0*phi[i]),0);
                  Double_t aux_Q3Q3_D0HF_Re_centbin_pTbin_ybin_massbin = (aux_Q3_D0*TComplex::Conjugate(aux_Q3_HFp)).Re();
                  h_D0_mass_v3[i_centbin][i_pTbin][i_ybin]->Fill(mass[i],aux_Q3Q3_D0HF_Re_centbin_pTbin_ybin_massbin/v3_den[i_centbin],weight);

            }
   }
}

for(Int_t i_centbin=0; i_centbin<N_CENTBIN; i_centbin++){
  for(Int_t i_pTbin=0; i_pTbin<N_PTBIN; i_pTbin++){
    for(Int_t i_ybin=0; i_ybin<N_YBIN; i_ybin++){

        h_D0_mass_v2[i_centbin][i_pTbin][i_ybin]->Write(); 
        h_D0_mass_v3[i_centbin][i_pTbin][i_ybin]->Write(); 

    }
  }
}

fout->Close();


std::cout<<" \n Done ... "<<std::endl;

    
}

int main(int argc, char *argv[])
{
        if(istest) argc=3;
        if(argc==3)
        {
                build_2DmassvnHisto_template(argv[1], argv[2]);
        }
        else
        {
                std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
                return 1;
        }
        return 0;
}


