# Makefile.in
#
# Copyright © 2012, 2013 Brandon Invergo <brandon@invergo.net>
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.

# This Makefile contains targets that fail if run in parallel
.NOTPARALLEL:
# List whatever files you want to include in your source distribution here.
# You can include whole directories but note that *everything* under that 
# directory will be included
DISTFILES = PKG-INFO Makefile.in configure setup.py install-sh

DESTDIR = 

SED = /usr/bin/sed
PACKAGE_BUGREPORT = gyoto@sympa.obspm.fr
PACKAGE_NAME = Gyoto
PACKAGE_STRING = Gyoto 2.0.0
PACKAGE_TARNAME = gyoto
PACKAGE_DISTNAME = ${PACKAGE_NAME}-${PACKAGE_VERSION}
PACKAGE_URL = 
PACKAGE_VERSION = 2.0.0
PATH_SEPARATOR = :
PYTHON = /usr/bin/python3
VIRTUALENV = no
SPHINXBUILD = @SPHINXBUILD@
SHELL = /bin/bash
MKDIR_P = /usr/bin/mkdir -p
INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = ${prefix}
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
prefix = /usr/local
srcdir = .
top_srcdir = ..
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
pythondir = ${prefix}/local/lib/python3.10/dist-packages
pyexecdir = ${exec_prefix}/
pkgdatadir = $(datadir)/Gyoto
pkgincludedir = $(includedir)/Gyoto
pkgpythondir = ${pythondir}/Gyoto
pkgpyexecdir = @pkgpyexecdir@
PYTHONPATH = $(pythondir)$(PATH_SEPARATOR)$(DESTDIR)$(pythondir)
SWIG=/usr/bin/swig3.0

CFITSIO_CFLAGS = 
CFITSIO_LIBS = -lcfitsio -lpthread
XERCES_CFLAGS = 
XERCES_LIBS = -lxerces-c
UDUNITS_CFLAGS = 
UDUNITS_CPPFLAGS = @UDUNITS_CPPFLAGS@
UDUNITS_LDFLAGS = @UDUNITS_LDFLAGS@
UDUNITS_LIBS = -ludunits2

CXX=mpic++
CC=$(CXX)

PYTHON = /usr/bin/python3
PYTHON_ABI_FLAGS = @PYTHON_ABI_FLAGS@
PYTHON_CFLAGS = -I/usr/include/python3.10 -I/usr/include/python3.10  -Wno-unused-result -Wsign-compare -g      -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O2 -Wall
PYTHON_CONFIG = /usr/bin/python3-config
PYTHON_EXTENSION_SUFFIX = .cpython-310-x86_64-linux-gnu.so
PYTHON_INCLUDES = -I/usr/include/python3.10 -I/usr/include/python3.10
PYTHON_LDFLAGS = -L/usr/lib/python3.10/config-3.10-x86_64-linux-gnu -L/usr/lib/x86_64-linux-gnu  -lcrypt -ldl  -lm -lm 
PYTHON_LIBS =  -lcrypt -ldl  -lm -lm 
PYTHON_PREFIX = /usr
PYTHON_BUILD_DIR = build/lib.`python3 -c "import distutils.util,sys ; print('{}-{}.{}'.format(distutils.util.get_platform(), sys.version_info.major, sys.version_info.minor))"`

CPPFLAGS=-I../include -I$(top_srcdir)/include $(CFITSIO_CFLAGS) $(XERCES_CFLAGS) $(UDUNITS_CFLAGS)
CXXFLAGS=-g -O2 $(CFITSIO_CFLAGS) $(XERCES_CFLAGS) $(UDUNITS_CFLAGS)
CFLAGS=$(CXXFLAGS)

SWIG_CMD = $(SWIG) -I../include -I$(srcdir)/../include -c++ -python -outdir swig_output

export LDFLAGS
export CFLAGS
export CPPFLAGS
export CXXFLAGS
export CC

GYOTO_EXTENSIONS =  gyoto/_core$(PYTHON_EXTENSION_SUFFIX) \
                    gyoto/_std$(PYTHON_EXTENSION_SUFFIX)
GYOTO_PYFILES = gyoto/core.py gyoto/std.py
GYOTO_SWIGFILES = $(srcdir)/gyoto.i $(srcdir)/gyoto_std.i gyoto_doc.i $(srcdir)/numpy.i $(srcdir)/gyoto_swig.h $(srcdir)/gyoto_std_swig.h
#GYOTO_EXTENSIONS += gyoto/_lorene$(PYTHON_EXTENSION_SUFFIX)
#GYOTO_PYFILES += gyoto/lorene.py
#GYOTO_SWIGFILES += $(srcdir)/gyoto_lorene.i

