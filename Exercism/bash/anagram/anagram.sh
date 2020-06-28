#!/usr/bin/env bash

is_anagram() {
    word="${1,,}"
    input="${2,,}"

    if [[ "$word" == "$input" ]]; then
        echo "false"
        return
    fi

    declare -a a
    for ((i=0; i<${#word}; i++)); do a[$i]="${word:$i:1}"; done
    declare -a b
    for ((i=0; i<${#input}; i++)); do b[$i]="${input:$i:1}"; done

    IFS=$'\n'
    a=($(sort <<<"${a[*]}"))
    b=($(sort <<<"${b[*]}"))
    unset IFS

    if [ "${a[*]}" == "${b[*]}" ]; then
        echo "true"
    else
        echo "false"
    fi
}

main () {
    word="${1}"
    result=""

    inputarr=(${2})
    for ((i=0; i<${#inputarr}; i++)); do
        if [ $(is_anagram "$word" "${inputarr[$i]}") == "true" ]; then
            result+="${inputarr[$i]} "
        fi
    done

    if [[ -z "$result" ]]; then
        echo ""
    else
        echo "${result::-1}"
    fi
}

main "$@"
