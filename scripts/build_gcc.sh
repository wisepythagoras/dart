#!/bin/bash

cd toolchain/gcc-6.2.0

tar -xf ../mpfr-3.1.4.tar.xz
mv -v mpfr-3.1.4 mpfr
tar -xf ../gmp-6.1.1.tar.xz
mv -v gmp-6.1.1 gmp
tar -xf ../mpc-1.0.3.tar.gz
mv -v mpc-1.0.3 mpc

cd ..
