/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TSA.h
 * Author: BrunoVinicius
 *
 * Created on January 23, 2019, 4:57 PM
 */

#ifndef TSA_H
#define TSA_H

class ResourceAlloc;
class Topology;
class Call;

#include "SA.h"

class TSA : public SA {

public:
    
    TSA(ResourceAlloc* rsa, SpectrumAllocationOption option, 
        Topology* topology);
    
    TSA(const TSA& orig);
    
    virtual ~TSA();
    
    
    void Random(Call* call) override;
    
    void FirstFit(Call* call) override;

private:

};

#endif /* TSA_H */

