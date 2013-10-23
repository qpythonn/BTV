#include "TFile.h"
#include "TString.h"
#include "TH1D.h"
#include "TCanvas.h"
#include <iostream>
#include "OptimalDistance.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TH2D.h"
#include "TH1.h"
#include "TH2.h"
#include "TSystem.h"
#include "TGraph.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TVirtualPad.h"
#include <vector>
#include <iostream>

 




//

std::vector<Double_t> VB_eff_Tight;
std::vector<Double_t> VB_eff_Medium;
std::vector<Double_t> VB_eff_Loose;
std::vector<Double_t> VB_eff;


int MissingPoint_Tight;
int MissingPoint_Medium;
int MissingPoint_Loose;



//Double_t target;
//cout << "Give the targeted value pf light efficiency" << endl;
//cin >> target;




void maketheplot(TString filename,TString histoname)
{


  cout << "Tchob" << endl;
  TFile *myfile=new TFile (filename,"read");
  TH1D * myhist = (TH1D*) myfile->Get(histoname);
  if(myhist==0)
    {
      cout << "wrong histogram name " << histoname << "!!!" << endl;
      return;
    }

  Double_t target;
  string stitle;
  string starget;


  // bo of the loop over the 3 working point
  // ------------------------ 

  
  for(target=0.001; target<=0.1; target = 10 * target)
    {

      if (target==0.001)
	{
	  stitle="Tight";
	  starget="0.001";
	  cout << stitle << target << endl;
	}
  



  Double_t Y_high=0;
  Double_t Y_low=0;
  Double_t X_high=0;
  Double_t X_low=0;
  int bin_number_high =0;
  int bin_number_low =0;

    

  // find the bottom and the top edge
  while (Y_high < target)
    {

      if (Y_high !=0)
	{
	  Y_low = Y_high;
	  bin_number_low = bin_number_high;
	}
      Y_high = myhist->GetBinContent(bin_number_high);
      bin_number_high++;

    }

  X_low = myhist->GetBinCenter(bin_number_low); // Define more readable variable
  X_high = myhist->GetBinCenter(bin_number_high);

  cout << "Ive found top edge!!!! Coordinate is : (" << X_high << ";" << Y_high << ")" << endl;
  cout << "Ive found low edge!!!! Coordinate is : (" << X_low << ";" << Y_low << ")" <<  endl;


  Double_t  B_eff = 0;


  B_eff= ((target-Y_low)* (X_high-X_low)/(Y_high-Y_low))+ X_low; // Do the extrapolation

  cout << "The interpolated B efficiency B_eff=" << B_eff << "%" <<  " for misstag efficiency=" << target << "%."  << endl;

  VB_eff.push_back(B_eff);  

  // Build the beff vector for differrent working point  

  int MissingPoint_Tight;
  int MissingPoint_Medium;
  int MissingPoint_Loose;


  if (target==0.001)
    { if (Y_low==0)
	{
	  MissingPoint_Tight++;
	}
      else VB_eff_Tight.push_back(B_eff);     
    }
  else if (target==0.01)
    { if (Y_low==0)
	{
	  MissingPoint_Medium++;
	  cout << "MissingPoint_Medium" << MissingPoint_Medium << endl;
	}
      else VB_eff_Medium.push_back(B_eff);     
    }
  else
    { if (Y_low==0)
	{
	  MissingPoint_Loose++;
	}
      else VB_eff_Loose.push_back(B_eff);     
    }
 
  // int last = VB_eff.size()-1;
  // cout << "last B_eff computed =" << VB_eff[last]<< endl;
  
  

  //  string a = "im a nice faco";
  //  cout << a << endl;
  //  cout << a+" and I know it!" << endl;


    }

  // ------------------------
  // eo of the loop over the 3 working point

}


void OptimalDistance()
{



  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist0001_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist001_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist003_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist004_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist005_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist006_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist007_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist009_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist011_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist1_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging//UpgradedSample/crab_output/dist10_10k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  cout << "list of all B_eff" << endl;




  /*
  // ---- USED FROM THE 16.05.2013
  // ----------------------------------------------------
     
  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0001_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist001_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0020_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist003_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist005_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0060_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");
  
  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0063_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");
  
  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0065_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");
      
  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0068_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

 maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0070_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");
  
  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0073_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");
  
  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0075_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");
  
  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist0078_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");
  
  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist009_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

  maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist011_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

    maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist1_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

    maketheplot("/Users/qpython/Desktop/phd/roothist//BTagging/CSV/dist10_50k.root","DQMData/Run 1/Btag/Run summary/CSV_GLOBAL/FlavEffVsBEff_DUSG_discr_CSV_GLOBAL");

 cout << "list of all B_eff" << endl;


                                        
 // ----------------------------------------------------   
 // ---- USED FROM THE 16.05.2013                                                                  
*/


 cout << "The B_eff vector for the Tight wp" << endl;

 for (int i=0; i < VB_eff_Tight.size();i++)
   {
     cout << VB_eff_Tight[i]<< endl;
   }


 cout << "The B_eff vector for the Medium wp" << endl;

 for (int i=0; i < VB_eff_Medium.size();i++)
   {
     cout << VB_eff_Medium[i]<< endl;
   }




 cout << "The B_eff vector for the Loose wp" << endl;

 for (int i=0; i < VB_eff_Loose.size();i++)
   {
     cout << VB_eff_Loose[i]<< endl;
   }





 // Hard wired distance vector (need to be improved)
std::vector<Double_t> VDistance;

VDistance.push_back(0.001);
VDistance.push_back(0.01);
//VDistance.push_back(0.020);
//
VDistance.push_back(0.03);
VDistance.push_back(0.04);
VDistance.push_back(0.05);
VDistance.push_back(0.06);
//
//VDistance.push_back(0.063);
//VDistance.push_back(0.065);
//VDistance.push_back(0.068);
//
VDistance.push_back(0.07);
//VDistance.push_back(0.073);
//VDistance.push_back(0.075);
//
//VDistance.push_back(0.078);
VDistance.push_back(0.09);
VDistance.push_back(0.11);
//
VDistance.push_back(1);
VDistance.push_back(10);


 // Convert Vector into array

 const int vector_size = VDistance.size();
 cout << "size is = " << vector_size << endl;

 if (vector_size != VB_eff.size()/3 )
   {
     cout << "Warning!!! The two vectors dont have the same size!!" << endl;
     cout << "VDistance size is =" << vector_size << endl;
     cout << " BE_eff size is =" << VB_eff.size() << endl;
   }




 double AB_eff [vector_size]; // Array of B_eff
 double ADistance [vector_size];
 



 


 for (i=0; i<vector_size;i++)
   {
     AB_eff[i]=VB_eff_Tight[i];
     ADistance[i]=VDistance[i];
     //  cout << VDistance[i] << endl;
   }

 cout << "MissingPoint_Tight = " << MissingPoint_Tight << endl;

 TCanvas * c_tight = new  TCanvas();
 TGraph *mygraph_tight = new TGraph (vector_size-MissingPoint_Tight,ADistance, AB_eff);//vector_size-MissingPoint_Tight


 mygraph_tight->GetXaxis()->SetTitle("maximal distance to jet axis [cm]");
 mygraph_tight->GetYaxis()->SetTitle("BTag efficiency");
 mygraph_tight->SetTitle("B eff vs distance for Tight point (mistag eff=0.1%) ");


  TFile* f = TFile::Open("PlotsOutput/PerformanceCurve.root","UPDATE");
  mygraph_tight->Draw("*"); 
  mygraph_tight->Write();
  f->Close();




 for (i=0; i<vector_size;i++)
   {
     AB_eff[i]=VB_eff_Medium[i];
     ADistance[i]=VDistance[i];
     //     cout << VDistance[i] << endl;
   }

 cout << "MissingPoint_Medium = " << MissingPoint_Medium << endl;


 TCanvas * c_Medium = new  TCanvas();
 TGraph *mygraph_Medium = new TGraph (vector_size-MissingPoint_Medium,ADistance, AB_eff);//vector_size-MissingPoint_Medium


 mygraph_Medium->GetXaxis()->SetTitle("maximal distance to jet axis [cm]");
 mygraph_Medium->GetYaxis()->SetTitle("BTag efficiency");
 mygraph_Medium->SetTitle("B eff vs distance for Medium point (mistag eff=1%) ");


  TFile* f = TFile::Open("PlotsOutput/PerformanceCurve.root","UPDATE");
  mygraph_Medium->Draw("*"); 
  mygraph_Medium->Write();
  f->Close();





 for (i=0; i<vector_size;i++)
   {
     AB_eff[i]=VB_eff_Loose[i];
     ADistance[i]=VDistance[i];
     //     cout << VDistance[i] << endl;
   }

 cout << "MissingPoint_Loose = " << MissingPoint_Loose << endl;

 TCanvas * c_Loose = new  TCanvas();
 TGraph *mygraph_Loose = new TGraph (vector_size-MissingPoint_Loose,ADistance, AB_eff);


 mygraph_Loose->GetXaxis()->SetTitle("maximal distance to jet axis [cm]");
 mygraph_Loose->GetYaxis()->SetTitle("BTag efficiency");
 mygraph_Loose->SetTitle("B eff vs distance for Loose point (mistag eff=10%) ");


  TFile* f = TFile::Open("PlotsOutput/PerformanceCurve.root","UPDATE");
  mygraph_Loose->Draw("*"); 
  mygraph_Loose->Write();
  f->Close();




}

