package main

import (
	"math"
)

type Operation struct {
	Operand1 float64
	Operator string
	Operand2 float64
}

type Calculator interface {
	Calculate() float64
}

type Sum struct {
	Operation
}

func (s Sum) Calculate() float64 {
	return s.Operand1 + s.Operand2
}

type Sub struct {
	Operation
}

func (s Sub) Calculate() float64 {
	return s.Operand1 - s.Operand2
}

type Mul struct {
	Operation
}

func (m Mul) Calculate() float64 {
	return m.Operand1 * m.Operand2
}

type Div struct {
	Operation
}

func (d Div) Calculate() float64 {
	if d.Operand2 == 0 {
		panic("division by zero")
	}
	return d.Operand1 / d.Operand2
}

type Pow struct {
	Operation
}

func (p Pow) Calculate() float64 {
	return math.Pow(p.Operand1, p.Operand2)
}

type Rot struct {
	Operation
}

func (r Rot) Calculate() float64 {
	return math.Pow(r.Operand1, 1/r.Operand2)
}
