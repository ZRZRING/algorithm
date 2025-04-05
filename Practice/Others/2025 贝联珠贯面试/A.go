package main

import (
	"fmt"
	"math/rand"
	"strconv"
)

func main() {
	mp := make(map[string]bool)
	for len(mp) < 100 {
		opt := rand.Int63() % 2
		if opt == 0 {
			// 加法
			a, c := (rand.Int63()%99 + 1), (rand.Int63()%99 + 1)
			if a > c {
				a, c = c, a
			}
			b := c - a
			st := strconv.FormatInt(a, 10) + " + " + strconv.FormatInt(b, 10) + " = "
			if mp[st] {
				continue
			}
			mp[st] = true
		} else {
			// 减法
			a, b := (rand.Int63()%99 + 1), (rand.Int63()%99 + 1)
			if a < b {
				a, b = b, a
			}
			st := strconv.FormatInt(a, 10) + " - " + strconv.FormatInt(b, 10) + " = "
			if mp[st] {
				continue
			}
			mp[st] = true
		}
	}
	for x := range(mp) {
		fmt.Println(x)
	}
}
