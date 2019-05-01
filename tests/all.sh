#!/bin/bash

# # テストするのはとりあえずtournament-sse42のみ(avx2が無いインスタンスを引くことがあるので)
# if [ "x$1" != "xtournament-sse42" ]; then
#   echo "testing cancel(!= $1)"
#   exit 0
# fi

echo "testing started"
pwd

echo "eval data downloading.."
wget "https://drive.google.com/uc?export=download&id=182H3qNkEerRtrvheN85t-UDkP0FyYt9J" -O qzilla_nn.7z
if [ $? != 0 ]; then
  echo "testing failed(wget)"
  exit 1
fi

echo "eval data unzip.."
7z x qzilla_nn.7z
if [ $? != 0 ]; then
  echo "testing failed(7z x)"
  exit 1
fi

mv qzilla_nn eval

echo "loading eval.bin.."
cat eval/*.bin > /dev/null 2>&1

./bench.sh

