## CiTRONIX - "Command-line elecTRONics for UNIX"
Set of tools for working with matrix boards/perfboards and stripboards in UNIX/Linux
shell.

### Utilities

- **genboard** - generate either a matrix/perfboard or a stripboard; execute with
**-h** argument for a quick help
- **reverse** - flip the board from right to left (like turning page); reads from
stdin
- **colorboard** - color the board, reads from stdin. **REMEMBER** - this utility
adds colors, and colors are ASCII escape sequences, i.e. it might lead to
confusion if not aware

### Examples of Usage

    ./reverse <boards/talking_electronics | ./colorboard

This command flips the boards from right to left and colors it

    tac <boards/talking_electronics | ./colorboard

This command flips the boards from upside down and colors it

### Rules of Drawing the Boards using CiTRONIX
Actually, there is only one rule to follow - you can draw your matrix boards in
any way you wantt, but keep them as understandable as possible.

### Type & Size of the Moards
Matrix/Perfboards & stripboards the the supported types. Evidently, all routing
should be done on the backside, preferrably without jumpers. Personally, I try
to avoid jumpers at all costs, but sometimes it's impossible, thus symbol **j**
was introduced.

### Control signs
The following signs are employed:

    - | \ / - wire point-to-point connections
    . - non-soldered copper pad/strip hole; stip is continious in this place
    o - soldered copper pad with component lead; might be the IC leg either
    * - several connectiion wires soldered without component lead
    # - component space
    & - # + wire connection is routed under component
    @ - soldered positive lead of anything/anode
    " - wire connection is under component AND component is placed from upper left corner to down right corner
    c b e g s d - collector, base, emitter, gate, source, drain
    : - copper strip/pad is cut/drilled out here
    V v L - Positive power rail, negative power rail and common wire, usually connector pin; sometimes v = L
    < > - input/output pins
    j - jumper connection
    = - continious copper strip

### Boundaries of the Components
Usually, boundaries and direction - thus placement - of the component are recognised by placing
hashes **#** between solderable terminals. Some components. like opamps, or cermet pots, can be
also outline by hashes - if it's clearly marked, than normal wiring symbols can be used inside
hashed region to depict the wiring under conmponent nicely and correctly.

For example:

    #####
    o . o
    #  /#
    ##o##

This art shows the placement of component, and that actually two out of its three pins are short-circuited. If connecting wire crosses the border of the component without solder joint, is't better to use **&**.

### Not-so-easy Cases
If the connecting wire goes under component, usually it's enough to use **&**. However,
it's not always the case. For example:

    o o
    |"|
    o o
 
Usually, it's enough to enclose **&** between hashes, but this time it's not possible.
So, in order to handle this situation the **"** symbol was introduced to explicitly
specify the diagonal placement of the component.

Another example:

    o#+-@

In reality, it is a diode, with the connecting wire going right under and along
the component, thus making impossible to use hashes. Happily, there is nothing
around to confuse us, and it's actually possible to guess, how the component should
be placed. In more difficult situations the **&** or **"** should be added.
