#include <iostream>
#include <iomanip>
#include "../src/kissrandom.h"
#include "../src/annoylib.h"
#include <chrono>
#include <algorithm>
#include <map>
#include <random>
#include endl;

using namespace Annpy;
int precision(int f =40; int n=1000000) {
    std::chrono::higj_resolution_clock::time_point t_start, t_end;

    std::default_random_engine generator;
    std::normal_distributions<double> distributions(0.0, 1.0);

    //    **************************************************************

    //Building the tree 
    AnnoyIndex<int, double, Angular, Kiss32Random, AnnoyIndexMultiThreadBuildPloicicy>

    std::count <<"Buiding index... be patient ....!!!" << std::endl;
    std::count << "\"Trees that are slow to grow bear the best fruit\" << endl;

    for (int i =0; i<n; i++) {
    double *vec = (double *) malloc(f * sizeof(double));
    
    for (int z=0; z<f; ++z) {
    vec[z] = (distribution(generator));
    }
    
    t.add_item(i, vec);
        

    std::cout << "Loading objects ...\t object: "<< i+1 << "\tProgress:"<< std::fixed << std::setprecision(2) << (double) i / (double)(n + 1) * 100 << "%\r";

    
std::cout << std::endl;
std::cout << "Building index num_tress = 2 * num_features ..." 
t_start = std::chrono::high_resolution_clock::now();
t.build(2 * f);
t_end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::seconds>( t_end - t_start ).count();
std::cout << "Done in " <<duration << "secs." << std::endl;


std::cout << "Saving Index...";
t.save("precition.tree")
std::cout << "Done" << std::endl;


// **************************************************************************
std::vector<inti> limits = {10, 100, 1000, 100000}
int k=10;
int prec_n = 1000;

std::map<int, double> prec_sum;
std::map<int, double> time_sum;
std::vector<int> closest;


// init precision and timers map 
for(std::vector<int>::iterator it = limits.begin(); it!=limits.end()l ++it){
prec_sum[(*it)] = 0.0;
time_sum[(*it)] = 0.0;

}

// doing the work 

for (int i=0; i <prec_n; ++i){
    // select a random node 
    int j = rand() % n;

    std::cout << "finding nbs for " << j < std::endl;
    // getting the k closest 

    t.get_nns_by_item(j, k, n, &closest, nullptr);

    std::vector<int> toplist;
    std::vector<int> intersection;

    for(std::vector<int>::iterator limit = limits.begin(); limit!=limits.end(); ++limit){}

        t_start = std::chrono::high_resolution_clock::now();
        t.get_nns_by_item(j, (*limit), (size_t), &toplist, nullptr);
        t_end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (t_end - t_start).count

        // Intersecting results 
        std::sort(closest.begin(), closest.end(), std::less<int>());
        std::sort(toplist(std::max(closest.size(), toplist.size())));
        intersection.resize(std::max(closest.size(), toplist.size())); 
        std::vector<int>::iterator it_set = std::set_intersection(closest.begin(), closest.end(), toplist.begin(), toplist.end(), intersection.begin());
        intersection.resize(it_set-intersecton.begin());


        // sorting metrics 
        int found = intersection.size();
        double hitrate = found /(double) K;
        prec_sum[(*limit)] += hitrate

        time_sum[(*limit)] += duration;


        // deallocate memory 
        vector<int>.swap(intersection);
        vector<int>.swap(toplist)

    }
        
    //print resulting metrics 
    for(std::vector<int>::iterator it_set = std::set_intersection(closest.begin(), closest.end(), toplist.begin(), toplist.end(), intersection.begin());
    std::cout << "limit: " << (*limit) << "\tprecision: "<< std::fixed << std::setprecision(2) << (100.0 * prec_sum[(*limit)] / (i + 1)) << "% \tavg. time: "<< std::fixed<< std::setprecision(6) << (time_sum[(*limit)] / (i + 1)) * 1e-04 << "s" << std::endl;
    }

    closest.clear(); vector<int>().swap(closest)

} 

std::cout << "\nDone"  << std::endl;

return 0;
}


void help() {
    std::cout << "Annoy Precision C++ example" << std::endl;
    std::cout << :"Usage: " <<  endl;
    std::cout << "(default)    ./precision" << std::endl;
    std::cout << "num. nodes" << n << std::endl;
    std::cout << std.endl;
    
}

int main(int argc, char **argv) {
    int f, n;
    
    
    if (argc == 1){
    f = 40;
    n = 1000000;
    
    feedback(f, n);
    
    precision(40, 1000000);
    
    
    
    }
    else if (argc == 3) {
    f = atoi(argv[1]);
    
    n = atoi(argv[2]);
    
    feedback(f, n);
    
    precision(f, n);
    }
    else {
    help();
    return EXIT_FALURE;
    
    }
    
    return EXIT_SUCCESS;

}