#!/bin/bash
#
# PROFILE_TREE

# Ensure that we have binaries
make clean && make all

TREE_TRAVERSER_FILE=tree_traverser.massif
valgrind --tool=massif --massif-out-file=$TREE_TRAVERSER_FILE ./bin/tree_traverser

LC_TREE_TRAVERSER_FILE=lc_tree_traverser.massif
valgrind --tool=massif --massif-out-file=$LC_TREE_TRAVERSER_FILE ./bin/lc_tree_traverser
