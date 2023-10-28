#include <fstream>
#include <iostream>
// #include <vector>
#include <bits/stdc++.h>
#include <random>
#include <algorithm>
// #include <ctime>
#include <chrono>
#include <set>

#define now() std::chrono::high_resolution_clock::now()
#define duration(stop, start) std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

using namespace std;

#include "SportsLayout.h"

SportsLayout::SportsLayout(string inputfilename)
{

    readInInputFile(inputfilename);
    mapping = new int[z];
}

bool SportsLayout::check_output_format()
{

    vector<bool> visited(l, false);
    for (int i = 0; i < z; i++)
    {
        if ((mapping[i] >= 1 && mapping[i] <= l))
        {
            if (!visited[mapping[i] - 1])
                visited[mapping[i] - 1] = true;
            else
            {
                cout << "Repeated locations, check format\n";
                return false;
            }
        }
        else
        {
            cout << "Invalid location, check format\n";
            return false;
        }
    }

    return true;
}

// void SportsLayout::readOutputFile(string output_filename)
// {
//         fstream ipfile;
//         ipfile.open(output_filename, ios::in);
//         if (!ipfile) {
//             cout << "No such file\n";
//             exit( 0 );
//         }
//         else {

//             vector<int> ip;

//             while (1) {
//                 int t;
//                 ipfile >> t;
//                 ip.push_back(t);
//                 if (ipfile.eof())
//                     break;

//             }

//         if(ip.size()!=z)
//         {
//             cout<<"number of values not equal to number of zones, check output format\n";
//             exit(0);
//         }
//         for(int i=0;i<z;i++)
//         mapping[i]=ip[i];
//     ipfile.close();

//     if(!check_output_format())
//         exit(0);
//     cout<<"Read output file, format OK"<<endl;

//         }

// }

long long SportsLayout::cost_fn()
{

    long long cost = 0;

    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < z; j++)
        {
            cost += (long long)N[i][j] * (long long)T[mapping[i] - 1][mapping[j] - 1];
        }
    }

    return cost;
}

void SportsLayout::readInInputFile(string inputfilename)
{
    fstream ipfile;
    ipfile.open(inputfilename, ios::in);
    if (!ipfile)
    {
        cout << "No such file\n";
        exit(0);
    }
    else
    {

        ipfile >> time;
        ipfile >> z;
        ipfile >> l;

        if (z > l)
        {
            cout << "Number of zones more than locations, check format of input file\n";
            exit(0);
        }

        int **tempT;
        int **tempN;

        tempT = new int *[l];
        for (int i = 0; i < l; ++i)
            tempT[i] = new int[l];

        tempN = new int *[z];
        for (int i = 0; i < z; ++i)
            tempN[i] = new int[z];

        for (int i = 0; i < z; i++)
        {
            for (int j = 0; j < z; j++)
                ipfile >> tempN[i][j];
        }

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++)
                ipfile >> tempT[i][j];
        }

        ipfile.close();

        T = tempT;
        N = tempN;
    }
}

void SportsLayout::write_to_file(string outputfilename)
{

    // Open the file for writing
    ofstream outputFile(outputfilename);

    // Check if the file is opened successfully
    if (!outputFile.is_open())
    {
        cerr << "Failed to open the file for writing." << std::endl;
        exit(0);
    }

    for (int i = 0; i < z; i++)
        outputFile << mapping[i] << " ";

    // Close the file
    outputFile.close();

    cout << "Allocation written to the file successfully." << endl;
}

