/* 
 * TREE_TRAVERSER
 * Program that traverses a simple tree. 
 * The point of this is to run the memory profiler and see how bad
 * the memory usage is.
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <getopt.h>
// Modules
#include "tree.hpp"
#include "tree_traverse.hpp"



int main(int argc, char *argv[])
{
    // TODO : accept a tree from the command line?
    //AsmOpts opts;
    const char* const short_opts = "v";
    const option long_opts[] = {};
    int argn = 0;
    int status;

    //init_opts(opts);

    // get args 
    //while(1)
    //{
    //    const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);
    //    if(opt == -1)
    //        break;

    //    switch(opt)
    //    {
    //        case 'v':
    //            opts.verbose = true;
    //            break;

    //        case 'i':
    //            opts.infile = std::string(optarg);
    //            break;

    //        case 'o':
    //            opts.outfile = std::string(optarg);
    //            break;

    //        //case 's':
    //        //    opts.dump_asm = true;
    //        //    break;

    //        //case 'S':
    //        //    opts.asm_file = std::string(optarg);
    //        //    break;

    //        case 'h':
    //            std::cout << "TODO : write help text and print here" << std::endl;
    //            break;

    //        default:
    //            std::cerr << "Unknown option " << std::string(optarg) << "(arg " << argn << ")" << std::endl;
    //            exit(-1);
    //            break;
    //    }
    //    argn++;
    //}


    TreeNode* tree = nullptr;
    std::string repr = "[1,2,3]";
    std::vector<int> traversal;

    tree = repr_to_tree(repr);
    if(tree == nullptr)
    {
        std::cout << "[" << __func__ << "] failed to create tree from repr " << repr << std::endl;
        return -1;
    }

    std::cout << "Performing in-order traversal" << std::endl;
    tree_inorder(tree, traversal);
    std::cout << "traversal contains " << traversal.size() << " nodes" << std::endl;
    std::cout << "[";
    for(unsigned int i = 0; i < traversal.size(); ++i)
        std::cout << traversal[i] << " ";
    std::cout << "]" << std::endl << std::endl;

    return 0;
}
