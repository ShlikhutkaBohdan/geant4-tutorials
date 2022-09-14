//
// Created by Boday Alfaro on 14.09.2022.
//

#include "g4root.hh"
#include "run.hh"

MyRunAction::MyRunAction() = default;

MyRunAction::~MyRunAction() = default;

void MyRunAction::BeginOfRunAction(const G4Run *aRun) {
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->OpenFile("output.root");
    man->CreateNtuple("Hits", "Hits");
    man->CreateNtupleIColumn("fEvent");
    man->CreateNtupleDColumn("fX");
    man->CreateNtupleDColumn("fY");
    man->CreateNtupleDColumn("fZ");
    man->FinishNtuple(0);
}

void MyRunAction::EndOfRunAction(const G4Run *aRun) {
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->Write();
    man->CloseFile();
}
