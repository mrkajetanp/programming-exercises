package twofer

import "fmt"

func ShareWith(names ...string) string {
	var result string;
	if len(names) == 0 || names[0] == "" {
		result = "you";
	} else {
		result = names[0];
	}

	return fmt.Sprintf("One for %s, one for me.", result);
}
