/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MultiNumSbvtSimulation.cpp
 * Author: BrunoVinicius
 * 
 * Created on January 21, 2019, 9:55 PM
 */

#include <vector>

#include "../../include/SimulationType/MultiNumSbvtSimulation.h"
#include "../../include/Data/Parameters.h"
#include "../../include/Calls/CallGenerator.h"
#include "../../include/Structure/Topology.h"
#include "../../include/Data/InputOutput.h"

MultiNumSbvtSimulation::MultiNumSbvtSimulation(unsigned int simulIndex)
:SimulationType(simulIndex) {
    
}

MultiNumSbvtSimulation::~MultiNumSbvtSimulation() {
    
}

void MultiNumSbvtSimulation::Run() {
    const double loadPoint = this->GetParameters()->GetLoadPoint().front();
    this->GetCallGenerator()->SetNetworkLoad(loadPoint);
    
    unsigned int minNumTransPerNode = 10;
    unsigned int maxNumTransPerNode = 100;
    
    for(unsigned int a = minNumTransPerNode; a <= maxNumTransPerNode; a += 10){
        this->GetInputOutput()->PrintProgressBar(a, minNumTransPerNode, 
                                                 maxNumTransPerNode);
        this->GetTopology()->SetNumberDevicesPerNode(a);
        
        SimulationType::Run();
        
        std::cout << this->GetData() << std::endl;
    }
    
    this->GetInputOutput()->PrintProgressBar(maxNumTransPerNode, 
                                             maxNumTransPerNode);
}

void MultiNumSbvtSimulation::Print() {
    this->Help();
    SimulationType::Print();
}

void MultiNumSbvtSimulation::Save() {
    SimulationType::Save();
}

void MultiNumSbvtSimulation::Help() {
    std::cout << "MULTIPLE NUMBER OF TRANSPONDERS SIMULATION" << std::endl
              << "This type of simulation increments the number of transponder "
              << "per node and analyzes the network performance. "
              << std::endl << std::endl;
}
