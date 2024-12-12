#!/bin/sh

# \\_____
# // Tobias Becker / fli4l<at>becker<dot>link
#
# -> original/see: https://repo.nettworks.org/svn/fli4l/branches/4.0/trunk/src/_mkfli4lsvn.sh
# -> default values for some variables / edit or set variable in external file
# -> usage: ./_mkfli4lgit.sh ./<config-file>

arch="x86_64"
packages="base"
lang="english"
log=~/"fli4l/fli4l-git.log"
verbose="yes"

# //for later use of $SED (MacOS vs. Linux sed)
#
type -p gsed >/dev/null && SED=gsed || SED=sed

myecho ()
{
    if [ "$verbose" = "yes" ]
    then
        echo "$1" "$2"
    fi
}

echo "set config variables"
if [ -f "$1" ]
then
    . "$1"
    echo "[ok] -> use <config-file> $1"
elif [ -f _mkfli4lgit.conf ]
then
    . ./_mkfli4lgit.conf
    echo "[ok] -> use <config-file> _mkfli4lgit.conf"
fi

echo "check repo/build structure"
if [ ! -f ./mktarball ]
then
    echo "Error: mktarball file is missing ..."
    exit 1
fi
if [ ! -f packages/base/version.txt ]
then
    echo "Error: current working directory is not the base directory of a checked out repository ..."
    exit 1
fi
if [ ! -d ../bin/$(arch) ]
then
    echo "Error: ../bin/$(arch) is missing -> Please check directory structure ..."
    exit 1
fi

echo "[ok] -> finished"
echo
echo "-------------------------------------------------------------------------------"
echo "cleanup:"

if [ -f ${log} ]
then
    myecho "... removing ${log}"
    rm ${log}
fi

rev=`git rev-parse --short HEAD`
branch=$(git branch | sed -n 's/^* //p')
[ "$branch" = "trunk" ] && branch= || branch="-$branch"

if [ -z "$rev" ]
then
	echo "Error finding current revision!"
	exit 1
fi

ver=`cat packages/base/version.txt`-$rev$branch
ARCH=$arch; export ARCH

if [ -d ~/fli4l-$ver ]
then
    myecho "... removing deprecated files from ~/fli4l-$ver"
    rm -rf ~/fli4l-$ver
fi

echo
echo "create folder fli4l-$ver and run mktarball:"
mkdir ~/fli4l-$ver

for i in $packages
do
    if [ -d packages/$i ]
    then
        myecho "... copying $i"
        if ! ./mktarball packages/$i ~/"fli4l-$ver" $ver >> ${log}
        then
            myecho "[failed] package (files) not found -> Please check repository with check-files.pl"
            exit 1
        else
            myecho "[ok] package found -> finished"
        fi
    else
        myecho "... skipping package $i because no source directory for $i exists"
    fi
done

echo $ver > ~/"fli4l-$ver"/version.txt
echo $arch > ~/"fli4l-$ver"/arch.txt

echo
myecho "fbr-build: -> list available kernel:"
find "../bin/$(arch)/img" -name "linux-*"

echo
myecho "fbr-build: -> list available kernel modules:"
find "../bin/$(arch)/lib/modules/"

echo
for i in $packages
do
    if [ -d ~/fli4l-$ver/doc/$lang/tex/$i ] && [ $i != "doc" ];
    then
        myecho "... run texlive build -> ~/fli4l-$ver/doc/$lang/tex/$i"
        make -C ~/fli4l-$ver/doc/$lang/tex/$i >> $log 2>&1
    else
        myecho "... exclude directory $i from texlive build"
    fi
done

echo
echo "_mkfli4lgit.sh -> finished"

# ---//
