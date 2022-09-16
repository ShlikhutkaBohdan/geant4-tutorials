//
// Created by Boday Alfaro on 16.09.2022.
//

#ifndef SIMULATION_STEPPING_HH
#define SIMULATION_STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "construction.hh"
#include "event.hh"


class MySteppingAction: public G4UserSteppingAction {
public:
    MySteppingAction(MyEventAction *eventAction);
    ~MySteppingAction() override;

    void UserSteppingAction(const G4Step *step) override;

private:
    MyEventAction *fEventAction;
};


#endif //SIMULATION_STEPPING_HH
