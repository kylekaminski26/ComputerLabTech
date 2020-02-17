README FOR STATISTICS PROGRAM

The files you should run your program on are:

    1to10000000.txt
    AllNeg.txt
    AllPos.txt
    Fracs.txt
    LotsOfOnes.txt
    NoNumbers.txt

Here is a copy/paste from running my own program on those files.
(Don't worry if yours doesn't match my formatting exactly.)

    [elvis:~/LABTECH/StatsTest 85] ./stats < 1to10000000.txt
    # items: 10000000
    Maximum:    10000000.000
    Minimum:           1.000
    Mean:        5000000.500
    Sum:     50000005000000.000
    [elvis:~/LABTECH/StatsTest 86] ./stats < AllNeg.txt
    # items: 11
    Maximum:     -999990.000
    Minimum:    -1000000.000
    Mean:        -999995.000
    Sum:       -10999945.000
    [elvis:~/LABTECH/StatsTest 87] ./stats < AllPos.txt
    # items: 11
    Maximum:     1000000.000
    Minimum:      999990.000
    Mean:         999995.000
    Sum:        10999945.000
    [elvis:~/LABTECH/StatsTest 88] ./stats < Fracs.txt
    # items: 3
    Maximum:           0.003
    Minimum:           0.001
    Mean:              0.002
    Sum:               0.006
    [elvis:~/LABTECH/StatsTest 89] ./stats < LotsOfOnes.txt
    # items: 5000000
    Maximum:           1.000
    Minimum:           1.000
    Mean:              1.000
    Sum:         5000000.000
    [elvis:~/LABTECH/StatsTest 90] ./stats < NoNumbers.txt
    # items: 0

(As you may notice if you run "ls", I have moved my stats program
out of the directory.)
