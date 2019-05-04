# Fillit1820

The **fillit** project is the first mandatory group project from the [42](https://www.42.fr) curriculum. **Fillit1820** is a unit test: there are only 1820 possible arrangements of 4 block characters ('#') and 12 empty characters ('.') in a 4x4 square to form a tetrimino, and 113 valid solutions. We can test them all using a systematic approach.

## Useful links
- The [Fillit PDF Subject](https://github.com/AugustinLopez/Fillit1820/blob/master/rcs/fillit.pdf)

## How to use

```
git clone https://github.com/AugustinLopez/Fillit1820.git
cd Fillit1820
make
./Fillit1820 /absolute/path/to/your/fillit/executable
```
- Fillit1820 expect a valid path to your fillit executable. Other argument will result in an undefined behavior.
- Fillit1820 uses several files from the /assets directory. The program will not work properly without them.
- Fillit1820 has no tolerance for syntax errors: your fillit program should find 113 valid solutions and return '**error**' in every other cases. 
- You may find additional ressources in the /otherTest directory. Note that those files are not used by Fillit1820: they must be tested manually.

## Example
```
./Fillit1820 ~/Not_working/fillit
Error / the piece is:
#..#
#...
#...
....


And your result is:
.A.
AA.
.A.


./Fillit1820 ~/Working/fillit
Congratulations, your fillit works with basic inputs!
```

## Trivia
This program was created early in my curriculum. It is a bit wonky (a simple bash script would probably do the job better) but it works just fine.
