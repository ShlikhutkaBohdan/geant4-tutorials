//
// Created by Boday Alfaro on 16.09.2022.
//

#include "stepping.hh"
#include "G4RunManager.hh"

MySteppingAction::MySteppingAction(MyEventAction *eventAction) {
    fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction() {

}

void MySteppingAction::UserSteppingAction(const G4Step *step) {

    G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

    const MyDetectorConstruction *detectorConstruction = static_cast<const
            MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();

    if (volume != fScoringVolume)
        return;

    G4double edep = step->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);
}
