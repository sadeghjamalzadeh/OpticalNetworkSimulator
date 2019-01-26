/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeSBVT.h
 * Author: BrunoVinicius
 *
 * Created on January 21, 2019, 6:13 PM
 */

#ifndef NODESBVT_H
#define NODESBVT_H

#include <vector>
#include <memory>

#include "../Node.h"

class Topology;
class SBVT;

class NodeSBVT : public Node {

public:
    
    NodeSBVT(Topology* topPointer,  NodeId nodeId);
    
    NodeSBVT(const NodeSBVT& orig);
    
    virtual ~NodeSBVT();
    
    
    void Initialize() override;
    
    void SetDevices(unsigned int numDevices) override;
    
    void Connect() override;
    
    void Desconnect() override;
    
    
    unsigned int GetNumberSBVT() const;

    void SetNumberSBVT(unsigned int numberSBVT);

private:
    
    void CreateDevices();
    
    void DeleteDevices();

private:
    
    unsigned int numberSBVT;
    
    std::vector<std::shared_ptr<SBVT>> SBVTs;
};

#endif /* NODESBVT_H */

