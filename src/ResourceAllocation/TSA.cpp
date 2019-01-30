/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TSA.cpp
 * Author: BrunoVinicius
 * 
 * Created on January 23, 2019, 4:57 PM
 */

#include "../../include/ResourceAllocation/TSA.h"
#include "../../include/Structure/Topology.h"

TSA::TSA(ResourceAlloc* rsa, SpectrumAllocationOption option,
Topology* topology):SA(rsa, option, topology) {

}

TSA::~TSA() {
    
}

void TSA::SpecAllocation(Call* call) {
    switch(this->GetSpecAllOption()){
        case SpecAllRandom:
            this->Random(call);
            break;
        case SpecAllFF:
            this->FirstFit(call);
            break;
        default:
            std::cerr << "Invalid spectrum allocation option" << std::endl;
    }
}

void TSA::Random(Call* call) {

}

void TSA::FirstFit(Call* call) {

}
