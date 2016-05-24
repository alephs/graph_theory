/*
 * bit_graph.cpp
 *
 *  Created on: May 24, 2016
 *      Author: Johnny Viel
 */
#include <iostream>
#include "bit_graph.h"
using namespace std;

bit_graph::bit_graph()
{
	this->dimension = 1;
	this->numEdges  = 0;
	this->adjacency = new long int[1];
	this->incidence = nullptr;
}

bit_graph::bit_graph( int dim )
{
	this->dimension = dim;
	this->numEdges  = 0;
	this->adjacency = new long int[ (dim % 64 == 0 ? dim/64 : 1+dim/64) ];
	this->incidence = nullptr;
}

bit_graph::bit_graph( const bit_graph & other ): adjacency(nullptr),incidence(nullptr)
{
	*this = other;
}

bit_graph& bit_graph::operator=( const bit_graph & other )
{
	if( this != &other )
	{
		this->dimension = other.dimension;
		this->numEdges  = other.numEdges;
		if( other.adjacency != nullptr ){
			int adj_size = sizeof(other.adjacency/sizeof(long int));
			if( this->adjacency == nullptr )
				this->adjacency = new long int[ adj_size ];
			for( int i=0; i<adj_size; i++ )
				this->adjacency[i] = other.adjacency[i];
		}
		if( other.incidence != nullptr ){
			int inc_size = sizeof(other.incidence/sizeof(long int));
			if( this->incidence == nullptr )
				this->incidence = new long int[ inc_size ];
			for( int i=0; i<inc_size; i++ )
				this->incidence[i] = other.incidence[i];
		}
	}
	return *this;
}

bit_graph::~bit_graph()
{
}

void bit_graph::gen_incidence()
{
}

void bit_graph::permute()
{
	//increment members of adjacency in cascading fashion
	//check if connected
}

void bit_graph::grow( int dimension )
{
	this->dimension += dimension;
}

void bit_graph::print( ostream& out )
{

}
