
#ifndef SPORTSLAYOUT_H
#define	SPORTSLAYOUT_H

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SportsLayout{

    private:
    int z,l;
    int** T;
    int **N;
    float time;
    int *mapping;

    public:
    SportsLayout(string inputfilename);

    bool check_output_format();

    // void readOutputFile(string output_filename);
    
    long long cost_fn();

    void write_to_file(string outputfilename);

    void readInInputFile(string inputfilename);

    int* random_mapping();

    void neighbours(int *mapping, vector<int*>& neighbours_list);

    
    int* opt_neighbour(int *mapping, long long * opt, int current_cost);
    
    long long neighbour_cost_fn(int* current_mapping);

    int* greedy_hill_climbing(int *mapping, int max_iterations, long long* value);
    
    int* random_restart_greedy_hill_climbing(int max_restarts, int max_iterations);

    // int* simulated_annealing(int max_restarts, int max_iterations);
    
    void compute_allocation();


};


#endif
