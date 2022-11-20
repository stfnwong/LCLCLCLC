# TODOL: check that this is the minimal image
FROM ubuntu:20.04
# Update 
RUN apt-get -y update && apt-get install -y
# Install a compiler 
RUN apt-get -y install g++ make && mkdir -pv /usr/local/lc

# Copy the src and test dirs 
COPY . /usr/local/lc

# Where should we enter the container?
CMD ["make all", "./test/run_tests"]
