# TODOL: check that this is the minimal image
FROM ubuntu:20.04
# Update 
RUN apt-get -y update && apt-get install -y
# Install a compiler 
RUN apt-get -y install g++ make && mkdir -pv /usr/local/lc/{bin,obj}

# Copy the src and test dirs 
#COPY . /usr/local/lc
WORKDIR /usr/local/lc
COPY src .
COPY test .

# Make a new poetry env?

# Where should we enter the container?
CMD ["make clean", "make all", "./test/run_tests.sh"]

