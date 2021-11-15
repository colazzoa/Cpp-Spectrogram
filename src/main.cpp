#include <iostream>
#include "ctrlApp.hpp"

int main(int argc, char *argv[])
{
    //Setting up Colourmap using open source library Colourmanager
    ColourManager::Init_ColourManager();
    ColourMap M = CMList::getMapList(CMClassification::DIVERGING)[3];
    ColourManager::setCurrentColourMap(M);

    //Main application is defined inside ctrlApp class
    ctrlApp app;
    app.run();
}
