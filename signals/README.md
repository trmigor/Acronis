# Signals

Simple program with infinite loop. It reacts on receiving signals such as SIGINT (2) and SIGTERM (15) by printing a message to stderr and exiting.

To compile use

```(bash)
make
```

To test for SIGINT, use

```(bash)
./signal &
killall -2 signal
```

To test for SIGTERM, use

```(bash)
./signal &
killall -15 signal
```

To cleanup, use

```(bash)
make clean
```
