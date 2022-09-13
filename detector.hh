//
// Created by Boday Alfaro on 13.09.2022.
//

#ifndef SIMULATION_DETECTOR_HH
#define SIMULATION_DETECTOR_HH


#include "G4VSensitiveDetector.hh"

class MySensitiveDetector : public G4VSensitiveDetector{

public:
    explicit MySensitiveDetector(const G4String &name);

    ~MySensitiveDetector() override;

protected:
    G4bool ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist) override;

};


#endif //SIMULATION_DETECTOR_HH
