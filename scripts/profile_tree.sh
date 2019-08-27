#!/bin/bash
#
# PROFILE_TREE

# Ensure that we have binaries
make clean && make all

TREE_TRAVERSER_FILE=tree_traverser
valgrind --tool=massif --massif-out-file=reports/$TREE_TRAVERSER_FILE.massif ./bin/tree_traverser

LC_TREE_TRAVERSER_FILE=lc_tree_traverser
valgrind --tool=massif --massif-out-file=reports/$LC_TREE_TRAVERSER_FILE.massif ./bin/lc_tree_traverser

# Dump reports to text file 
ms_print reports/$TREE_TRAVERSER_FILE.massif > reports/$TREE_TRAVERSER_FILE.txt 

ms_print reports/$LC_TREE_TRAVERSER_FILE.massif > reports/$LC_TREE_TRAVERSER_FILE.txt 
