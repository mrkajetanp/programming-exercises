package reverse

func Reverse(input string) string {
	var result string = ""

	for _, r := range input {
		result = string(r) + result
	}

	return result
}
