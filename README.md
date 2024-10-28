## CMake C++ Project For Zipf's Law

This is a C++ project that demonstrates the use of CMake, Google Test, and Doxygen to build a project that calculates the frequency of words in a text file and verifies that the frequency distribution follows Zipf's Law. The project contains two different implementations to process a book, get the distribution of its words, rank those words, count the hapax legomena, and to graph the Zipf's Law as a log-log plot.

The first implementation uses associative containers like `std::map` and `std::multimap`, while the second implementation relies solely on vector and algorithms from the STL (Standard Template Library).

Both matplot++ and python are used to generate the log-log plot of the Zipf's Law.

### Prerequisites

Install the dependencies:

```bash
conda env create -f environment.yml
```
This will create a conda environment called `cppdev` which you can activate with:

```bash
conda activate cppdev
```

### Building the project

To build the project, create a build directory and run CMake from there:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

You can now run the executable:

```bash
    ./bin/zipf
    make run_plot_script
    make run_plot_script_vs
```

Or...

You can now run the tests:

```bash
ctest
```

It might be called ctest.exe in Windows.

The documentation will also be generated in the `build/docs/sphinx/index.html` directory. Open the `index.html` file in a web browser to view it.


### Cleaning the project

To clean the project, just remove the `build` directory:

```bash
rm -rf build
```
