package isogram

import (
	"strings"
)

func IsIsogram(input string) bool {
	var letters = make(map[rune]bool)

	for _, c := range strings.ToLower(input) {
		if c == ' ' || c == '-' {
			continue
		}

		_, contains := letters[c]

		if contains {
			return false
		}

		letters[c] = true
	}

	return true
}
