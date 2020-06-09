#!/usr/bin/env bash

function sum_of_squares {
    result=0
    for ((i = 1 ; i <= $(("$1")) ; i++)); do
        result=$(( "$result" + "$i"**2 ))
    done
    echo $(( "$result" ))
}


function square_of_sum {
    result=0
    for ((i = 1 ; i <= $(("$1")) ; i++)); do
        result=$(( "$result" + "$i" ))
    done
    echo $(( "$result"**2 ))
}

function difference {
    echo $(( $(square_of_sum "$1") - $(sum_of_squares "$1") ))
}

main () {
    if [[ "$1" == "sum_of_squares" ]]; then
        sum_of_squares "$2"
    fi

    if [[ "$1" == "square_of_sum" ]]; then
        square_of_sum "$2"
    fi

    if [[ "$1" == "difference" ]]; then
        difference "$2"
    fi
}

main "$@"
