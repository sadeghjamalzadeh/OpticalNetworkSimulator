/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MW_SBVT.cpp
 * Author: BrunoVinicius
 * 
 * Created on January 29, 2019, 11:20 PM
 */

#include "../../../../include/Structure/Devices/SBVT/MW_SBVT.h"
#include "../../../../include/Structure/Devices/Laser.h"

MW_SBVT::MW_SBVT(Node* node):SBVT(node), 
laser(std::make_shared<Laser>(this)) {
    
}

MW_SBVT::~MW_SBVT() {
    
}

void MW_SBVT::Initialize() {
    this->laser->Initialize();
    
    SBVT::Initialize();
}
