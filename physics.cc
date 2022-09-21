//
// Created by Boday Alfaro on 12.09.2022.
//

#include "physics.hh"

MyPhysicsList::MyPhysicsList() {
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4OpticalPhysics());
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4RadioactiveDecayPhysics());
}

MyPhysicsList::~MyPhysicsList() {}