# Pi

Calculate the digits of PI on-the-fly and print these on the screen.

> **note**
> This program is essentially similar to `pi`, but now modified such that it
> can be completely executed from RAM. The program requires about 1kb of RAM,
> so it needs to start preferably somewhere early in RAM. Here, we have set it
> to `0x7000`.

## Algorithm

The digits of PI are calculated using the [Spigot algorithm](https://en.wikipedia.org/wiki/Spigot_algorithm)
which has the main advantage that it relies only on integer arithmetics. The
algorithm has been obtained from the [code provided by Haenel](https://www.jjj.de/hfloat/spigot.haenel.txt).

## Compilation

When using Bash for Windows, simply run

```
./compile.sh
```

If you want to test the program in the M2000.exe emulator of Marcel de Kogel,
adjust the `run.sh` file and execute it.