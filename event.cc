//
// Created by Boday Alfaro on 16.09.2022.
//

#include "event.hh"

MyEventAction::MyEventAction(MyRunAction *) {
    fEdep = 0;
}

void MyEventAction::BeginOfEventAction(const G4Event *anEvent) {
    fEdep = 0;
}

void MyEventAction::EndOfEventAction(const G4Event *anEvent) {
    G4cout << "Energy disposition: " << fEdep << G4endl;
    G4AnalysisManager * man = G4AnalysisManager::Instance();
    man->FillNtupleDColumn(2, 0, fEdep);
    man->AddNtupleRow(2);
}
