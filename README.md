# DEModel

A simple viscoelastic model for dielectric elastomers is implemented based on the Constitutive Modeling Framework (CMF).

This suite requires the CMF library and the Eigen library (see https://eigen.tuxfamily.org)

# Commands Windows (MinGW) compilation and testing

1. mkdir build
2. cd build
3. cmake -G "MinGW Makefiles" ../ -DCMAKE_INSTALL_PREFIX=/install/path -DCMF_DIR=/path/to/cmf -DEIGEN3_DIR=/path/to/eigen
4. mingw32-make install
5. ctest