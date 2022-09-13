//
// Created by Boday Alfaro on 13.09.2022.
//

#ifndef SIMULATION_GENERATOR_HH
#define SIMULATION_GENERATOR_HH

#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction {
public:
    MyPrimaryGenerator();

    ~MyPrimaryGenerator() override;

    void GeneratePrimaries(G4Event *anEvent) override;

private:
    G4ParticleGun *fParticleGun;
};


#endif //SIMULATION_GENERATOR_HH
