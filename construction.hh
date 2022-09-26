#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4Tubs.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "detector.hh"
#include "G4GenericMessenger.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"

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

    G4double xWorld, yWorld, zWorld;

    G4bool isCherenkov, isScintillator;

    G4Box *solidWorld, *solidRadiator, *solidDetector, *solidScintillator;

    G4LogicalVolume *logicWorld, *logicRadiator, *logicDetector, *logicScintillator;

    G4VPhysicalVolume *physWorld, *physRadiator, *physDetector, *physScintillator;

    G4Material *SiO2, *H2O, *Aerogel, *worldMat, *NaI;
    G4Element *C, *Na, *I;

    G4LogicalVolume *fScoringVolume;

    G4OpticalSurface *mirrorSurface;

    void DefineMaterials();

    void ConstructCherenkov();
    void ConstructScintillator();
};

#endif
