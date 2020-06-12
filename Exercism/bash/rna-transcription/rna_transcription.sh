#!/usr/bin/env bash

main() {
    declare -A rna
    rna['C']='G'
    rna['G']='C'
    rna['T']='A'
    rna['A']='U'

    result=""

    for char in $(echo "${1}" | tr -d " " | grep -o .); do
        if [[ "${rna[$char]}" == "" ]]; then
            echo "Invalid nucleotide detected."
            return 1
        fi
        result+=${rna[$char]}
    done

    echo "$result"
}

main "$@"
