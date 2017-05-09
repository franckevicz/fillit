# fillit

Program will take a file as parameter which contains a list of Tetriminos and arrange them to create the **smallest square** possible. Obviously, main goal is to find this smallest square in the minimal amount of time, despite a exponentially growing number of possibilities each time a piece is added.

The whole task is in [this pdf](https://github.com/franckevicz/fillit/blob/master/fillit.en.pdf). It's not described very clear as long as it's a part of the task.
Here is just a quick explanation.

Executable `./fillit` must take as parameter one (and only one) file which contains a list of Tetriminos to arrange. This file has a very specific format : every Tetriminos description consists of 4 lines and each Tetriminos are separated by an empty line

If the number of parameters given to your executable is different from 1, your program must display his usage and exit properly. If you dont know what a usage is, execute the command cp without arguments in your Shell to get an idea.
The description of a Tetriminos must respect the following rules :
+ Precisely 4 lines of 4 characters followed by a new line.
+ A Tetriminos is a classic piece of Tetris composed of 4 blocks.
+ Each character must be either a ’#’ when the character is one of the 4 blocks of a Tetriminos or a ’.’ if it’s empty.
+ Each block of a Tetriminos must be in contact with at least one other block on any of his 4 sides.

That's nice tetraminos:
```
....    ....    ####    ....    .##.    ....    .#..    ....    ....
..##    ....    ....    ....    ..##    .##.    ###.    ##..    .##.
..#.    ..##    ....    ##..    ....    ##..    ....    #...    ..#.
..#.    ..##    ....    ##..    ....    ....    ....    #...    ..#.
```

And that's NOT:
```
###    ...#    ##...   #.      ....    ..##    ####    ,,,,    .HH.
...#    ..#.    ##...   ##      ....    ....    ####    ####    HH..
....    .#..    ....    #.      ....    ....    ####    ,,,,    ....
....    #...    ....            ....    ##..    ####    ,,,,    ....
```

Example of work

```
$> cat sample.fillit | cat -e
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$
....$
.##.$
.##.$
....$
$
....$
....$
##..$
.##.$
$
##..$
.#..$
.#..$
....$
$
....$
###.$
.#..$
....$
$> ./fillit sample.fillit | cat -e
ABBBB.$
ACCCEE$
AFFCEE$
A.FFGG$
HHHDDG$
.HDD.G$
```
