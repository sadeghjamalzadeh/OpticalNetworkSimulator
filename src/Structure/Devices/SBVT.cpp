/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SBVT.cpp
 * Author: BrunoVinicius
 * 
 * Created on January 20, 2019, 11:57 PM
 */

#include "../../../include/Structure/Devices/SBVT.h"

SBVT::SBVT(Node* node)
:node(node), state(false), carriersState(0), 
centralFrequencies(0) {
    
}

SBVT::~SBVT() {

}

void SBVT::Initialize() {
    this->state = false;
    this->carriersState.assign(this->numberCarriers, false);
    this->centralFrequencies.assign(this->numberCarriers, 0.0);
}

const unsigned int SBVT::GetNumberCarriers() const {
    return numberCarriers;
}
