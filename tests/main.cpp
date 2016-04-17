/*
 * main.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: asm
 */
#include <iostream>
#include <string.h>
#include "../headers/data-structures.hpp"
#include <cppunit/TestResult.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestSuccessListener.h>
#include <cppunit/TextTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include "data-structures-test.hpp"

using namespace std;

int main(int argc, char *argv[]){
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    CppUnit::TestResult controller;
    CppUnit::BriefTestProgressListener progress;
    controller.addListener(&progress);

    runner.addTest( registry.makeTest() );
    if((argc == 2) && (strcmp(argv[1],"brief") == 0)){
        runner.run(controller);
    }else{
        runner.run();
    }

    return 0;
}