all: $(GYOTO_PYFILES) $(GYOTO_EXTENSIONS) directories setup-check

setup-check:
	mkdir -p $(PYTHON_BUILD_DIR)
	cp -rf tests $(PYTHON_BUILD_DIR)

directories:
	mkdir -p dist
	mkdir -p Gyoto.egg-info

../doc/xml/index.xml:
	cd ../doc; $(MAKE) doxygen.stamp

gyoto_doc.i.orig: ../doc/xml/index.xml
	$(PYTHON) $(srcdir)/doxy2swig.py --no-function-definition $< $@ || rm $@

gyoto_doc.i: gyoto_doc.i.orig
	$(SED) -e 's/Gyoto::Screen::Angles/Angles/' \
	       -e 's/Gyoto::Screen::Bucket/Bucket/' \
	       -e 's/Gyoto::Screen::Coord1dSet/Coord1dSet/' \
	       -e 's/Gyoto::Screen::Coord2dSet/Coord2dSet/' \
	       -e 's/Gyoto::Screen::Empty/Empty/' \
	       -e 's/Gyoto::Screen::Grid/Grid/' \
	       -e 's/Gyoto::Screen::Indices/Indices/' \
	       -e 's/Gyoto::Screen::Range/Range/' \
	       -e 's/Gyoto::Screen::RepeatAngle/RepeatAngle/' \
	          $< > $@

gyoto/_core$(PYTHON_EXTENSION_SUFFIX): core_wrap.cxx
	$(PYTHON) setup.py build

gyoto/_std$(PYTHON_EXTENSION_SUFFIX): std_wrap.cxx
	$(PYTHON) setup.py build

gyoto/_lorene$(PYTHON_EXTENSION_SUFFIX): lorene_wrap.cxx
	$(PYTHON) setup.py build

gyoto/core.py: $(srcdir)/headers/core swig_output/core.py
	$(MKDIR_P) `dirname $@`
	cat $^ > $@

gyoto/std.py: $(srcdir)/headers/std swig_output/std.py
	$(MKDIR_P) `dirname $@`
	cat $^ > $@

gyoto/lorene.py: $(srcdir)/headers/lorene swig_output/lorene.py
	$(MKDIR_P) `dirname $@`
	cat $^ > $@

