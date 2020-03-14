# LCLCLCLC
Leetcode. 

![A photo of me as I contribute to this repository](docs/images/lclclclc.jpeg)

## About
Leetcode. Its a veritable way of life. The measure by which a man's worth is judged. What is lifes purpose, if not to excel at Leetcode?


This repo contains experiments for leetcode problems. For whatever reason LC reports huge memory usage even for very simple things. The repo is just a random collection of answers to various questions, but without any real reference to the questions. Quite a lot of it is just profiling.

Also there are some C++ things that are just in there for language practice.

## Requirements 
- Tests use gtest (but I am moving them over to Catch2 because I can't be bothered setting up TravisCI to work with gtest).
- Valgrind (I used massif for heap profiling)
- I used GCC 9.1.1, but there aren't any special features that would require this version.

## Documentation
HA HA HA HA HA HA HA HA HA

## Tests
Test used gtest. Almost everything here is in C++ but sometimes I use Python (3.6). For many of the problems the unit test is in effect the output of the exercise. For those I just replicate the visible unit tests in the question and then paste the core logic into leetcode to see how it does on the hidden tests. 
