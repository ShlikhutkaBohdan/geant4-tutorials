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

class MyDetectorConstruction: public G4VUserDetectorConstruction 
{
public:
  MyDetectorConstruction();
  ~MyDetectorConstruction() override;
  
  G4VPhysicalVolume *Construct() override;

private:
    G4LogicalVolume *logicDetector;
    void ConstructSDandField() override;
};

#endif
