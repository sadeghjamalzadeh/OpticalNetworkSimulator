/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MultiNumSbvtSimulation.h
 * Author: BrunoVinicius
 *
 * Created on January 21, 2019, 9:55 PM
 */

#ifndef MULTINUMSBVTSIMULATION_H
#define MULTINUMSBVTSIMULATION_H

#include "SimulationType.h"

#include <iostream>

class MultiNumSbvtSimulation : public SimulationType {

public:
    
    MultiNumSbvtSimulation(unsigned int simulIndex);
    
    MultiNumSbvtSimulation(const MultiNumSbvtSimulation& orig);
    
    virtual ~MultiNumSbvtSimulation();
    
    
    /**
     * @brief Runs a simulation with specified parameters.
     */
    void Run() override;
    /**
     * @brief Print this simulation in terminal.
     */
    void Print() override;
    /**
     * @brief Save the results in .txt files.
     */
    void Save() override;
    /**
     * @brief Prints a description of the simulation.
     */
    void Help() override;
    
private:

};

#endif /* MULTINUMSBVTSIMULATION_H */

