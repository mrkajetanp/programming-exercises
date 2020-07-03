#!/usr/bin/env bash

main() {
    a="$2"
    b="$3"
    c="$4"

    errs="$a <= 0 || $b <= 0 || $c <= 0 || $a+$b < $c || $b+$c<$a || $c+$a<$b"
    if (( $(echo "$errs" | bc -l) )); then
        echo "false"
        return
    fi

    case "$1" in
        equilateral)
            if (( $(echo "$a == $b && $b == $c" | bc -l) )); then
                echo "true"
                return
            fi
            ;;
        isosceles)
            if (( $(echo "$a == $b || $b == $c || $a == $c" | bc -l) )); then
                echo "true"
                return
            fi
            ;;
        scalene)
            if (( $(echo "$a != $b && $b != $c && $a != $c" | bc -l) )); then
                echo "true"
                return
            fi
            ;;
    esac

    echo "false"
}

main "$@"
