/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laser.h
 * Author: BrunoVinicius
 *
 * Created on January 28, 2019, 11:59 PM
 */

#ifndef LASER_H
#define LASER_H

class SBVT;

class Laser {

public:
    
    Laser(SBVT* sbvt);
    
    virtual ~Laser();
    
    
    void  Initialize();
    
    bool IsLaserOn() const;

    void SetLaserOn();
    
    void SetLaserOff();
    
    double GetFrequency() const;

    void SetFrequency(double frequency);


private:
    
    SBVT* sbvt;
    
    bool state;
    
    double frequency;
};

#endif /* LASER_H */

