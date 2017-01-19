;Author: Christopher Murray
;Question 1 Homework 1

#lang plai-typed
(define PI 3.141592653589793)

(define-type Shape
  [Square  (side : number)]
  [Circle  (radius : number)]
  [Triangle (height : number) (width :  number)])

(test (Square 2) (Square 2))
(test (Circle 2) (Circle 2))
(test (Triangle 3 3) (Triangle 3 3))

;This function computes the area of a Shape (defined above)
;- (Shape -> number)
(define (area [shape : Shape]) : number
  (type-case Shape shape
    [Square (s) (* s s)]
    [Circle (r) (* PI(* r r))]
    [Triangle (h w) (* h(* 0.5 w))]
    )
  )
 
 (test (area (Square 2)) 4)
 (test (area (Circle 5))78.53981633974483)
 (test (area (Triangle 2 9)) 9.0)

;This function takes a trinary digit, its position and computes
;its value in decimal
;- (number number -> number)
;#<procedure:ternary_pow>
(define (trinary_pow [product : number] [position : number]) : number
  (cond
    [(eq? position 0) product]
    [else (trinary_pow (* product 3) (- position 1))]))

;This function takes a list, calculates the first numbers
;value from trinary and calls itslef onto the rest of the list
;- ((listof number) number number -> number)
;#<procedure:helper>
(define (helper num [position : number] [sum : number]) : number
  (cond
    [(empty? num) sum]
    [else (helper (rest num) (+ position 1)
                  (+ sum (trinary_pow (first num) position)))]))

;This function takes a trinary number and computes its value in decimal
;- ((listof number) -> number)
;#<procedure:tern->num>
(define (tern->num num) : number
  (helper num 0 0))

(test (tern->num  empty) 0)
(test (tern->num  (list 1)) 1)
(test (tern->num  (list 2)) 2)
(test (tern->num (list 1 0 2 1)) 46)
(test (tern->num (list 1 2 0 1)) 34)

(define minutes-spent 120)
  
 