// Returns a random mapping of the z zones to location
int *SportsLayout::random_mapping()
{
    int *new_array = new int[z];
    std::vector<int> sequence;
    for (int i = 1; i <= l; ++i)
    {
        sequence.push_back(i);
    }
    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(sequence.begin(), sequence.end(), gen);
    for (int i = 0; i < z; ++i)
    {
        new_array[i] = sequence[i];
    }
    return new_array;
}
/*
// Finds the zl neighbours of any state
void SportsLayout::neighbours(int *current_mapping, vector<int *> &neighbours_list)
{

    for (int i = 0; i < z; i++)
    {
        for (int j = i; j < z; j++)
        {
            int *new_array = new int[z]; // This gives BT I think
            for (int k = 0; k < z; k++)
            {
                new_array[k] = current_mapping[k];
            }
            int temp = new_array[i];
            new_array[i] = new_array[j];
            new_array[j] = temp;
            neighbours_list.push_back(new_array);
        }
    }

    vector<int> mapping_locations;
    for (int i = 0; i < z; i++)
    {
        mapping_locations.push_back(current_mapping[i]);
    }
    sort(mapping_locations.begin(), mapping_locations.end());

    vector<int> unvisited_locations;

    int expected = 1; // The expected value to find in the vector
    for (int num : mapping_locations)
    {
        if (num == expected)
        {
            expected++;
        }
        else if (num > expected)
        {
            while (expected < num)
            {
                unvisited_locations.push_back(expected);
                expected++;
            }
            expected = num + 1;
        }
    }
    while (expected <= l)
    {
        unvisited_locations.push_back(expected);
        expected++;
    }
    // for (int i = 0; i<unvisited_locations.size();i++){
    //     cout<<unvisited_locations[i]<<" ";
    // }
    for (int i = 0; i < unvisited_locations.size(); i++)
    {
        for (int j = 0; j < z; j++)
        {
            int *new_array = new int[z];
            for (int k = 0; k < z; k++)
            {
                new_array[k] = current_mapping[k];
            }
            new_array[j] = unvisited_locations[i];
            neighbours_list.push_back(new_array);
        }
    }
}
*/
// Calculates the cost of the mapping with a particular neighbour
long long SportsLayout::neighbour_cost_fn(int *current_mapping)
{

    long long cost = 0;

    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < z; j++)
        {
            cost += (long long)N[i][j] * (long long)T[current_mapping[i] - 1][current_mapping[j] - 1];
        }
    }

    return cost;
}

int *SportsLayout::opt_neighbour(int *current_mapping, long long *opt, int current_cost)
{
    // Checking new locations first
    // Creating a set of unvisited locations
    set<int> unvisited;
    for (int i = 1; i <= l; i++)
        unvisited.insert(i); // O(l)
    for (int i = 0; i < z; i++)
    {
        if ((unvisited.find(current_mapping[i]) != unvisited.end()))
            unvisited.erase(current_mapping[i]); // O(z)
    }

    // Now iterating in O(z^2(l-z))
    long long opt_val = current_cost;
    int optneighbour[z];
    int newneighbour[z];

    // Can't just equate the pointers! Both will get changed

    for (int i = 0; i < z; i++)
        newneighbour[i] = current_mapping[i];
    
    for (auto newelement : unvisited)
    {
        for (int k = 0; k < z; k++)
        {

            newneighbour[k] = newelement;
            long long neighbour_cost = current_cost;
            for (int i = 0; i < z; i++)
            {
                neighbour_cost += (long long)N[i][k] * ((long long)T[newneighbour[i] - 1][newneighbour[k] - 1] - (long long)T[current_mapping[i] - 1][current_mapping[k] - 1]) + (long long)N[k][i] * ((long long)T[newneighbour[k] - 1][newneighbour[i] - 1] - (long long)T[current_mapping[k] - 1][current_mapping[i] - 1]);
            }
            // cout<<((neighbour_cost==neighbour_cost_fn(newneighbour))? "Yes":"No")<<endl;
            if (neighbour_cost < opt_val)
            {
                opt_val = neighbour_cost;
                for (int i = 0; i < z; i++)
                    optneighbour[i] = newneighbour[i];
            }
            newneighbour[k] = current_mapping[k];
        }
    }
    // cout<<"Newloc\n";
    // for(int i=0; i<3; i++){cout<<optneighbour[i]<<" ";}
    // cout<<endl;
    // Now checking for swaps
    // Intermediate hybrid!
    int intermediateneighbour[z];
    for (int i = 0; i < z; i++)
        intermediateneighbour[i] = current_mapping[i];
    
    for (int k = 0; k < z; k++)
    {
        for (int l = k+1; l < z; l++)
        {
            intermediateneighbour[k]=current_mapping[l];
    //         for(int i=0; i<3; i++){cout<<intermediateneighbour[i]<<" ";}
    // cout<<endl;
            newneighbour[k]= current_mapping[l];
            newneighbour[l]= current_mapping[k];
    //         for(int i=0; i<3; i++){cout<<newneighbour[i]<<" ";}
    // cout<<endl;
            long long neighbour_cost = current_cost;
            // neighbour_cost=neighbour_cost_fn(newneighbour);
            for (int i = 0; i < z; i++)
            {
                neighbour_cost += (long long)N[i][k] * ((long long)T[intermediateneighbour[i] - 1][intermediateneighbour[k] - 1] - (long long)T[current_mapping[i] - 1][current_mapping[k] - 1]) + (long long)N[k][i] * ((long long)T[intermediateneighbour[k] - 1][intermediateneighbour[i] - 1] - (long long)T[current_mapping[k] - 1][current_mapping[i] - 1]);
                neighbour_cost += (long long)N[i][l] * ((long long)T[newneighbour[i] - 1][newneighbour[l] - 1] - (long long)T[intermediateneighbour[i] - 1][intermediateneighbour[l] - 1]) + (long long)N[l][i] * ((long long)T[newneighbour[l] - 1][newneighbour[i] - 1] - (long long)T[intermediateneighbour[l] - 1][intermediateneighbour[i] - 1]);
            }
            // cout<<((neighbour_cost==neighbour_cost_fn(newneighbour))? "Yes":"No")<<endl;
            if (neighbour_cost < opt_val)
            {
                opt_val = neighbour_cost;
                for (int i = 0; i < z; i++)
                    optneighbour[i] = newneighbour[i];
            }
            intermediateneighbour[k]=current_mapping[k];
            newneighbour[k]= current_mapping[k];
            newneighbour[l]= current_mapping[l];
        }
        

    }

    //TRANSFER OPTNEIGHBOUR TO HEAP
    int * optneighbourheap = new int[z];
    for (int i = 0; i < z; i++)
        optneighbourheap[i] = optneighbour[i];
    
    //GIVE COST BY USING A POINTER
    *opt=opt_val;
    return optneighbourheap;
}

