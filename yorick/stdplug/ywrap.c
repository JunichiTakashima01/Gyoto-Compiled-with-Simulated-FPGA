/* codger-generated yorick package wrapper file */
#include "play.h"
#include "ydata.h"

/*----------------begin ./gyoto_std.i */
extern BuiltIn Y___set_GyotoStdPlugSupplier;
extern BuiltIn Y__gyoto_KerrBL_register_as_Metric;
extern BuiltIn Y__gyoto_KerrKS_register_as_Metric;
extern BuiltIn Y_gyoto_KerrBL;
extern BuiltIn Y_gyoto_KerrKS;
extern BuiltIn Y__gyoto_Star_register_as_Astrobj;
extern BuiltIn Y_gyoto_Star;
extern BuiltIn Y__gyoto_StarTrace_register_as_Astrobj;
extern BuiltIn Y_gyoto_StarTrace;
extern BuiltIn Y__gyoto_FixedStar_register_as_Astrobj;
extern BuiltIn Y_gyoto_FixedStar;
extern BuiltIn Y__gyoto_Torus_register_as_Astrobj;
extern BuiltIn Y_gyoto_Torus;
extern BuiltIn Y__gyoto_PatternDisk_register_as_Astrobj;
extern BuiltIn Y_gyoto_PatternDisk;
extern BuiltIn Y__gyoto_DirectionalDisk_register_as_Astrobj;
extern BuiltIn Y_gyoto_DirectionalDisk;
extern BuiltIn Y__gyoto_Disk3D_register_as_Astrobj;
extern BuiltIn Y_gyoto_Disk3D;
extern BuiltIn Y__gyoto_PolishDoughnut_register_as_Astrobj;
extern BuiltIn Y_gyoto_PolishDoughnut;
extern BuiltIn Y_gyoto_PowerLawSpectrum;
extern BuiltIn Y__gyoto_PowerLawSpectrum_register_as_Metric;
extern BuiltIn Y_gyoto_BlackBodySpectrum;
extern BuiltIn Y__gyoto_BlackBodySpectrum_register_as_Metric;

/*----------------list include files */

static char *y0_includes[] = {
  "./gyoto_std.i",
  0,
  0
};

/*----------------collect pointers and names */

static BuiltIn *y0_routines[] = {
  &Y___set_GyotoStdPlugSupplier,
  &Y__gyoto_KerrBL_register_as_Metric,
  &Y__gyoto_KerrKS_register_as_Metric,
  &Y_gyoto_KerrBL,
  &Y_gyoto_KerrKS,
  &Y__gyoto_Star_register_as_Astrobj,
  &Y_gyoto_Star,
  &Y__gyoto_StarTrace_register_as_Astrobj,
  &Y_gyoto_StarTrace,
  &Y__gyoto_FixedStar_register_as_Astrobj,
  &Y_gyoto_FixedStar,
  &Y__gyoto_Torus_register_as_Astrobj,
  &Y_gyoto_Torus,
  &Y__gyoto_PatternDisk_register_as_Astrobj,
  &Y_gyoto_PatternDisk,
  &Y__gyoto_DirectionalDisk_register_as_Astrobj,
  &Y_gyoto_DirectionalDisk,
  &Y__gyoto_Disk3D_register_as_Astrobj,
  &Y_gyoto_Disk3D,
  &Y__gyoto_PolishDoughnut_register_as_Astrobj,
  &Y_gyoto_PolishDoughnut,
  &Y_gyoto_PowerLawSpectrum,
  &Y__gyoto_PowerLawSpectrum_register_as_Metric,
  &Y_gyoto_BlackBodySpectrum,
  &Y__gyoto_BlackBodySpectrum_register_as_Metric,
  0
};

static void *y0_values[] = {
  0
};

static char *y0_names[] = {
  "__set_GyotoStdPlugSupplier",
  "_gyoto_KerrBL_register_as_Metric",
  "_gyoto_KerrKS_register_as_Metric",
  "gyoto_KerrBL",
  "gyoto_KerrKS",
  "_gyoto_Star_register_as_Astrobj",
  "gyoto_Star",
  "_gyoto_StarTrace_register_as_Astrobj",
  "gyoto_StarTrace",
  "_gyoto_FixedStar_register_as_Astrobj",
  "gyoto_FixedStar",
  "_gyoto_Torus_register_as_Astrobj",
  "gyoto_Torus",
  "_gyoto_PatternDisk_register_as_Astrobj",
  "gyoto_PatternDisk",
  "_gyoto_DirectionalDisk_register_as_Astrobj",
  "gyoto_DirectionalDisk",
  "_gyoto_Disk3D_register_as_Astrobj",
  "gyoto_Disk3D",
  "_gyoto_PolishDoughnut_register_as_Astrobj",
  "gyoto_PolishDoughnut",
  "gyoto_PowerLawSpectrum",
  "_gyoto_PowerLawSpectrum_register_as_Metric",
  "gyoto_BlackBodySpectrum",
  "_gyoto_BlackBodySpectrum_register_as_Metric",
  0
};

/*----------------define package initialization function */

PLUG_EXPORT char *yk_gyoto_std(char ***,
                         BuiltIn ***, void ***, char ***);
static char *y0_pkgname = "gyoto_std";

char *
yk_gyoto_std(char ***ifiles,
       BuiltIn ***code, void ***data, char ***varname)
{
  *ifiles = y0_includes;
  *code = y0_routines;
  *data = y0_values;
  *varname = y0_names;
  return y0_pkgname;
}
