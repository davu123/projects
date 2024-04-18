package main

import (
	"log"
	"net/http"
)

func main() {
	http.HandleFunc("/result", resultHandler)
	log.Println("Server starting on port :8080...")
	if err := http.ListenAndServe(":8080", nil); err != nil {
		log.Fatal("ListenAndServe: ", err)
	}
}
