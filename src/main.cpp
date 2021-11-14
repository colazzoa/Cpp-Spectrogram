#include <iostream>
#include "ctrlApp.hpp"

int main(int argc, char *argv[])
{
    ColourManager::Init_ColourManager(); 

    ColourMap M = CMList::getMapList(CMClassification::DIVERGING)[3];

    ColourManager::setCurrentColourMap(M);

    ctrlApp app;

    app.run();
}

