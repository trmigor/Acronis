# Shared library

Simple shared library, containing functionality of integral computation by Cotes formula.

To compile only library, use

```(bash)
make create_lib
```

To compile it with testing program, use

```(bash)
make
```

Testing program implements integral computation for function $f(x) = x^2$. To run it with default borders and accuracy, use

```(bash)
./integrate
```

To specify borders, use

```(bash)
./integrate <left_border> <right_border>
```

changing `<left_border>` and `<right_border>` with numbers.

To specify accuracy, use

```(bash)
./integrate <left_border> <right_border> <accuracy>
```

changing `<left_border>`, `<right_border>` and `<accuracy>` with numbers.

To cleanup use

```(bash)
make clean
```
