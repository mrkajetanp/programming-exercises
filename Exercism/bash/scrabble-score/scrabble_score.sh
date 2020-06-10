#!/usr/bin/env bash

main () {
    result=0

    declare -A scores

    scores['a']=1
    scores['e']=1
    scores['i']=1
    scores['o']=1
    scores['u']=1
    scores['l']=1
    scores['n']=1
    scores['r']=1
    scores['s']=1
    scores['t']=1
    scores['d']=2
    scores['g']=2
    scores['b']=3
    scores['c']=3
    scores['m']=3
    scores['p']=3
    scores['f']=4
    scores['h']=4
    scores['v']=4
    scores['w']=4
    scores['y']=4
    scores['k']=5
    scores['j']=8
    scores['x']=8
    scores['q']=10
    scores['z']=10

    for char in $(echo "${1,,}" | tr -d " " | grep -o .); do
        result=$(( "$result" + "${scores["$char"]}"))
    done


    echo "$result"
}

main "$@"
