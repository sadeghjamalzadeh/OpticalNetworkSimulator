/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ML_SBVT.h
 * Author: BrunoVinicius
 *
 * Created on January 29, 2019, 3:05 PM
 */

#ifndef ML_SBVT_H
#define ML_SBVT_H

#include <memory>

class Laser;

#include "../SBVT.h"

class ML_SBVT : public SBVT {

public:
    
    ML_SBVT(Node* node);
    
    virtual ~ML_SBVT();

    
    void Initialize() override;

private:
    
    std::vector<std::shared_ptr<Laser>> lasers;
};

#endif /* ML_SBVT_H */

