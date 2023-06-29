# Digest2

`digest2` uses statistical ranging techniques to compute chances that an
object is of various orbit classes, including Near Earth Objects, or NEOs.
The input file can be either `.obs` (80 column MPC-format) or `xml` (ADES), with at least two
observations per object. `digest2` will output orbit class scores for each object.

### Latest improvements
Current version: 0.19.3, updated June 22, 2023 by Richard Cloete & Peter Veres.

This latest update includes the ability for `digest2` to read and parse the new [ADES (xml) format](https://minorplanetcenter.net/iau/info/ADES.html), bringing with it the following advantages:
- Improved precision: The ADES format includes the full precision of the observations, c.f. the truncated 80-column MPC format.
- Performance: Computations using the ADES format provide 5x performance speedup.
- Improved uncertainties: The ADES format provides new astrometric uncertainty information (rmsRA and rmsDec), which is more accurate than the estimated error values previously used (see config file).
- The ability to process roving observer observations, which are not supported in the 80-column MPC format.
- The ability to process satellite observations.


### Getting started
To get started, clone this repository and read the following files:
* [BUILDING.md](BUILDING.md) for instructions on building the source code.
* [OPERATION.md](OPERATION.md) for instructions on configuration and operation.
* [ALGORITHM.md](ALGORITHM.md) for an outline of the underlying algorithm.


### License
Digest2 is public domain. See [LICENSE.md](LICENSE.md) for details.

### The name "digest2"
There is no known history of a digest1; this is not version 2 of a program.
Also nothing is known about the origin or meaning of the name.
The program name is simply `digest2`.
