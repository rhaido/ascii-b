```
     %           %
         %           %
            %           %
               %          %
                 %          %
                   %          %                   :::
                    %          %                ::::::
                 %%%%%%  %%%%%%%%%            ::::::::
              %%%%%ZZZZ%%%%%%   %%%ZZZZ     ::::::::::         ::::::
             %%%ZZZZZ%%%%%%%%%%%%%%ZZZZZZ  :::::::::::    :::::::::::::::::
             ZZZ%ZZZ%%%%%%%%%%%%%%%ZZZZZZZ::::::::::***:::::::::::::::::::::
          ZZZ%ZZZZZZ%%%%%%%%%%%%%%ZZZZZZZZZ::::::***:::::::::::::::::::::::
        ZZZ%ZZZZZZZZZZ%%%%%%%%%%ZZZZZZ%ZZZZ:::***:::::::::::::::::::::::
       ZZ%ZZZZZZZZZZZZZZZZZZZZZZZ%%%%% %ZZZ:**::::::::::::::::::::::
      ZZ%ZZZZZZZZZZZZZZZZZZZ%%%%% | | %ZZZ *:::::::::::::::::::
      Z%ZZZZZZZZZZZZZZZ%%%%%%%%%%%%%%%ZZZ::::::::::::::::::::::::::
       ZZZZZZZZZZZ%%%%%ZZZZZZZZZZZZZZZZZ%%%%:::ZZZZ:::::::::::::::::
         ZZZZ%%%%%ZZZZZZZZZZZZZZZZZZ%%%%%ZZZ%%ZZZ%ZZ%%*:::::::::::
            ZZZZZZZZZZZZZZZZZZ%%%%%%%%%ZZZZZZZZZZ%ZZ%:::*:::::::
            *:::%%%%%%%%%%%%%%%%%%%%%%%ZZZZZZZZZZ%%%*::::*::::
          *:::::::%%%%%%%%%%%%%%%%%%%%%%%ZZZZZ%%      *:::Z
         **:ZZZZ:::%%%%%%%%%%%%%%%%%%%%%%%%%%%ZZ      ZZZZZ
        *:ZZZZZZZ       %%%%%%%%%%%%%%%%%%%%%ZZZZ    ZZZZZZZ
       *::::ZZZZZZ         %%%%%%%%%%%%%%%ZZZZZZZ      ZZZ
        *::ZZZZZZ           Z%%%%%%%%%%%ZZZZZZZ%%
          ZZZZ              ZZZZZZZZZZZZZZZZ%%%%%
                           %%%ZZZZZZZZZZZ%%%%%%%%
                          Z%%%%%%%%%%%%%%%%%%%%%
                          ZZ%%%%%%%%%%%%%%%%%%%
                          %ZZZZZZZZZZZZZZZZZZZ
                          %%ZZZZZZZZZZZZZZZZZ
                           %%%%%%%%%%%%%%%%
                            %%%%%%%%%%%%%
                             %%%%%%%%%
                              ZZZZ
                              ZZZ
                             ZZ
                            Z

source: http://www.retrojunkie.com/asciiart/animals/bees.htm
```


## ASCii-pcB
Set of tools for working with matrix/perf/strip Boards in UNIX/Linux console
environment.

Put the fun back :D

### Motivation
At a certain moment I found, that I needed a method to automatically flip /
mirror boards I was drawing in my sketchbook - thus, this project was born :)

### Utilities

- **genboard** - generate either a matrix/perfboard or a stripboard; execute with
  **-h** argument for a quick help
- **flip** - flip the board from right to left (like turning page) or upside
  down; reads from standard input
- **colorboard** - color the board, reads from standard input. **REMEMBER** - this utility
  adds colors, and colors are ASCII escape sequences, i.e. it might lead to
  confusion if not aware
- **wiring** - show only soldering points and wiring between them
- **soldepads** - show only soldered pads and mark pads, which can be drilled
  off with ':'

### Examples of Usage
This command flips the boards upside down and colors it

    ./flip <boards/talking_electronics | ./colorboard

The following command flips the boards from right to left (like turning the page of a book) and colors it

    ./flip -h <boards/talking_electronics | ./colorboard

And this command get an advantage from UNIX pipes and does flipping + mirroring:

    ./flip -h <boards/monostable.cx | ./flip  

Show only solder points and wiring between the points:

    ./wiring < boards/astable.cx | ../flip -t | ../colorboard

Simple!

### Rules of Drawing the Boards
Actually, there is only one rule to follow - you can draw your matrix/strip boards
in any way, but keep them as understandable as possible.

### Type & Size of the Boards
Matrix/Perfboards & stripboards are the only supported types. Evidently, all routing
should be done on the backside, preferably without jumpers. Personally, I try
to avoid jumpers at all costs, but sometimes it just impossible to provide a compact
layout without them, thus symbol **j** was introduced.

### Control signs
The following signs are employed:

    - | \ / - wire point-to-point connections
    . - non-soldered copper pad/strip hole; strip is continuous in this place
    o - soldered copper pad with a component lead; might be an IC leg
    * - several connection wires soldered without component lead
    # - component space
    l - # + wire connection is routed under component vertically
    ~ - # + wire connection is routed under component horizontally
    % - # + wire connection is routed under component diagonally top right - down left
    & - # + wire connection is routed under component diagonally top left - down right
    @ - soldered positive lead of anything/anode
    c b e g s d - collector, base, emitter, gate, source, drain
    : - copper strip/pad is cut/drilled out here
    V v T - Positive power rail, negative power rail and common wire, usually soldered as connector pin
    < > - input/output pins
    j - jumper connection
    = - continuous copper strip

### Boundaries of the Components
Usually, boundaries and direction - thus placement - of a component are recognized by placing
hashes **#** between solderable terminals. Some components, like opamps, or cermet pots, can be
also outlined by hashes; if the boundaries are clearly marked, than normal wiring symbols can be used inside
hashed region to depict a wiring under component nicely and correctly.

For example, here is a cermet 3-terminal pot with 2 leads soldered together:

      |
    ##&##
    o +-o-
    #  /#
    ##o##
      |

This art shows the placement of component, and that two out of its three pins are soldered together.
If connecting wire crosses the border of the component without solder joint, isn't better to use **&**.

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

In reality, it was a diode, with the connecting wire going right under and along
the component, thus making impossible to use hashes. Happily, there is nothing
around to confuse us, and it's relatively easy to "decrypt", how the component should
be placed. In more difficult situations the **&** or **"** symbols should be added.
