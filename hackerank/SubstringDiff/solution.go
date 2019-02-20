package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var cache [1500][1500]int32

func find_min_diff(n int, s1 string, s2 string) int32 {
	length := len(s1)
	min := int32(987654321)
	for i := 0; i < length-n+1; i++ {
		for j := 0; j < length-n+1; j++ {
			ret := int32(0)
			if s1[i] != s2[j] {
				ret = int32(1)
			}

			if n != 1 {
				ret = ret + cache[i+1][j+1]
			}

			cache[i][j] = ret
			if ret < min {
				min = ret
			}
		}
	}
	return min
}

// Complete the substringDiff function below.
func substringDiff(k int32, s1 string, s2 string) int32 {
	length := len(s1)
	ret := 0
	for n := 1; n <= length; n++ {
		min_diff := find_min_diff(n, s1, s2)
		if min_diff <= k {
			ret = n
		}
	}

	return int32(ret)
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