swig_output/core.py core_wrap.cxx: gyoto.i gyoto_doc.i $(top_srcdir)/include/*.h $(builddir)/../include/*.h
	$(MKDIR_P) swig_output
	$(SWIG_CMD) -o core_wrap.cxx $(srcdir)/gyoto.i

swig_output/std.py std_wrap.cxx: gyoto_std.i gyoto.i gyoto_doc.i $(top_srcdir)/include/*.h $(builddir)/../include/*.h
	$(MKDIR_P) swig_output
	$(SWIG_CMD) -o std_wrap.cxx $(srcdir)/gyoto_std.i

swig_output/lorene.py lorene_wrap.cxx: gyoto_lorene.i gyoto.i gyoto_doc.i $(top_srcdir)/include/*.h $(builddir)/../include/*.h
	$(MKDIR_P) swig_output
	$(SWIG_CMD) -o lorene_wrap.cxx $(srcdir)/gyoto_lorene.i

.PHONY: all install uninstall distclean info install-html html install-pdf pdf install-dvi dvi install-ps ps clean dist check installdirs


# Since installing to a virtualenv is all the rage these days, support it here. If the VIRTUALENV
# variable is set to anything other than "no", set up a new virtualenv and install there, otherwise
# install as usual from setup.py
install: all installdirs
ifneq ($(VIRTUALENV),no)
	$(VIRTUALENV) $(VIRTUALENV_FLAGS) $(DESTDIR)$(prefix) || $(VIRTUALENV) $(DESTDIR)$(prefix)
	$(DESTDIR)$(prefix)/bin/python setup.py install --prefix=$(DESTDIR)$(prefix)
else
	$(PYTHON) setup.py install --prefix=$(DESTDIR)$(prefix) --record=gyoto_installed.txt
endif
	$(INSTALL_DATA) $(GYOTO_SWIGFILES) $(DESTDIR)$(pkgincludedir)


# setup.py doesn't (yet) support an uninstall command, so until it does, you 
# must manually remove everything that was installed here. The following example
# should remove a basic package installed via setup.py, but please double- and 
# triple-check it so that you don't remove something you shouldn't!
# Be sure to remove any extra files you install, such as binaries or documentation!
uninstall: 
	-cd $(DESTDIR)$(pkgincludedir) ; \
	   for file in $(GYOTO_SWIGFILES) numpy.i gyoto_swig.h ; do \
	      rm `basename $$file` ;\
	   done
	-rm -rvf $(DESTDIR)$(pkgpythondir)
	-cat gyoto_*installed.txt | xargs rm
	-rmdir $(DESTDIR)$(pkgincludedir)


# Just use the usual setup.py clean command
clean:
	$(PYTHON) setup.py clean
	-rm -Rf build dist swig_output $(GYOTO_PYFILES) $(GYOTO_EXTENSIONS)
	-rm *.pyc gyoto_doc.i gyoto_doc.i.orig
	-rm -f doxygen_sqlite3.db gyoto_*installed.txt
	-rm -f tests/*.pyc *_wrap.cxx gyoto/*.pyc
	-rm -Rf _gyoto*.so Gyoto*.egg-info _*.so
	-rm -Rf dist gyoto/__pycache__/ tests/__pycache__/

# Clean up the output of configure
distclean: clean 
	-rm -v $(builddir)/setup*.py
	-rm -v $(builddir)/Makefile

# You can either use the setup.py sdist command or you can roll your own here
dist:
#	$(PYTHON) setup.py sdist
	mkdir $(PACKAGE_DISTNAME)
	cp -r $(DISTFILES) $(PACKAGE_DISTNAME)
	tar -czf $(PACKAGE_DISTNAME).tar.gz $(PACKAGE_DISTNAME)
	rm -rf $(PACKAGE_DISTNAME)

# Use the setup.py test command
check:
	cd $(PYTHON_BUILD_DIR) ; LD_LIBRARY_PATH=../../../lib/.libs:$$LD_LIBRARY_PATH PYTHONPATH=.:$$PYTHONPATH $(PYTHON) -B -m unittest tests/*.py

# setup.py might complain if a directory doesn't exist so just in case, make the directory
# here
installdirs:
	$(MKDIR_P) $(DESTDIR)$(pkgpythondir)
	$(MKDIR_P) $(DESTDIR)$(pkgincludedir)



# The following show how to install documentation. In this example,
# docs are built from a separate Makefile contained in the docs
# directory which uses the SPHINXBUILD variable to store the location
# of the sphinx-build (Python doc tool) binary to use.

# $(DESTDIR)$(infodir)/foo.info: docs/build/texinfo/foo.info
# 	$(POST_INSTALL)
# 	$(INSTALL_DATA) @< $(DESTDIR)$@
# 	if $(SHELL) -c 'install-info --version' >/dev/null 2>&1; then
# 		install-info --dir-file=$(DESTDIR)$(infodir)/dir \
# 				$(DESTDIR)$(infodir)/foo.info;
# 	else true; fi
#
# info: docs/build/texinfo/foo.info
#
# docs/build/texinfo/foo.info: $(wildcard docs/source/*)
# ifneq ($(SPHINXBUILD),no)
# 	$(MAKE) -C docs info SPHINXBUILD=$(SPHINXBUILD)
# endif
#
#
# install-html: html installdirs
# 	$(INSTALL_DATA) docs/build/html/* $(DESTDIR)$(htmldir)
#
# html: docs/build/html/index.html
#
# docs/build/html/index.html: $(wildcard $(srcdir)/docs/source/*)
# ifneq ($(SPHINXBUILD),no)
# 	$(MAKE) -C docs html SPHINXBUILD=$(SPHINXBUILD)
# endif
#
#
# install-pdf: pdf installdirs
# 	$(INSTALL_DATA) docs/build/latex/foo.pdf $(DESTDIR)$(pdfdir)
#
# pdf: docs/build/latex/Foo.pdf
#
# docs/build/latex/foo.pdf: $(wildcard $(srcdir)/docs/source/*)
# ifneq ($(SPHINXBUILD),no)
# 	$(MAKE) -C docs latexpdf SPHINXBUILD=$(SPHINXBUILD)
# endif
#
#
# install-dvi:
#
# dvi:
#
# install-ps:
#
# ps:


