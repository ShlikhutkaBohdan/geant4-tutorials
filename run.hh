//
// Created by Boday Alfaro on 14.09.2022.
//

#ifndef SIMULATION_RUN_HH
#define SIMULATION_RUN_HH

#include "G4UserRunAction.hh"

class MyRunAction : public G4UserRunAction {
public:
    MyRunAction();

    ~MyRunAction() override;

    void BeginOfRunAction(const G4Run *aRun) override;

    void EndOfRunAction(const G4Run *aRun) override;
};

#endif //SIMULATION_RUN_HH
