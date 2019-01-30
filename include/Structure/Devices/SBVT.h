/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SBVT.h
 * Author: BrunoVinicius
 *
 * Created on January 20, 2019, 11:57 PM
 */

#ifndef SBVT_H
#define SBVT_H

#include <vector>

class Node;

class SBVT {

public:
    
    SBVT(Node* node);
    
    virtual ~SBVT();
    
    
    virtual void Initialize();
    
    
    const unsigned int GetNumberCarriers() const;

private:
    
    Node* node;
    
    bool state;
    
    const unsigned int numberCarriers = 3;
    
    std::vector<bool> carriersState;
    
    std::vector<double> centralFrequencies;
};

#endif /* SBVT_H */
