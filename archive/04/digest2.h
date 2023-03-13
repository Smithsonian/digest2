/*
digest2.h

Copyright (c) 2010 Sonia Keys

See external file LICENSE, distributed with this software.

-------------------------------------------------------------------------------
*/

#include <stdint.h>
#include "d2model.h"

// M_PI is in math.h, but not defined in some strict modes
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327
#endif

// typedefs
//-----------------------------------------------------------------------------
// observation.
typedef struct {
   double mjd;  // modified julian date
   double ra;   // radians
   double dec;
   double vmag;  // observed magnitude, normalized to V band.
                 // 0 means no magnitude.
   int    site;  // index into site table.  basically an integer form of the
                 // MPC three character obscode.
   _Bool  spacebased;
   double earth_observer[3];
} observation;

// site.  observatory site parallax constants.
typedef struct {
   double longitude;  // unit is circles
   double rhoCosPhi;  // unit is AU
   double rhoSinPhi;
} site;

// tkstatus.  traklet status, during processing and as a result code.
typedef enum {
   INVALID,
   UNPROC,
   ACRON,
   FAIL,
   SUCCESS
} tkstatus;

typedef struct {
   double rawScore;
   double noIdScore;
   _Bool  tagInClass[QX][EX][IX][HX];
   _Bool  tagOutOfClass[QX][EX][IX][HX];
   double sumAllInClass;
   double sumUnkInClass;
   double sumAllOutOfClass;
   double sumUnkOutOfClass;
   _Bool  dInClass[QX][EX][IX][HX];
   _Bool  dOutOfClass[QX][EX][IX][HX];
} perClass;

// tracklet.  struct holds working variables and everything associated with
// computing scores for a single tracklet.
//
// note: some code relies on this structure being zero initialized.
typedef struct {
   // these few elements really describe the tracklet
   tkstatus status;
   char desig[13];
   observation *olist;
   int obsCap; // allocated capacity of olist
   int lines;  // for status=INVALID, this is the number of consecutive
               // invalid lines.  otherwise, it is the number of valid
               // observations in olist.

   // distance independent working variables.  computed over the course
   // of processing the tracklet.
   uint64_t rand;                      // LCG random numuber
   double vmag;                       // composite value for the tracklet
   double sun_observer[2][3];         // vectors at times t0 and t1
   double observer_object_unit[2][3]; // vectors at times t0 and t1
   double dt;                         // t1 - t0
   double invdt;                      // 1/dt
   double invdtsq;                    // 1/(dt**2)
   int    binsTagged;
   _Bool  tag[QX][EX][IX][HX];

   // distance dependent working variables.  these are computed separately
   // for each distance considered.
   double sun_object0[3];
   double sun_object0_mag;
   double sun_object0_magsq;

   double observer_object0[3];
   double observer_object0_mag;

   double observer1_object0 [3];
   double observer1_object0_mag;
   double observer1_object0_magsq;

   double tz;
   double hmag;
   int    hmag_bin;
   _Bool  dNewTag;
   _Bool  dTag[QX][EX][IX][HX];

   perClass *class;  // array, extent = nClassesComputed
} tracklet;

extern char msgMemory[];
extern char msgOpen[];
extern char msgRead[];
extern char msgStatus[];
extern char msgUsage[];

extern site siteTable[2000];
extern double K, INV_K, U, TWO_PI;
extern uint64_t LCGA, LCGM;
extern double invLCGM;
extern int nClassConfig;
extern int classConfig[D2CLASSES];

void fatal(char *msg);
void fatal1(char *msg, char *arg);

double mustStrtod(char *str);
int mustStrtoi(char *str);

// functions in mpc.c
void readMpcOcd(void);
_Bool parseMpc80(char *line, observation *obsp);
_Bool parseMpcSat(char *line, observation *obsp);

// functions in d2mathq.c
void initGlobals(void);
void score(tracklet *tk);
