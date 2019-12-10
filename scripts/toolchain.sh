#!/bin/bash

# Define the source that we will need to build the complete toolchain for
# Dart.
sources=(
    "http://ftp.gnu.org/gnu/binutils/binutils-2.27.tar.bz2"
    "http://ftp.gnu.org/gnu/gcc/gcc-6.2.0/gcc-6.2.0.tar.bz2"
    "http://www.nasm.us/pub/nasm/releasebuilds/2.12.02/nasm-2.12.02.tar.xz"
    "http://www.mpfr.org/mpfr-3.1.4/mpfr-3.1.4.tar.xz"
    "http://www.multiprecision.org/mpc/download/mpc-1.0.3.tar.gz"
    "http://ftp.gnu.org/gnu/gmp/gmp-6.1.1.tar.xz"
)

#echo $1; exit
export ARCH="i386"
export VALIDARCH=("i386" "arm" "x86_64")

# The function that checks if the command line arguments are
# valid.
validateArguments () {
    local e

    for e in "${@:2}"; do [[ "$e" == "$1" ]] && return 0; done

    return 1
}

# Check the arguments and get the target architecture.
if [[ -n $1 ]]
then
    validateArguments $1 "${VALIDARCH[@]}"

    if [ $? = 1 ]
    then
        echo "Unknown architecture '$1'"
        exit
    fi

    # If the architecture was found, set that into the ARCH variable.
    ARCH="$1"

    if [[ "$ARCH" = $(uname -m) ]]
    then
        printf "No need to build toolchain since the target architecture"
        printf "is the same as the machine architecture: $ARCH\n"
        exit
    fi
fi

echo "Building for $ARCH"
export filenames=()

# Download the sources.
for source in "${sources[@]}"
do
    filename=${source##*/}
    filenames+=("$filename")
    echo "GET '$filename'"

    # Download the source only if it hasn't already been downloaded.
    if [ ! -f toolchain/$filename ]
    then
        wget -q -P toolchain $source

        # Notify for any possible error encountered while attempting
        # to download the source file.
        if [ $? != 0 ]
        then
            echo "There was an error downloading $source"
            exit
        fi
    fi
done

# Enter the toolchain directory
cd toolchain

# Extract the sources.
for file in "${filenames[@]}"
do
    folder=$(echo $file | perl -pe 's/\.(tar|tgz).*$//;s{^.*/}{}')
    echo "UNTAR $folder"

    # Extract the sources if they haven't been already extracted.
    if [ ! -d "$folder" ]
    then
        tar xf $file
    fi
done

# Start building...
