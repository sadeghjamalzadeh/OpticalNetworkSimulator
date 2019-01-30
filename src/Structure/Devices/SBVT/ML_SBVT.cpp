/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ML_SBVT.cpp
 * Author: BrunoVinicius
 * 
 * Created on January 29, 2019, 3:05 PM
 */

#include "../../../../include/Structure/Devices/SBVT/ML_SBVT.h"
#include "../../../../include/Structure/Devices/Laser.h"

ML_SBVT::ML_SBVT(Node* node):SBVT(node), 
lasers(this->GetNumberCarriers(), std::make_shared<Laser>(this)) {
    
}

ML_SBVT::~ML_SBVT() {

}

void ML_SBVT::Initialize() {
    
    for(auto it : this->lasers){
        it->Initialize();
    }
    
    SBVT::Initialize();
}
