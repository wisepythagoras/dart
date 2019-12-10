# Makefile for the x86 kernel
CC 	:= ./toolchain/bin/i386-elf-gcc
LD 	:= ./toolchain/bin/i386-elf-ld
AS      := ./toolchain/bin/nasm
ARMCC   := -nostdlib -nostartfiles -ffreestanding -std=c99 -lgcc
ARM	:= ./toolchain/bin/arm-none-eabi
# -Wall -Wextra 

INCLUDE := src/include

CFLAGS  := -v -msoft-float -nostdlib -nostdinc -fno-builtin -I$(INCLUDE) -Wextra -std=c99
# CFLAGS  := -std=c99 -pedantic -Wall -Wextra -MMD -Werror -Wno-unused-parameter
# CFLAGS  += -O3 -fomit-frame-pointer $(INCLUDE)
# CFLAGS  += -mno-sse -mno-mmx -mno-sse2 -mno-sse3
# CFLAGS  += -Isrc/include
# ASFLAGS := -felf32

all: make-all

make-all:
	@ echo "Make all"
	@ bash ./src/scripts/makeit

arm:
	@ echo "Make ARM"
	@ mkdir -p objs
	$(ARM)-as src/arch/arm/boot/start.s -o objs/start-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/main.c -o objs/main-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/arch/arm/screen.c -o objs/screen-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/arch/arm/cpuid.c -o objs/cpuid.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/screen/ctype.c -o objs/ctype-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/screen/printf.c -o objs/printf-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/screen/stdio.c -o objs/stdio-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/screen/stdlib.c -o objs/stdlib-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/screen/string.c -o objs/string-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/string/strlen.c -o objs/strlen-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/string/strcpy.c -o objs/strcpy-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/string/strcmp.c -o objs/strcmp-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/string/strcat.c -o objs/strcat-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/string/memset.c -o objs/memset-arm.o
	$(ARM)-gcc -Isrc/include $(ARMCC) -c src/string/memcpy.c -o objs/memcpy-arm.o
	$(ARM)-gcc -nostdlib -T src/linker-arm.ld -o kernel-arm objs/start-arm.o objs/screen-arm.o   \
	objs/ctype-arm.o objs/stdio-arm.o objs/stdlib-arm.o objs/string-arm.o objs/strlen-arm.o objs/strcpy-arm.o \
	objs/strcmp-arm.o objs/strcat-arm.o objs/memset-arm.o objs/memcpy-arm.o objs/main-arm.o objs/cpuid.o -lgcc

run-arm:
	@ qemu-system-arm -kernel kernel-arm -serial stdio -M none -cpu arm1176

run:
	@ qemu-system-i386 -kernel kernel-i386

clean:
	@ rm -rf objs
	@ rm kernel-i386

clean-toolchain:
	@ rm -rf toolchain
toolchain:
	@ echo ""
	@ echo "Starting automatic cross-toolchain build. This may take a while depending on"
	@ echo "your Internet connection and processor speed."
	@ echo ""
	@ echo "The cross-toolchain will be completely contained within the toolchain/ directory. No"
	@ echo "superuser access is required."
	@ echo ""
	@ mkdir -p toolchain
	@ echo " WGET toolchain/binutils-2.24.tar.bz2"
	@ wget -P toolchain http://ftp.gnu.org/gnu/binutils/binutils-2.27.tar.bz2
	@ echo " WGET toolchain/gcc-6.2.0.tar.bz2"
	@ wget -P toolchain http://ftp.gnu.org/gnu/gcc/gcc-6.2.0/gcc-6.2.0.tar.bz2
	@ echo " WGET toolchain/nasm-2.12.02.tar.bz2"
	@ wget -P toolchain http://www.nasm.us/pub/nasm/releasebuilds/2.12.02/nasm-2.12.02.tar.xz
	@ echo " WGET toolchain/mpfr-3.1.4.tar.xz"
	@ wget -P toolchain http://www.mpfr.org/mpfr-3.1.4/mpfr-3.1.4.tar.xz
	@ echo " WGET toolchain/mpc-1.0.3.tag.gz"
	@ wget -P toolchain http://www.multiprecision.org/mpc/download/mpc-1.0.3.tar.gz
	@ echo " WGET toolchain/gmp-6.1.1.tar.xz"
	@ wget -P toolchain http://ftp.gnu.org/gnu/gmp/gmp-6.1.1.tar.xz
	@ echo " UNTAR toolchain/binutils-2.24.tar.bz2"
	@ tar -xf toolchain/binutils-2.27.tar.bz2 -C toolchain
	@ rm toolchain/binutils-2.27.tar.bz2
	@ echo " UNTAR toolchain/gcc-6.2.0.tar.bz2"
	@ tar -xf toolchain/gcc-6.2.0.tar.bz2 -C toolchain
	@ rm toolchain/gcc-6.2.0.tar.bz2
	@ echo " UNTAR toolchain/nasm-2.12.02.tar.xz"
	@ tar -xf toolchain/nasm-2.12.02.tar.xz -C toolchain
	@ rm toolchain/nasm-2.12.02.tar.xz
	@ mkdir -p toolchain/build-binutils
	@ echo ""
	@ echo " CONFIGURING BINUTILS"
	@ echo ""
	@ cd toolchain/build-binutils && ../binutils-2.27/configure \
	--target=i386-elf --prefix=$(PWD)/toolchain --disable-nls
	@ echo ""
	@ echo " COMPILING BINUTILS"
	@ echo ""
	@ make -C toolchain/build-binutils all
	@ echo ""
	@ echo " INSTALLING BINUTILS"
	@ echo ""
	@ make -C toolchain/build-binutils install
	@ echo ""
	@ echo " CLEAN toolchain/build-binutils toolchain/binutils-2.27"
	@ rm -rf toolchain/build-binutils toolchain/binutils-2.27
	@ mkdir -p toolchain/build-gcc
	@ echo ""
	@ echo " CONFIGURING GCC"
	@ echo ""
	@ export PATH=$PATH:$(PWD)/toolchain/bin
	@ bash scripts/build_gcc.sh
	@ cd toolchain/build-gcc
	@ ../gcc-6.2.0/configure \
	--target=i386-elf --prefix=$(PWD)/toolchain --disable-nls \
	--enable-languages=c --without-headers
	@ echo ""
	@ echo " COMPILING GCC"
	@ echo ""
	@ make -C toolchain/build-gcc all-gcc
	@ echo ""
	@ echo " INSTALLING GCC"
	@ echo ""
	@ make -C toolchain/build-gcc install-gcc
	@ echo ""
	@ echo " CLEAN toolchain/build-gcc toolchain/gcc-6.2.0"
	@ rm -rf toolchain/build-gcc toolchain/gcc-6.2.0
	@ echo ""
	@ echo " CONFIGURING NASM"
	@ echo ""
	@ cd toolchain/nasm-2.12.02 && ./configure --prefix=$(PWD)/toolchain
	@ echo ""
	@ echo " COMPILING NASM"
	@ echo ""
	@ make -C toolchain/nasm-2.12.02
	@ echo ""
	@ echo " INSTALLING NASM"
	@ echo ""
	@ make -C toolchain/nasm-2.12.02 install
	@ echo ""
	@ echo " CLEAN toolchain/nasm-2.12.02"
	@ rm -rf toolchain/nasm-2.12.02
	
