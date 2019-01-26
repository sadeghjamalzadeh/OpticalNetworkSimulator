/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CallDevices.h
 * Author: BrunoVinicius
 *
 * Created on January 24, 2019, 4:14 PM
 */

#ifndef CALLDEVICES_H
#define CALLDEVICES_H

class Node;
class SBVT;

#include "Call.h"
#include "CallGenerator.h"

class CallDevices : public Call {

public:
    
    CallDevices(Node* orNode, Node* deNode, double bitRate, TIME deacTime);
    
    CallDevices(const CallDevices& orig);
    
    virtual ~CallDevices();

private:
    
    SBVT* orSVBT;
    
    SBVT* deSBVT;
};

#endif /* CALLDEVICES_H */

