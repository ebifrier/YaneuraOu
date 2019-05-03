#!/bin/bash

echo "download started"
pwd

echo "eval data downloading.."
wget "https://drive.google.com/uc?export=download&id=1NV6SK9kAZ7xKD8SFXPSY81DyzaiajBXJ" -O qzilla_nn.zip
if [ $? != 0 ]; then
  echo "download failed(wget)"
  exit 1
fi

echo "eval data unzip.."
unzip qzilla_nn.zip
if [ $? != 0 ]; then
  echo "download failed(unzip)"
  exit 1
fi

rm -rf eval
mv qzilla_nn eval

echo "loading eval.bin.."
cat eval/*.bin > /dev/null 2>&1
