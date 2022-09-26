//
// Created by Boday Alfaro on 13.09.2022.
//

#include "G4SystemOfUnits.hh"
#include "detector.hh"
#include "g4root.hh"
#include "G4RunManager.hh"

MySensitiveDetector::MySensitiveDetector(const G4String &name) : G4VSensitiveDetector(name) {}

MySensitiveDetector::~MySensitiveDetector() {

}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist) {
    G4Track *track = aStep->GetTrack();
    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

    G4ThreeVector posPhoton = preStepPoint->GetPosition();
    G4ThreeVector momPhoton = preStepPoint->GetMomentum();

    G4double wlen = (1.239841939*eV/momPhoton.mag())*1E+03;

//    G4cout << "Photon position" << posPhoton << G4endl;
    const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

    G4int copyNo = touchable->GetCopyNumber();

//    G4cout << "Copy number: " << copyNo << G4endl;

    G4VPhysicalVolume *physVol = touchable->GetVolume();

    const G4ThreeVector &posDetector = physVol->GetTranslation();

#ifndef G4MULTITHREADED
    G4cout << "Detector position: " << posDetector << G4endl;
#endif


    G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->FillNtupleIColumn(0, 0, evt);
    man->FillNtupleDColumn(0, 1, posDetector[0]);
    man->FillNtupleDColumn(0, 2, posDetector[1]);
    man->FillNtupleDColumn(0,3, posDetector[2]);
    man->FillNtupleDColumn(0,4, wlen);

    man->FillNtupleIColumn(1, 0, evt);
    man->FillNtupleDColumn(1, 1, posDetector[0]);
    man->FillNtupleDColumn(1, 2, posDetector[1]);
    man->FillNtupleDColumn(1,3, posDetector[2]);

    man->AddNtupleRow(0);
}
