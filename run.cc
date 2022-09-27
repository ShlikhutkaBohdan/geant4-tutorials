//
// Created by Boday Alfaro on 14.09.2022.
//

#include "g4root.hh"
#include "run.hh"
#include "G4Run.hh"

MyRunAction::MyRunAction() {
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->CreateNtuple("Photons", "Photons");
    man->CreateNtupleIColumn("fEvent");
    man->CreateNtupleDColumn("fX");
    man->CreateNtupleDColumn("fY");
    man->CreateNtupleDColumn("fZ");
    man->CreateNtupleDColumn("fWlen");
    man->CreateNtupleDColumn("fT"); //time
    man->FinishNtuple(0);

    man->CreateNtuple("Hits", "Hits");
    man->CreateNtupleIColumn("fEvent");
    man->CreateNtupleDColumn("fX");
    man->CreateNtupleDColumn("fY");
    man->CreateNtupleDColumn("fZ");
    man->FinishNtuple(1);

    man->CreateNtuple("Scoring", "Scoring");
    man->CreateNtupleDColumn("fDep");
    man->FinishNtuple(2);
}

MyRunAction::~MyRunAction() = default;

void MyRunAction::BeginOfRunAction(const G4Run *aRun) {
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    G4int runNumber = aRun->GetRunID();
    std::stringstream strRunId;
    strRunId << runNumber;

    man->OpenFile("output" + strRunId.str() + ".root");
}

void MyRunAction::EndOfRunAction(const G4Run *aRun) {
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->Write();
    man->CloseFile();
}
