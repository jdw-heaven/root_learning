#include <TFile.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TMath.h>

void calculateAndPlot(double a) {
  const int kMax = 50; // 前10项和
  const int nPoints = 1000; // 图中的点数

  double xMin = -5.0;
  double xMax = 5.0;
  double dx = (xMax - xMin) / nPoints;

  double x[nPoints];
  double ySum[nPoints];
  for (int i = 0; i < nPoints; ++i) {
    x[i] = xMin + i * dx;
    ySum[i] = 0.0;
  }

  for (int k = 1+50; k <= kMax+100; ++k) {
    for (int i = 0; i < nPoints; ++i) {
      double term = 2.0 * TMath::Sin(k * TMath::Pi() * a) * TMath::Sin(k * TMath::Pi() * x[i]);
      ySum[i] += term;
    }
  }

  TGraph* graph = new TGraph(nPoints, x, ySum);
  graph->SetTitle("Sum of Terms");
  //graph->GetXaxis()->SetTitle("x");
  //graph->GetYaxis()->SetTitle("Sum");

  TCanvas* canvas = new TCanvas("canvas", "Sum of Terms", 800, 600);
  graph->Draw("AL");

  TString fileName = TString::Format("sum_graph_a_%.2f.root", a);
  TFile* outputFile = new TFile(fileName, "RECREATE");
  graph->Write();
  outputFile->Close();

  delete graph;
  delete canvas;
}

void delta() {
  double a = 0.5; // 参数a的值
  calculateAndPlot(a);
}