/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Routing.cpp
 * Author: BrunoVinicius
 * 
 * Created on November 19, 2018, 11:43 PM
 */

#include "../../include/RSA/Routing.h"
#include "../../include/RSA/Route.h"
#include "../../include/Structure/Topology.h"
#include "../../include/Structure/Node.h"
#include "../../include/Structure/Link.h"
#include "../../include/RSA/RSA.h"
#include "../../include/GeneralClasses/Def.h"
#include "../../include/Calls/Call.h"

Routing::Routing() {
}

Routing::Routing(const Routing& orig) {
}

Routing::~Routing() {
}

void Routing::Dijkstra() {
    std::shared_ptr<Route> route;
    unsigned int numNodes = this->topology->GetNumNodes();
    
    for(unsigned int orN = 0; orN < numNodes; orN++){
        for(unsigned int deN = 0; deN < numNodes; deN++){
            if(orN != deN){
                route = this->Dijkstra(orN, deN);
            }
            else{
                route = nullptr;
            }
            this->rsaAlgorithm->SetRoute(orN, deN, route);
        }
    }
}

void Routing::Dijkstra(Call* call) {
    unsigned int orNode = call->GetOrNode()->GetNodeId();
    unsigned int deNode = call->GetDeNode()->GetNodeId();
    
    call->PushTrialRoute(this->rsaAlgorithm->GetRoutes(orNode, deNode).front());
}

std::shared_ptr<Route> Routing::Dijkstra(unsigned int orNode, 
unsigned int deNode) {
    int k=-1, h, hops;
    unsigned int i, j, VA;
    long double min;
    unsigned int numNodes = this->topology->GetNumNodes();
    std::vector<int> r;
    Link *link;
    std::shared_ptr<Route> routeDJK;
    
    double *CustoVertice = new double[numNodes];
    int *Precedente = new int[numNodes];
    int *PathRev = new int[numNodes];
    bool *Status = new bool[numNodes];
    assert(orNode != deNode);
    bool networkDisconnected = false;

    //Initializes all vertices with infinite cost
    //and the source vertice with cost zero
    for(i = 0; i < numNodes; i++){
        if(i != orNode)
            CustoVertice[i] = Def::Max_Double;
        else
            CustoVertice[i] = 0.0;
        
        Precedente[i] = -1;
        Status[i] = 0;
    }
    VA = numNodes;

    while(VA > 0 && !networkDisconnected){

        min = Def::Max_Double;
        
        for(i = 0; i < numNodes; i++)
            if((Status[i] == 0) && (CustoVertice[i] < min)){
                min = CustoVertice[i];
                k = i;
            }

        if(k == (int) deNode)
            break;
        
        Status[k] = 1;
        VA = VA - 1;
        bool outputLinkFound = false;

        for(j = 0; j < numNodes; j++){
            link = this->topology->GetLink((unsigned int) k, 
                                           (unsigned int) j);

            if((link != NULL) && 
               (link->GetCost() < Def::Max_Double) && 
               (this->topology->GetNode(link->GetOrigimNode())->
               IsNodeWorking()) &&
               (this->topology->GetNode(link->GetDestinationNode())->
               IsNodeWorking())){
                outputLinkFound = true;

                if((Status[j] == 0) && 
                   (CustoVertice[k] + link->GetCost() < CustoVertice[j])){
                    CustoVertice[j] = CustoVertice[k] + link->GetCost();
                    Precedente[j] = k;
                }
            }
        }
        
        if(!outputLinkFound)
            networkDisconnected = true;
    }//Fim do while

    if(!networkDisconnected){
        PathRev[0] = deNode;
        hops = 0;
        j = deNode;
        
        while(j != orNode){
            hops = hops + 1;
            PathRev[hops] = Precedente[j];
            j = Precedente[j];
        }
        r.clear();
        
        for(h = 0; h <= hops; h++)
            r.push_back(PathRev[hops-h]);
        
        routeDJK = std::make_shared<Route>(this->GetRsaAlgorithm(), r);
    }

    delete []CustoVertice; delete []Precedente; 
    delete []Status; delete []PathRev;
    
    return routeDJK;
}

RSA* Routing::GetRsaAlgorithm() const {
    return rsaAlgorithm;
}

void Routing::SetRsaAlgorithm(RSA* rsaAlgorithm) {
    this->rsaAlgorithm = rsaAlgorithm;
}

Topology* Routing::GetTopology() const {
    return topology;
}

void Routing::SetTopology(Topology* topology) {
    this->topology = topology;
}