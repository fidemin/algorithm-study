package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func max(arr ...int) int {
	max := 0
	for _, v := range arr {
		if v > max {
			max = v
		}
	}
	return max
}

func maxLengthDiff(i int, j int, k int, s1 string, s2 string) int {
	best := 0
	bad := 0
	l := 0
	n := len(s1)

	for {
		if i+l >= n || j+l >= n {
			best = max(best, l)
			break
		}

		if s1[i+l] != s2[j+l] {
			bad++
		}

		if bad > k {
			best = max(best, l)

			for s1[i] == s2[j] {
				i++
				j++
				l--
			}

			bad -= 1
			i += 1
			j += 1

		} else {
			l += 1
		}
	}
	return best
}

// Complete the substringDiff function below.
func substringDiff(k int32, s1 string, s2 string) int32 {
	length := len(s1)
	best := 0
	for i := 0; i < length; i++ {
		best = max(best, maxLengthDiff(0, i, int(k), s1, s2), maxLengthDiff(i, 0, int(k), s1, s2))

	}
	return int32(best)
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	tTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	t := int32(tTemp)

	for tItr := 0; tItr < int(t); tItr++ {
		kS1S2 := strings.Split(readLine(reader), " ")

		kTemp, err := strconv.ParseInt(kS1S2[0], 10, 64)
		checkError(err)
		k := int32(kTemp)

		s1 := kS1S2[1]

		s2 := kS1S2[2]

		result := substringDiff(k, s1, s2)

		fmt.Printf("%d\n", result)
	}

}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}
