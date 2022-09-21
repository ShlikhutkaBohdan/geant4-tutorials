//
// Created by Boday Alfaro on 12.09.2022.
//

#ifndef SIMULATION_PHYSICS_HH
#define SIMULATION_PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"

class MyPhysicsList : public G4VModularPhysicsList {
public:
    MyPhysicsList();
    ~MyPhysicsList() override;
};


#endif //SIMULATION_PHYSICS_HH
