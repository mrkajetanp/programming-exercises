#!/usr/bin/env bash
#
main () {
    result=""

    for word in $(echo "$1" | tr -d "*_" | tr "-" " " | tr " " "\n")
    do
        result+="${word:0:1}"
    done

    echo ${result^^}
}

main "$@"
