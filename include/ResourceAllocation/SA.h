/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SA.h
 * Author: BrunoVinicius
 *
 * Created on November 22, 2018, 11:36 PM
 */

#ifndef SA_H
#define SA_H

#include <random>
#include <cstdlib>

class ResourceAlloc;
class Topology;
class Call;

#include "../Data/Options.h"

class SA {

public:
    
    SA(ResourceAlloc* rsa, SpectrumAllocationOption option, Topology* topology);
    
    virtual ~SA();
    
    
    void SpecAllocation(Call* call);
    
    virtual void Random(Call* call);
    
    virtual void FirstFit(Call* call);
    
    void MostUsed(Call* call);
    
    void LeastUsed(Call* call);
    
    void MaxSum(Call* call);
    
    void RCL(Call* call);
    
    void MSCL(Call* call);
    
    
    Topology* GetTopology() const;

private:
    
    ResourceAlloc* resourceAlloc;
    
    SpectrumAllocationOption specAllOption;
    
    Topology* topology;
};

#endif /* SA_H */

