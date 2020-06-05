main () {
    len="${#1}"

    result=0
    for digit in $(echo "$1" | grep -o .); do
        result=$(( $result + $digit**$len ))
    done

    if [[ "$result" == "$1" ]]; then
        echo "true"
    else
        echo "false"
    fi
}

main "$@"
