package acronym

import (
	"bytes"
	"strings"
)

func Abbreviate(s string) string {
	s = strings.ReplaceAll(s, "-", " ")
	s = strings.ReplaceAll(s, "_", "")
	var words = strings.Split(s, " ")
	var b bytes.Buffer

	for _, w := range words {
		if w != "" {
			b.WriteByte(w[0])
		}
	}

	return strings.ToUpper(b.String());
}
