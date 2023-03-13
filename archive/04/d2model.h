//! C99

/* d2model.h

Copyright (c) 2010 Sonia Keys

See external file LICENSE, distributed with this software.

-------------------------------------------------------------------------------
*/

// extents for model
#define D2CLASSES 13
#define QX 29
#define EX 8
#define IX 11
#define HX 18

// model
extern double  modelAllSS    [QX][EX][IX][HX];
extern double  modelUnkSS    [QX][EX][IX][HX];
extern double  modelAllClass [D2CLASSES][QX][EX][IX][HX];
extern double  modelUnkClass [D2CLASSES][QX][EX][IX][HX];

// partition arrays
extern double  qpart[QX];
extern double  epart[EX];
extern double  ipart[IX];
extern double  hpart[HX];

typedef _Bool (*classtest)(double, double, double);

extern char *classAbbr[D2CLASSES];
extern char *classHeading[D2CLASSES];
extern classtest isClass[D2CLASSES];

_Bool qeihToBin(double q, double e, double i, double h, int bin[4]);
_Bool qeiToBin(double q, double e, double i, int bin[3]);
_Bool hToBin(double h, int *ih);

