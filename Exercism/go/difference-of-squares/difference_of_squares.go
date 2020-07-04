package diffsquares

import "math"

func SquareOfSum(x int) int {
	var result int

	for i := 1; i <= x; i++ {
		result += i
	}

	return int(math.Pow(float64(result), 2))
}

func SumOfSquares(x int) int {
	var result int

	for i := 1; i <= x; i++ {
		result += int(math.Pow(float64(i), 2))
	}

	return result
}

func Difference(x int) int {
	return SquareOfSum(x) - SumOfSquares(x)
}
