/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeSBVT.cpp
 * Author: BrunoVinicius
 * 
 * Created on January 21, 2019, 6:13 PM
 */

#include "../../../include/Structure/Nodes/NodeSBVT.h"
#include "../../../include/Structure/Devices/SBVT.h"

NodeSBVT::NodeSBVT(Topology* topPointer,  NodeId nodeId)
:Node(topPointer, nodeId), numberSBVT(0), SBVTs(0) {
    
}

NodeSBVT::~NodeSBVT() {
    
}

void NodeSBVT::Initialize() {
    Node::Initialize();
    
    for(auto it : this->SBVTs){
        it->Initialize();
    }
}

void NodeSBVT::SetDevices(unsigned int numDevices) {
    this->SetNumberSBVT(numDevices);
}

void NodeSBVT::Connect() {
    Node::Connect();
}

void NodeSBVT::Desconnect() {
    Node::Desconnect();
}

unsigned int NodeSBVT::GetNumberSBVT() const {
    return numberSBVT;
}

void NodeSBVT::SetNumberSBVT(unsigned int numberSBVT) {
    unsigned int pastNumberSBVT = this->numberSBVT;
    this->numberSBVT = numberSBVT;
    
    if(pastNumberSBVT < this->numberSBVT)
        this->CreateDevices();
    else if(pastNumberSBVT > this->numberSBVT)
        this->DeleteDevices();
}

void NodeSBVT::CreateDevices() {
    
    while(this->SBVTs.size() < this->numberSBVT){
        this->SBVTs.push_back(std::make_shared<SBVT>(this));
    }
}

void NodeSBVT::DeleteDevices() {
    
    while(this->SBVTs.size() > this->numberSBVT){
        this->SBVTs.back().reset();
        this->SBVTs.pop_back();
    }
}
