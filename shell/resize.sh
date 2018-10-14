#!/usr/bin/env sh

index=1
end='.png'
for file in `find . -name '*.png'`
do
  convert -resize 640 $file ${index}${end}
  echo ${index}${end}
  ((index++))
done 
