/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MW_SBVT.h
 * Author: BrunoVinicius
 *
 * Created on January 29, 2019, 11:20 PM
 */

#ifndef MW_SBVT_H
#define MW_SBVT_H

#include <memory>

class Laser;

#include "../SBVT.h"

class MW_SBVT : public SBVT {

public:
    
    MW_SBVT(Node* node);
    
    virtual ~MW_SBVT();
    
    
    void Initialize() override;

private:
    
    std::shared_ptr<Laser> laser;
};

#endif /* MW_SBVT_H */

