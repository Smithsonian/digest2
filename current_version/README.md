# Digest2

Current version: 0.19.2, updated Oct. 7, 2021 by Peter Veres.
Changes: d2mpc.c - added band conversion for 'u', added CMOS 'B'

Digest2 uses statistical ranging techniques to compute chances that an
object is of various orbit classes, including Near Earth Objects, or NEOs.
Input is a file of 80 column MPC-format observations, with at least two
observations per object.  Output is orbit class scores for each object.

* Digest2 is available on Bitbucket at https://bitbucket.org/mpcdev/digest2/.
To download and install there are two parts, the source code and the "model,"
Both available from the digest2
[Downloads](https://bitbucket.org/mpcdev/digest2/downloads/) page (or on
Bitbucket, click the Downloads icon on the left.)  The Downloads page has
tabs labeled "Downloads" and "Tags."  The model is on the
[Downloads](https://bitbucket.org/mpcdev/digest2/downloads/?tab=downloads) tab,
the source code is on the
[Tags](https://bitbucket.org/mpcdev/digest2/downloads/?tab=tags) tab.

* For instructions on building the source code, see the file BUILDING.md.

* Further instructions on configuration and operation are in OPERATION.md.

* An outline of the underlying algorithm is in ALGORITHM.md.

* Digest2 is public domain.

### The name "digest2"

There is no known history of a digest1; this is not version 2 of a program.
Also nothing is known about the origin or meaning of the name.
The program name is simply digest2.
