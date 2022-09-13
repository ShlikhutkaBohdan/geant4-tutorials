//
// Created by Boday Alfaro on 13.09.2022.
//

#include "action.hh"
#include "generator.hh"

MyActionInitialization::MyActionInitialization() = default;

MyActionInitialization::~MyActionInitialization() = default;

void MyActionInitialization::Build() const {
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);
}