int *SportsLayout::greedy_hill_climbing(int *old_mapping, int max_iterations, long long* value)
{
    int *current_mapping = old_mapping;
    long long current_value = neighbour_cost_fn(current_mapping);

    for (int i = 0; i < max_iterations; i++)
    {
        long long best_neighbour_value;
        int* best_neighbour = SportsLayout::opt_neighbour(current_mapping, &best_neighbour_value, current_value);

        if (best_neighbour == nullptr) {
            // Handle allocation failure, e.g., by exiting the loop or returning an error value.
            break;
        }

        if (best_neighbour_value >= current_value)
        {
            delete[] best_neighbour; // Don't forget to free the memory
            break;
        }

        delete[] current_mapping; // Use delete[] for arrays
        current_mapping = best_neighbour;
        current_value = best_neighbour_value;
    }

    // cout << current_value << endl;
    *value = current_value;
    return current_mapping;
}


int *SportsLayout::random_restart_greedy_hill_climbing(int max_restarts, int max_iterations)
{
    int *best_mapping = new int[z];
    int best_value = INT_MAX;

    auto initialTime = now();
    int maxtimegap = 0;
    int oldtime = 0;
    // for (int i = 0; i <= max_restarts; i++)
    while (1)
    {
        int *current_mapping = random_mapping();
        long long value;
        int *mapping = greedy_hill_climbing(current_mapping, max_iterations,&value);
        // int value = neighbour_cost_fn(mapping); // THIS IS WRONG IT RETURNS LONG LONG
        if (value < best_value)
        {
            delete[] best_mapping;
            best_mapping = mapping;
            best_value = value;
        }
        cout<<(long long)best_value<<endl;
        auto finalTime = now();
        auto d = duration(finalTime, initialTime);
        maxtimegap = std::max(maxtimegap, int(d.count()) - oldtime);
        oldtime = d.count();
        // Using 0.1 seconds -- divide by 10^5
        //  cout<<"timegap "<<maxtimegap/100000.0<<endl;

        // cout<<(d.count()/100000.0)<<endl;
        if ((double(d.count()) / 100000.0) >= (600.0 * time - maxtimegap / 100000.0))
            break;
    }
    return best_mapping;
}



void SportsLayout::compute_allocation()
{
    // you can write your code here
    // comment out following dummy code
    //  int* initial_mapping = new int[z];
    //  for(int i=0;i<z;i++){
    //  initial_mapping[i]=i+1;
    //  }
    auto initialTime = now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(initialTime);

    // cout<<"Hi"<<endl;
    // Print the current time as a string
    // std::cout << "Current time: " << std::ctime(&currentTime);
    mapping = random_restart_greedy_hill_climbing(1000, 100000);
    for (int i = 0; i < z; i++)
    {
        std::cout << mapping[i] << " ";
    }
    std::cout << std::endl;
    auto finalTime = now();
    // currentTime = std::chrono::system_clock::to_time_t(finalTime);
    // std::cout << "Final time: " << std::ctime(&currentTime);
}
