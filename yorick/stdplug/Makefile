# these values filled in by    yorick -batch make.i
Y_MAKEDIR=/usr/lib/yorick
Y_EXE=/usr/lib/yorick/bin/yorick
Y_EXE_PKGS=
Y_EXE_HOME=/usr/lib/yorick
Y_EXE_SITE=/usr/lib/yorick
Y_HOME_PKG=

# ----------------------------------------------------- optimization flags

# options for make command line, e.g.-   make COPT=-g TGT=exe
COPT=$(COPT_DEFAULT) -L../../lib -I../../include -I../../include
TGT=$(DEFAULT_TGT)

# ------------------------------------------------ macros for this package

vpath %.C .

CXXFLAGS=-g -O2
CPPFLAGS= -P  -DGYOTO_NO_DEPRECATED
XERCES_LIBS=-lxerces-c
XERCES_CFLAGS=
CFITSIO_LIBS=-lcfitsio -lpthread
CFITSIO_CFLAGS=
UDUNITS_CFLAGS=
BOOST_CPPFLAGS=
UDUNITS_LIBS=-ludunits2
DYLIB_VAR=LD_LIBRARY_PATH
PTHREAD_CFLAGS= 
PTHREAD_LIBS= 
SYS=other
plugin_sfx=so

YGYOTO_C = $(shell ls ./../*.C)
GYOTO_C = $(shell ls ../../lib/*.C)
GYOTO_OBJ = $(GYOTO_C:.C=.o)
GYOTO_H = $(shell ls ../../include/*.h)

PKG_NAME=gyoto_std
PKG_I=./gyoto_std.i

OBJS = StdPlug.o gyoto_KerrBL.o gyoto_KerrKS.o \
	gyoto_Star.o gyoto_StarTrace.o gyoto_FixedStar.o \
	gyoto_Torus.o gyoto_PatternDisk.o \
	gyoto_DirectionalDisk.o \
	gyoto_Disk3D.o gyoto_PolishDoughnut.o\
	gyoto_PowerLawSpectrum.o gyoto_BlackBodySpectrum.o

# change to give the executable a name other than yorick
PKG_EXENAME=yorick

# PKG_DEPLIBS=-Lsomedir -lsomelib   for dependencies of this package
PKG_DEPLIBS=-L../../lib/.libs -lgyoto-unreleased $(PTHREADS_LIBS)

ifeq ($(SYS),Darwin)
PKG_DEPLIBS+=-bundle_loader ../../lib/.libs/libgyoto-stdplug.$(plugin_sfx) \
	-flat_namespace -bundle_loader ../gyoto.so $(LIB_CXX)
endif

# set compiler (or rarely loader) flags specific to this package
PKG_CFLAGS= -I../../include -I../../yorick $(XERCES_CFLAGS) $(CFITSIO_CFLAGS) $(UDUNITS_CFLAGS) $(BOOST_CPPFLAGS) $(PTHREAD_CFLAGS)
PKG_LDFLAGS= $(PTHREAD_CFLAGS)

# list of additional package names you want in PKG_EXENAME
# (typically Y_EXE_PKGS should be first here)
EXTRA_PKGS=$(Y_EXE_PKGS)

# list of additional files for clean
PKG_CLEAN=

# autoload file for this package, if any
PKG_I_START=
# non-pkg.i include files for this package, if any
PKG_I_EXTRA=

# -------------------------------- standard targets and rules (in Makepkg)

# set macros Makepkg uses in target and dependency names
# DLL_TARGETS, LIB_TARGETS, EXE_TARGETS
# are any additional targets (defined below) prerequisite to
# the plugin library, archive library, and executable, respectively
PKG_I_DEPS=$(PKG_I)
Y_DISTMAKE=distmake

include $(Y_MAKEDIR)/Make.cfg
# Yorick-distributed Makepkg is not reliable for out-of-tree builds.
include ../../yorick/Makepkg
include $(Y_MAKEDIR)/Make$(TGT)

# override macros Makepkg sets for rules and other macros
# Y_HOME and Y_SITE in Make.cfg may not be correct (e.g.- relocatable)
Y_HOME=$(Y_EXE_HOME)
Y_SITE=$(Y_EXE_SITE)
# use the compiler selected with the configure script
CC=gcc
CXX=mpic++

# Actual install directories set with ./configure --with-yorick-*
prefix=/usr/local
exec_prefix=${prefix}
DEST_Y_HOME=$(DESTDIR)${exec_prefix}/lib/yorick
DEST_Y_SITE=$(DESTDIR)${prefix}/lib/yorick

# ------------begin C++ source hacks
# must use C++ to load yorick with this C++ package
# this assumes make default CXX macro points to C++ compiler
CXXFLAGS+=$(CFLAGS) $(GYOTO_FLAGS) -DYGYOTO_LOCAL_SUPPLIER=GyotoStdPlugSupplier
LD_DLL=$(CXX) $(LDFLAGS) $(PLUG_SHARED)
LD_EXE=$(CXX) $(LDFLAGS) $(PLUG_EXPORT)

# C++ has no standard file extension, supply default make rule(s)
.C.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<
# --------------end C++ source hacks

# simple example:
#myfunc.o: myapi.h
# more complex example (also consider using PKG_CFLAGS above):
#myfunc.o: myapi.h myfunc.c
#	$(CC) $(CPPFLAGS) $(CFLAGS) -DMY_SWITCH -o $@ -c myfunc.c


StdPlug.o: ./../ygyoto_supplier.C ./../ygyoto.h 
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<

../../lib/libgyoto.a: $(GYOTO_C) $(GYOTO_H)
	make -C ../lib

gyoto_std.so: ../gyoto.so $(OBJS)

../gyoto.so:
	make -C .. gyoto.so

.PHONY: standalone test-cppprog test-standalone test test-plugin check

# -------------------------------------------------------- end of Makefile
