/*
 * bit_graph.h
 * compressed representation of simple (undirected/unweighted) graph
 * for use in graph theory
 *
 *  Created on: May 24, 2016
 *      Author: Johnny Viel
 */
#pragma once
#include <vector>

class bit_graph {

private:
	int dimension;
	int numEdges;
	long int* adjacency;
	long int* incidence;
	//std::vector<long int> adjacency;


public:
	bit_graph();
	bit_graph( int dimension );
	bit_graph( const bit_graph &other );
	bit_graph& operator=( const bit_graph &other );
	~bit_graph();

	void gen_incidence();
	void permute();              // permutes matrix to next possible combination/# of edges
	void grow( int dimension );  // adds to dimensionality
	void print( std::ostream& out );
};



