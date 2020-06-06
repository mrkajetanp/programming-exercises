#!/usr/bin/env bash
#
main () {
    result=""

    for ((i = $(("${#1}"-1)) ; i >= 0 ; i--)); do
        result+="${1:$i:1}"
    done

    echo "$result"
}

main "$@"
