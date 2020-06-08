#!/usr/bin/env bash

main () {
    if [[ "$1" == "total" ]]; then
        echo "18446744073709551615"
        return 0
    fi

    if [[ "$1" -eq 64 ]]; then
        echo "9223372036854775808"
        return 0
    fi

    if [[ "$1" -lt 1 ]] || [[ "$1" -gt 64 ]]; then
        echo "Error: invalid input"
        return 1
    fi

    result=$(( 2**("$1"-1) ))
    echo "$result"
}

main "$@"
