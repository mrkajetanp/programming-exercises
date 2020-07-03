package raindrops

import (
	"bytes"
	"strconv"
)

func Convert(input int) (string) {
	var result bytes.Buffer

	if input % 3 == 0 {
		result.WriteString("Pling");
	}

	if input % 5 == 0 {
		result.WriteString("Plang");
	}

	if input % 7 == 0 {
		result.WriteString("Plong");
	}

	if result.Len() == 0 {
		result.WriteString(strconv.Itoa(input));
	}

	return result.String();
}
