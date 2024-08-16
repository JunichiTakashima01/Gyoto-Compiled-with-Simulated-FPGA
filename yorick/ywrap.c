/* codger-generated yorick package wrapper file */
#include "play.h"
#include "ydata.h"

/*----------------begin ./gyoto.i */
extern BuiltIn Y_gyoto_haveXerces;
extern BuiltIn Y_gyoto_haveCFITSIO;
extern BuiltIn Y_gyoto_haveBoost;
extern BuiltIn Y_gyoto_haveUDUNITS;
extern BuiltIn Y_gyoto_havePTHREAD;
extern BuiltIn Y_gyoto_haveMPI;
extern BuiltIn Y_gyoto_MPI_Init;
extern BuiltIn Y_gyoto_MPI_Finalize;
extern BuiltIn Y_gyoto_MPI_Finalized;
extern BuiltIn Y_gyoto_MPI_Initialized;
extern BuiltIn Y___gyoto_setErrorHandler;
extern BuiltIn Y_gyoto_requirePlugin;
extern BuiltIn Y_gyoto_loadPlugin;
extern BuiltIn Y_gyoto_havePlugin;
extern BuiltIn Y___gyoto_initRegister;
extern BuiltIn Y___gyoto_exportSupplier;
extern BuiltIn Y_gyoto_Scenery;
extern BuiltIn Y_gyoto_Scenery_rayTrace;
extern BuiltIn Y_gyoto_Photon;
extern BuiltIn Y_gyoto_Metric;
extern BuiltIn Y_gyoto_Astrobj;
extern BuiltIn Y_gyoto_ThinDisk;
extern BuiltIn Y_gyoto_Screen;
extern BuiltIn Y_gyoto_Spectrum;
extern BuiltIn Y_gyoto_debug;
extern BuiltIn Y_gyoto_verbose;
extern BuiltIn Y_gyoto_Spectrometer;
extern BuiltIn Y_gyoto_SpectroUniform;
extern BuiltIn Y__gyoto_SpectroUniform_register_as_Spectro;
extern BuiltIn Y_gyoto_SpectroComplex;
extern BuiltIn Y__gyoto_SpCplx_register_as_Spectrometer;
extern BuiltIn Y_is_gyoto_Photon;
extern BuiltIn Y_is_gyoto_Astrobj;
extern BuiltIn Y_is_gyoto_Metric;
extern BuiltIn Y_is_gyoto_Spectrometer;
extern BuiltIn Y_is_gyoto_Spectrum;
extern BuiltIn Y_is_gyoto_Screen;
extern BuiltIn Y_is_gyoto_Scenery;
extern BuiltIn Y_gyoto_dontcatchSIGFPE;
extern BuiltIn Y_gyoto_dontcatchSIGSEGV;
extern BuiltIn Y_gyoto_fedisableexcept;
extern BuiltIn Y_gyoto_feenableexcept;
extern BuiltIn Y_gyoto_haveFENV;
extern BuiltIn Y_gyoto_FE;
extern BuiltIn Y_gyoto_listRegister;

/*----------------list include files */

static char *y0_includes[] = {
  "./gyoto.i",
  0,
  0
};

/*----------------collect pointers and names */

static BuiltIn *y0_routines[] = {
  &Y_gyoto_haveXerces,
  &Y_gyoto_haveCFITSIO,
  &Y_gyoto_haveBoost,
  &Y_gyoto_haveUDUNITS,
  &Y_gyoto_havePTHREAD,
  &Y_gyoto_haveMPI,
  &Y_gyoto_MPI_Init,
  &Y_gyoto_MPI_Finalize,
  &Y_gyoto_MPI_Finalized,
  &Y_gyoto_MPI_Initialized,
  &Y___gyoto_setErrorHandler,
  &Y_gyoto_requirePlugin,
  &Y_gyoto_loadPlugin,
  &Y_gyoto_havePlugin,
  &Y___gyoto_initRegister,
  &Y___gyoto_exportSupplier,
  &Y_gyoto_Scenery,
  &Y_gyoto_Scenery_rayTrace,
  &Y_gyoto_Photon,
  &Y_gyoto_Metric,
  &Y_gyoto_Astrobj,
  &Y_gyoto_ThinDisk,
  &Y_gyoto_Screen,
  &Y_gyoto_Spectrum,
  &Y_gyoto_debug,
  &Y_gyoto_verbose,
  &Y_gyoto_Spectrometer,
  &Y_gyoto_SpectroUniform,
  &Y__gyoto_SpectroUniform_register_as_Spectro,
  &Y_gyoto_SpectroComplex,
  &Y__gyoto_SpCplx_register_as_Spectrometer,
  &Y_is_gyoto_Photon,
  &Y_is_gyoto_Astrobj,
  &Y_is_gyoto_Metric,
  &Y_is_gyoto_Spectrometer,
  &Y_is_gyoto_Spectrum,
  &Y_is_gyoto_Screen,
  &Y_is_gyoto_Scenery,
  &Y_gyoto_dontcatchSIGFPE,
  &Y_gyoto_dontcatchSIGSEGV,
  &Y_gyoto_fedisableexcept,
  &Y_gyoto_feenableexcept,
  &Y_gyoto_haveFENV,
  &Y_gyoto_FE,
  &Y_gyoto_listRegister,
  0
};

static void *y0_values[] = {
  0
};

static char *y0_names[] = {
  "gyoto_haveXerces",
  "gyoto_haveCFITSIO",
  "gyoto_haveBoost",
  "gyoto_haveUDUNITS",
  "gyoto_havePTHREAD",
  "gyoto_haveMPI",
  "gyoto_MPI_Init",
  "gyoto_MPI_Finalize",
  "gyoto_MPI_Finalized",
  "gyoto_MPI_Initialized",
  "__gyoto_setErrorHandler",
  "gyoto_requirePlugin",
  "gyoto_loadPlugin",
  "gyoto_havePlugin",
  "__gyoto_initRegister",
  "__gyoto_exportSupplier",
  "gyoto_Scenery",
  "gyoto_Scenery_rayTrace",
  "gyoto_Photon",
  "gyoto_Metric",
  "gyoto_Astrobj",
  "gyoto_ThinDisk",
  "gyoto_Screen",
  "gyoto_Spectrum",
  "gyoto_debug",
  "gyoto_verbose",
  "gyoto_Spectrometer",
  "gyoto_SpectroUniform",
  "_gyoto_SpectroUniform_register_as_Spectro",
  "gyoto_SpectroComplex",
  "_gyoto_SpCplx_register_as_Spectrometer",
  "is_gyoto_Photon",
  "is_gyoto_Astrobj",
  "is_gyoto_Metric",
  "is_gyoto_Spectrometer",
  "is_gyoto_Spectrum",
  "is_gyoto_Screen",
  "is_gyoto_Scenery",
  "gyoto_dontcatchSIGFPE",
  "gyoto_dontcatchSIGSEGV",
  "gyoto_fedisableexcept",
  "gyoto_feenableexcept",
  "gyoto_haveFENV",
  "gyoto_FE",
  "gyoto_listRegister",
  0
};

/*----------------define package initialization function */

PLUG_EXPORT char *yk_gyoto(char ***,
                         BuiltIn ***, void ***, char ***);
static char *y0_pkgname = "gyoto";

char *
yk_gyoto(char ***ifiles,
       BuiltIn ***code, void ***data, char ***varname)
{
  *ifiles = y0_includes;
  *code = y0_routines;
  *data = y0_values;
  *varname = y0_names;
  return y0_pkgname;
}
