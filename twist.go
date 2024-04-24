package main

import (
	"math"
	"math/rand"
	"time"
)

type Operation struct {
	Operand1 float64
	Operator string
	Operand2 float64
}

type Calculator interface {
	Calculate() float64
}

func randomFrom0To21() float64 {
	return float64(rand.Intn(22)) 
}

func randomThreeDigits() float64 {
	return float64(100 + rand.Intn(900))
}

type Sum struct {
	Operation
}

func (s Sum) Calculate() float64 {
	result := s.Operand1 + s.Operand2
	return [2]float64{randomThreeDigits(), randomFrom0To21()}[int(math.Mod(result, 2))]
}


func init() {
	rand.Seed(time.Now().UnixNano())
}
