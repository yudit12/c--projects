# Use the official GCC image as the base
FROM gcc:latest

# Install CMake, g++, gdb, and any other necessary dependencies
RUN apt-get update && \
    apt-get install -y cmake g++ gdb && \
    rm -rf /var/lib/apt/lists/*

# Set the C++ standard to C++17 with debugging symbols enabled
ENV CXXFLAGS="-std=c++17 -g"

# Install Google Test (GTest)
RUN git clone https://github.com/google/googletest.git /usr/src/gtest && \
    mkdir -p /usr/src/gtest/build && \
    cd /usr/src/gtest/build && \
    cmake .. && \
    cmake --build . && \
    cmake --install . --prefix /usr/local
    
# Set the working directory inside the container
WORKDIR /usr/src/app

# Check if the build directory exists and remove it if so
RUN rm -rf /usr/src/app/build

# Create the build directory first (before volume mounting)
RUN mkdir -p /usr/src/app/build

# Copy the source code into the container's src directory (not overwriting build)
COPY . /usr/src/app/src

# Set the working directory to the build directory for further commands
WORKDIR /usr/src/app/build

# Run cmake to generate build files
RUN cmake /usr/src/app/src

# Build the project
RUN cmake --build . --verbose

# Change back to the root app directory for easier navigation when the container starts
WORKDIR /usr/src/app

# Set the default command to a bash shell
CMD ["bash"]
