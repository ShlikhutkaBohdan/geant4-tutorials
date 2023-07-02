//
// Created by Boday Alfaro on 16.09.2022.
//

#ifndef SIMULATION_EVENT_HH
#define SIMULATION_EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

//#include "g4root.hh"
#include "G4AnalysisManager.hh"
#include "run.hh"

class MyEventAction : public G4UserEventAction {
public:
    explicit MyEventAction(MyRunAction *);

    void BeginOfEventAction(const G4Event *anEvent) override;

    void EndOfEventAction(const G4Event *anEvent) override;

    void AddEdep(G4double edep) { fEdep += edep; }
private:
    G4double fEdep;
};


#endif //SIMULATION_EVENT_HH
