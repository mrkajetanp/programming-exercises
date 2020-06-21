#!/usr/bin/env bash

main () {
    a=0
    c=0
    g=0
    t=0

    for (( i = 0 ; i < ${#1} ; i++ )); do
        case "${1:$i:1}" in
            'A')
                a=$(( "$a" + 1 ))
                ;;
            'C')
                c=$(( "$c" + 1 ))
                ;;
            'G')
                g=$(( "$g" + 1 ))
                ;;
            'T')
                t=$(( "$t" + 1 ))
                ;;
            *)
                echo "Invalid nucleotide in strand"
                return 1
        esac
    done

    echo $"A: $a\nC: $c\nG: $g\nT: $t"
}

main "$@"
