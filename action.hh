//
// Created by Boday Alfaro on 13.09.2022.
//

#ifndef SIMULATION_ACTION_HH
#define SIMULATION_ACTION_HH

#include "G4VUserActionInitialization.hh"

class MyActionInitialization : public G4VUserActionInitialization {

public:
    MyActionInitialization();

    ~MyActionInitialization() override;

    void Build() const override;
};


#endif //SIMULATION_ACTION_HH
