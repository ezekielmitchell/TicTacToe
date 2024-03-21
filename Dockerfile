FROM ubuntu:latest

# Install C++ compiler and build tools
RUN apt-get update && apt-get install -y g++ make

# Set working directory
WORKDIR /tictactoe

# Add your C++ source file
COPY main.cpp /tictactoe

# Compile the C++ code
RUN g++ main.cpp -o main

# Define the command to run when the container starts
CMD ["./main"]
