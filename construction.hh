#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "detector.hh"
#include "G4GenericMessenger.hh"

class MyDetectorConstruction: public G4VUserDetectorConstruction 
{
public:
  MyDetectorConstruction();
  ~MyDetectorConstruction() override;

  G4LogicalVolume *GetScoringVolume() const {
      return fScoringVolume;
  }

  G4VPhysicalVolume *Construct() override;

private:
    void ConstructSDandField() override;

    G4GenericMessenger *fMessenger;

    G4int nCols, nRows;

    G4Box *solidWorld, *solidRadiator, *solidDetector;
    G4LogicalVolume *logicWorld, *logicRadiator, *logicDetector;

    G4VPhysicalVolume *physWorld, *physRadiator, *physDetector;

    G4Material *SiO2, *H2O, *Aerogel, *worldMat;
    G4Element *C;

    G4LogicalVolume *fScoringVolume;

    void DefineMaterials();
};

#endif
