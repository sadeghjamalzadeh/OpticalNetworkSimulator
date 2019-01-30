/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laser.cpp
 * Author: BrunoVinicius
 * 
 * Created on January 28, 2019, 11:59 PM
 */

#include <cassert>

#include "../../../include/Structure/Devices/Laser.h"

Laser::Laser(SBVT* sbvt):
sbvt(sbvt), state(false), frequency(0.0) {

}

Laser::~Laser() {
    
}

void Laser::Initialize() {
    this->state = false;
    this->frequency = 0.0;
}

bool Laser::IsLaserOn() const {
    return state;
}

void Laser::SetLaserOn() {
    assert(this->state == false);
    
    this->state = true;
}

void Laser::SetLaserOff() {
    assert(this->state == true);
    
    this->state = false;
}

double Laser::GetFrequency() const {
    return frequency;
}

void Laser::SetFrequency(double frequency) {
    assert(frequency >= 0.0);
    
    this->frequency = frequency;
}
