/*
    Copyright 2014 Thibaut Paumard

    This file is part of Gyoto.

    Gyoto is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Gyoto is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Gyoto.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
  The purpose of this file is to set Yorick paths to access the gyoto
  plug-in from the built source tree. This file (setpaths.i) and its
  source (setpaths.i.in) are not supposed to be installed on the
  system.
 */

abs_top_srcdir="/home/junichi/Gyoto";
abs_top_builddir="/home/junichi/Gyoto";

#include "pathfun.i"
idirs=abs_top_srcdir+"/yorick/"+["", "stdplug/"];
sodirs=abs_top_builddir+"/yorick/"+["", "stdplug/"];
plug_dir,_(sodirs, plug_dir());
set_path, pathform(idirs)+":"+get_path();

GYOTO_EXAMPLES_DIR=abs_top_builddir+"/doc/examples/";
