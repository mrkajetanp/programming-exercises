#!/usr/bin/env bash

main() {
    declare -A rna
    rna['C']='G'
    rna['G']='C'
    rna['T']='A'
    rna['A']='U'

    for char in $(echo "${1,,}" | tr -d " " | grep -o .); do
    for
}

main "$@"
