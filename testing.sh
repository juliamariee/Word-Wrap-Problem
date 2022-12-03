#!/bin/bash
rm -r goCrazy/*
make
./makeTest 5 160 5 24
mkdir ./goCrazy/outputs
let number="1"
for file in ./goCrazy/*
do
  #./wordWrap $file $output 1 
  echo $number

  output=./goCrazy/outputs/out_${number}_dp.txt
  ./wordWrap $file $output 1;
  echo $number >> ./goCrazy/outputs/dpOuts.txt 
  tail -n 2 $output >> ./goCrazy/outputs/dpOuts.txt

  output=./goCrazy/outputs/out_${number}_g.txt;
  ./wordWrap $file $output 0;
  echo $number >> ./goCrazy/outputs/gOuts.txt 
  tail -n 2 $output >> ./goCrazy/outputs/gOuts.txt

  number=$((number + 1))
done
