@echo Filtering Data...
@echo off
java -cp ..\ Fir.FirTester -SampleFile sound.txt -CoeffFile coeff.txt -SampleNum 30000 -CoeffNum 21 -Cycle 3
