# digest2

last update: July 13, 2023 by P. Veres

`digest2` is  a fast, short-arc orbit classifier for small solar system bodies writen in C. 
The code provides a score, which represents a pseudo-probability that a tracklet (set of several
astrometric positions of the same object within a night) belongs to a given solar system orbit type.
digest2 is primarily used as a classifier for Near-Earth Object (NEO) candidates, to identify those
to be prioritized for rapid follow-up observation.

The functionality and componnts of the code are described in details in:
Keys, S., Veres, P., Payne, M.J. et al., 2019. The digest2 NEO Classification Code. 
Publications of the Astronomical Society of the Pacific, 131:064501 (22pp)

and in
Veres, P., Cloete, R., Weryk, R. et al, (in prep). Improvement of digest2 NEO Classification Code
 - utilizing the Astrometry Data Exchange Standard.
 
 the original repository of the code was in
 https://bitbucket.org/mpcdev/digest2/src/master/
 
 However, the new repository will be available at
 https://github.com/Smithsonian/digest2
 
 The new repository consists of three directories:
 
 1) population (contains the population model, configuration file with observatory codes
and uncertaities and archive with previous config and population model. Also contains
make_population directory with the instruction how to construct the population csv file)
 2) archive (previous versions of digest2 code)
 3) digest2 (the main and current repo with the source code, with the instructions and readme files)
 
