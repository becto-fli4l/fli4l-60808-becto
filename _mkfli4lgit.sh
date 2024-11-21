#!/bin/sh

# \\_____
# // Tobias Becker / fli4l<at>becker<dot>link
#
# -> original/see: https://repo.nettworks.org/svn/fli4l/branches/4.0/trunk/src/_mkfli4lsvn.sh
# -> default values for some variables / edit or set variable in external file
# -> usage: ./_mkfli4lgit.sh ./<config-file>

arch="x86_64"
packages="base"
outdir=~/"fli4l/fli4l-git"
remove_configdir="no"
log=~/"fli4l/fli4l-git.log"
verbose="yes"

# no changes needed after this line
# --------------------------------------

# for later use of $SED (MacOS vs. Linux sed)
# -------------------------------------------
type -p gsed >/dev/null && SED=gsed || SED=sed

myecho ()
{
    if [ "$verbose" = "yes" ]
    then
        echo "$1" "$2"
    fi
}

# set variables with own configuration file
# -----------------------------------------
if [ -f "$1" ]
then
    . "$1"
elif [ -f _mkfli4lgit.conf ]
then
    . ./_mkfli4lgit.conf
fi

# some checks
# -----------
if [ ! -d ${outdir} ]
then
    echo "Error: ${outdir} does not exist ..."
    echo "create it (mkdir ${outdir}) and start again"
    exit 1
fi
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
    echo "Error: ../bin/$(arch) is missing -> Please check repository ..."
    exit 1
fi

echo
echo "updating fli4l (${outdir})"
echo "-------------------------------------------------------------------------------"
echo "removing old files"

remove="changes check doc img logo opt src unix windows"

if [ -f ${log} ]
then
    myecho "... removing ${log}"
    rm ${log}
fi

if [ "$remove_configdir" = "yes" ]
then
    if [ -d ${outdir}/config ]
    then
        myecho "... removing ${outdir}/config/"
        rm -rf ${outdir}/config
    fi
fi

for i in $remove
do
    if [ -d ${outdir}/$i ]
    then
        myecho "... removing ${outdir}/$i/"
        rm -rf ${outdir}/$i
    fi
done

# remove all files in the top directory of the fli4l hierarchy
for i in `$SED -e '/^[iI]/d;s/^. //;/.*\/.*/d' packages/*/files.txt`
do
    myecho "... removing ${outdir}/$i"
    rm -f ${outdir}/$i
done

rev=`git rev-parse --short HEAD`
branch=$(git branch | sed -n 's/^* //p')
[ "$branch" = "trunk" ] && branch= || branch="-$branch"

if [ -z "$rev" ]
then
	echo "Error finding current revision!"
	exit 1
fi

ver=`cat packages/base/version.txt`-r$rev$branch
ARCH=$arch; export ARCH

echo
echo "updating fli4l files to $ver"

for i in $packages
do
    if [ -d packages/$i ]
    then
        myecho "... copying $i"
        if ! ./mktarball packages/$i ${outdir} $ver >> ${log}
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

echo $ver > ${outdir}/version.txt
echo $arch > ${outdir}/arch.txt

echo
myecho "fbr-build: -> list available kernel:"
find "../bin/$(arch)/img" -name "linux-*"

echo
myecho "fbr-build: -> list available kernel modules:"
find "../bin/$(arch)/lib/modules/"

echo
echo "_mkfli4lgit.sh -> finished"

# ---//
