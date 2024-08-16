#!/usr/bin/env python

# setup.py.in.distutils
#
# Copyright 2012, 2013 Brandon Invergo <brandon@invergo.net>
# Copyright 2014 Thibaut Paumard
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.

HOME_LORENE=""

from setuptools import setup, Extension
import platform
import re

import numpy
try:
    numpy_include = numpy.get_include()
except AttributeError:
    numpy_include = numpy.get_numpy_include()


if platform.system() == 'Linux':
    doc_dir = '/usr/local/share/doc/gyoto'
else:
    try:
        from win32com.shell import shellcon, shell
        homedir = shell.SHGetFolderPath(0, shellcon.CSIDL_APPDATA, 0, 0)
        appdir = 'gyoto'
        doc_dir = os.path.join(homedir, appdir)
    except:
        pass

gyoto_lib_dirs=['../lib/.libs']
gyoto_libs=['gyoto-unreleased']
for libspec in ('-lcfitsio -lpthread', '-lxerces-c', '-ludunits2'):
    libspec=re.split('[ \t]', libspec)
    for comp in libspec:
        if re.match('-L', comp):
            gyoto_lib_dirs.append(re.sub('^-L', '', comp))
        elif re.match('-l', comp):
            gyoto_libs.append(re.sub('^-l', '', comp))

gyoto_module = Extension('gyoto/_core',
                         sources=['core_wrap.cxx'],
                         include_dirs=[numpy_include, '/home/junichi/Gyoto/python'],
                         library_dirs=gyoto_lib_dirs,
                         libraries=gyoto_libs
                         )

gyoto_std_module = Extension('gyoto/_std',
                         sources=['std_wrap.cxx'],
                         include_dirs=[numpy_include, '/home/junichi/Gyoto/python'],
                         library_dirs=gyoto_lib_dirs,
                         libraries=gyoto_libs
                         )

gyoto_lorene_module = Extension('gyoto/_lorene',
                         sources=['lorene_wrap.cxx'],
                         include_dirs=[numpy_include, '/home/junichi/Gyoto/python'],
                         library_dirs=gyoto_lib_dirs,
                         libraries=gyoto_libs
                         )

pymodules = ["gyoto.__init__", "gyoto.core", "gyoto.std", "gyoto_std",
             "gyoto._namespaces", "gyoto.astrobj", "gyoto.metric",
             "gyoto.spectrum", "gyoto.spectrometer", "gyoto.animate", "gyoto.util"]
extmodules= [gyoto_module, gyoto_std_module]

if HOME_LORENE != "":
    pymodules.append("gyoto.lorene")
    pymodules.append("gyoto_lorene")
    extmodules.append(gyoto_lorene_module)

setup(name='Gyoto',
      version='2.0.0',
      author_email='gyoto@sympa.obspm.fr',
      py_modules=pymodules,
      ext_modules=extmodules,
      test_suite='tests'
     )
