{


  gSystem->Load("libFWCoreFWLite.so");
  AutoLibraryLoader::enable();
  TFile f("patTuple_PF2PAT.root");

  TTree* Events = 0;
  gDirectory->GetObject("Events", Events);
  
  Events->Draw("patMuons_selectedPatMuons__PAT.obj.pt()>>h1");
  Events->Draw("patMuons_selectedPatMuonsPFlow__PAT.obj.pt()>>h2","","same");
 
  TH1* h1 = 0;
  gDirectory->GetObject("h1", h1);
  h1->SetStats( false );
  h1->Draw();

  TH1* h2 = 0;
  gDirectory->GetObject("h2", h2);
  h2->SetLineColor(4);
  h2->Draw("same");

  TLegend leg(0.6,0.6,0.8,0.8);
  leg.AddEntry( h1, "std PAT");
  leg.AddEntry( h2, "PF2PAT+PAT");
  leg.Draw();
}
