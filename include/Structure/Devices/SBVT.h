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

class Node;

#include <vector>


class SBVT {

public:
    
    SBVT(Node* node);
    
    virtual ~SBVT();
    
    
    virtual void Initialize();

private:
    
    Node* node;
    
    unsigned int numberCarriers;
    
    std::vector<bool> carriersState;
    
    std::vector<double> centralFrequencies;
};

#endif /* SBVT_H */

