rm -rf build
mkdir build
cd build
cmake ..
make
make package
make package_source