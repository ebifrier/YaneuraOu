#!/bin/bash

echo "download started"
pwd

echo "eval data downloading.."
wget "https://drive.google.com/uc?export=download&id=182H3qNkEerRtrvheN85t-UDkP0FyYt9J" -O qzilla_nn.7z
if [ $? != 0 ]; then
  echo "download failed(wget)"
  exit 1
fi

echo "eval data unzip.."
7z x qzilla_nn.7z
if [ $? != 0 ]; then
  echo "download failed(7z x)"
  exit 1
fi

mv qzilla_nn eval

echo "loading eval.bin.."
cat eval/*.bin > /dev/null 2>&1
