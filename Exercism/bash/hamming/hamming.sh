#!/usr/bin/env bash

main () {
    result=0

    if [ "$#" -ne 2 ]; then
        echo "Usage: hamming.sh <string1> <string2>"
        return 1
    fi

    if [[ ${#1} != ${#2} ]]; then
        echo "left and right strands must be of equal length"
        return 1
    fi

    for (( i = 0 ; i < ${#1} ; i++ )); do
        if [[  "${1:$i:1}" != "${2:$i:1}" ]]; then
            result=$((result + 1))
        fi
    done

    echo $result
}

main "$@"
