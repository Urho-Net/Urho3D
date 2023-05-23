#!/bin/bash

while getopts i:t:e: option
do
case "${option}"
in
i) INPUT=${OPTARG};;
t) TEXT=${OPTARG};;
e) ECHO=${OPTARG};;
esac
done

if [[ "$INPUT" != "" ]]; then
    while IFS= read -r line
    do
    arrIN=(${line//-/ })
    name="$(echo -e " ${arrIN[2]}" | tr -d '[:space:]')"
    start="$(echo -e " ${arrIN[0]}" | tr -d '[:space:]')"
    end="$(echo -e " ${arrIN[1]}" | tr -d '[:space:]')"
    ./AssetImporter.exe anim ${INPUT} ${name} -split ${start}  ${end}
    #echo \"${name}\",
    done < "$TEXT"
fi

if [[ "$ECHO" != "" ]]; then
    while IFS= read -r line
    do
    arrIN=(${line//-/ })
    name="$(echo -e " ${arrIN[2]}" | tr -d '[:space:]')"
    start="$(echo -e " ${arrIN[0]}" | tr -d '[:space:]')"
    end="$(echo -e " ${arrIN[1]}" | tr -d '[:space:]')"
    echo \"${name}\",
    done < "$ECHO"
fi