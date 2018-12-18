# Fillit1820
Check if a fillit can deal with the 1820 possibles combinations of 4 cubes among 16 places. Also contains some non-automatic tests in "/otherTest" that you might want to try.

## Description
Fillit1820 is a simple program that will run your fillit program 1820 times, testing each 4-combinations of cube among 16 possibles places.

```
Examples:
####
....
....
....

but also:
....
###.
#...
....

and also: 
.###
#...
....
....

and even: 
...#   
#...
...#
#...

etc...
```

Your program should find the 113 valid solutions and return 'error' for every other cases.

## How to use
Use make to create the executable Fillit1820.
```
./Fillit1820
./assets/
       ./valid.txt
       ./piece.txt
```

```Usage: ./Fillit1820 path_to_fillit```

**Example :** ./Fillit1820 ../myvogsphere/fillit

This is a WIP, so expect this thing to break down at any moment.
