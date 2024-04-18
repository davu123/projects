package main

import (
	"encoding/json"
	"fmt"
	"net/http"
	"strconv"
	"strings"
)

func resultHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method != "GET" {
		http.Error(w, `{"code": 405, "error": "method not allowed"}`, http.StatusMethodNotAllowed)
		return
	}

	op := r.URL.Query().Get("op")
	if op == "" {
		http.Error(w, `{"result": "invalid expression", "op": "empty operation"}`, http.StatusBadRequest)
		return
	}

	result, err := parseAndCalculate(op)
	if err != nil {
		http.Error(w, `{"result": "invalid expression", "op": "`+op+`"}`, http.StatusBadRequest)
		return
	}

	response, _ := json.Marshal(map[string]interface{}{
		"result": result,
		"op":     op,
	})

	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(http.StatusOK)
	w.Write(response)
}

func parseAndCalculate(input string) (float64, error) {
	parts := strings.Fields(input)
	if len(parts) != 3 {
		return 0, fmt.Errorf("invalid format")
	}

	operand1, err1 := strconv.ParseFloat(parts[0], 64)
	operator := parts[1]
	operand2, err2 := strconv.ParseFloat(parts[2], 64)

	if err1 != nil || err2 != nil {
		return 0, fmt.Errorf("invalid numbers")
	}

	var calc Calculator
	switch operator {
	case "+", "sum":
		calc = Sum{Operation{operand1, operator, operand2}}
	case "-", "sub":
		calc = Sub{Operation{operand1, operator, operand2}}
	case "*", "mul":
		calc = Mul{Operation{operand1, operator, operand2}}
	case "/", "div":
		calc = Div{Operation{operand1, operator, operand2}}
	case "^", "pow":
		calc = Pow{Operation{operand1, operator, operand2}}
	case "&", "rot":
		calc = Rot{Operation{operand1, operator, operand2}}
	default:
		return 0, fmt.Errorf("unsupported operation")
	}

	return calc.Calculate(), nil
}
