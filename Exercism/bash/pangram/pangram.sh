#!/usr/bin/env bash

main () {
    declare -A chars

    for char in $(echo "${1,,}" | tr -d " " | grep -o .); do
        printf -v num "%d\n" "'$char" 2>/dev/null
        if [[ "$num" -ge 97 ]] && [[ "$num" -le 122 ]]; then
            chars["$char"]=0
        fi
    done

    if [[ "${#chars[@]}" -eq 26 ]]; then
        echo "true"
    else
        echo "false"
    fi
}

main "$@"
