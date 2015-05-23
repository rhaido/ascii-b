## CITRONIX - CommandLine ElectronIcs for UNIX
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

$ ./reverse <boards/talking_electronics | ./colorboard

This command flips the boards from right to left and colors it

$ tac <boards/talking_electronics | ./colorboard

This command flips the boards from upside down and colors it
