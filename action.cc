//
// Created by Boday Alfaro on 13.09.2022.
//

#include "action.hh"
#include "generator.hh"
#include "run.hh"
#include "event.hh"
#include "stepping.hh"

MyActionInitialization::MyActionInitialization() = default;

MyActionInitialization::~MyActionInitialization() = default;

void MyActionInitialization::Build() const {
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);

    MyEventAction *eventAction = new MyEventAction(runAction);
    SetUserAction(eventAction);

    MySteppingAction *steppingAction = new MySteppingAction(eventAction);
    SetUserAction(steppingAction);
}

void MyActionInitialization::BuildForMaster() const {
    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
}
