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

### Examples

    ./reverse <boards/talking_electronics | ./colorboard

This command flips the boards from right to left and colors it

    tac <boards/talking_electronics | ./colorboard

This command flips the boards from upside down and colors it

### Control signs
The following signs are employed:

    [-|\/] - wire point-to-point connections
    . - non-soldered copper pad/strip hole; stip is continious in this place
    o - soldered copper pad with component lead
    * - several connectiion wires soldered without component lead
    # - component space
    @ - soldered positive lead of anything/anode
    & - wire connection is routed under component
    " - wire connection is under component AND component is placed from down right corner to upper left corner
    [cbegsd] - collector, base, emitter, gate, source, drain
    : - copper strip/pad is cut/drilled out here
    [vL] - power rail and common wire, usually connector pin
    [<>] - input/output pins
    = - sector of continiou s copper strip

