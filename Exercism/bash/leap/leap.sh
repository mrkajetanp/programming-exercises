#!/usr/bin/env bash

factor () {
    echo $(( "$1" % "$2"  ))
}

main () {
    if [ "$#" -ne 1 ]; then
        echo "Usage: leap.sh <year>"
        return 1
    fi

    re='^[0-9]+$'
    if ! [[ "$1" =~ $re ]] ; then
        echo "Usage: leap.sh <year>"
        return 1
    fi

    if [[ $(factor "$1" 4) -eq 0 ]] && ([[ $(factor "$1" 100) -ne 0 ]] || [[ $(factor "$1" 400) -eq 0 ]]); then
        echo "true"
        return
    fi

    echo "false"
}

main "$@"
