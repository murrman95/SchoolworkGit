#lang plai

(define (stringify s)
                   (number->string s))

(define (comma-join formatter list)
  (helper formatter list ""))

(define (helper formatter list rString)
  (cond
   [(empty? list) rString]
   [(empty? (rest list)) (string-append rString (formatter (first list)))]
   [else (helper formatter (rest list) (string-append
                                         rString
                                         (string-append
                                          (formatter
                                           (first list)
                                          )
                                         ",")))]))
                                        