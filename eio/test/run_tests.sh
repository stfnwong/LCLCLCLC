#!/bin/bash
# Run all the tests in ./bin/tests

TEST_DIR="./bin/test"

for t in ${TEST_DIR}/*; do
    ./$t || rc=$?
    if [[ rc -ne 0 ]] ; then
        exit $rc
    fi
done