toolchain-arm:
	@ echo ""
	@ echo "Starting automatic cross-toolchain build. This may take a while depending on"
	@ echo "your Internet connection and processor speed."
	@ echo ""
	@ echo "The cross-toolchain will be completely contained within the toolchain/ directory. No"
	@ echo "superuser access is required."
	@ echo ""
	@ mkdir -p toolchain
	@ echo " WGET toolchain/binutils-2.24.tar.bz2"
	@ wget -P toolchain http://ftp.gnu.org/gnu/binutils/binutils-2.27.tar.bz2
	@ echo " WGET toolchain/gcc-6.2.0.tar.bz2"
	@ wget -P toolchain http://ftp.gnu.org/gnu/gcc/gcc-6.2.0/gcc-6.2.0.tar.bz2
	@ echo " WGET toolchain/nasm-2.12.02.tar.bz2"
	@ wget -P toolchain http://www.nasm.us/pub/nasm/releasebuilds/2.12.02/nasm-2.12.02.tar.xz
	@ echo " WGET toolchain/mpfr-3.1.4.tar.xz"
	@ wget -P toolchain http://www.mpfr.org/mpfr-3.1.4/mpfr-3.1.4.tar.xz
	@ echo " WGET toolchain/mpc-1.0.3.tag.gz"
	@ wget -P toolchain http://www.multiprecision.org/mpc/download/mpc-1.0.3.tar.gz
	@ echo " WGET toolchain/gmp-6.1.1.tar.xz"
	@ wget -P toolchain http://ftp.gnu.org/gnu/gmp/gmp-6.1.1.tar.xz
	@ echo " UNTAR toolchain/binutils-2.24.tar.bz2"
	@ tar -xf toolchain/binutils-2.27.tar.bz2 -C toolchain
	@ rm toolchain/binutils-2.27.tar.bz2
	@ echo " UNTAR toolchain/gcc-6.2.0.tar.bz2"
	@ tar -xf toolchain/gcc-6.2.0.tar.bz2 -C toolchain
	@ rm toolchain/gcc-6.2.0.tar.bz2
	@ mkdir -p toolchain/build-binutils
	@ echo ""
	@ echo " CONFIGURING BINUTILS"
	@ echo ""
	@ cd toolchain/build-binutils && ../binutils-2.24/configure \
	--target=arm-none-eabi --prefix=$(PWD)/toolchain --disable-nls
	@ echo ""
	@ echo " COMPILING BINUTILS"
	@ echo ""
	@ make -C toolchain/build-binutils all
	@ echo ""
	@ echo " INSTALLING BINUTILS"
	@ echo ""
	@ make -C toolchain/build-binutils install
	@ echo ""
	@ echo " CLEAN toolchain/build-binutils toolchain/binutils-2.27"
	@ rm -rf toolchain/build-binutils toolchain/binutils-2.27
	@ mkdir -p toolchain/build-gcc
	@ echo ""
	@ echo " CONFIGURING GCC"
	@ echo ""
	@ export PATH=$PATH:$(PWD)/toolchain/bin
	@ bash tools/build_gcc.sh
	@ cd toolchain/build-gcc
	@ ../gcc-6.2.0/configure \
	--target=arm-none-eabi --prefix=$(PWD)/toolchain --disable-nls \
	--enable-languages=c --without-headers 
	@ echo ""
	@ echo " COMPILING GCC"
	@ echo ""
	@ make -C toolchain/build-gcc all-gcc all-target-libgcc
	@ echo ""
	@ echo " INSTALLING GCC"
	@ echo ""
	@ make -C toolchain/build-gcc install-gcc install-target-libgcc
	@ echo ""
	@ echo " CLEAN toolchain/build-gcc toolchain/gcc-6.2.0"
	@ rm -rf toolchain/build-gcc toolchain/gcc-6.2.0
