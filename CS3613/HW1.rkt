;Author: Christopher Murray
;Question 1 Homework 1

#lang plai-typed
(define PI 3.141592653589793)

(define-type Shape
  [Square  (side : number)]
  [Circle  (radius : number)]
  [Triangle (height : number) (width :  number)])


(define (area [shape : Shape]) : number ;; (Shape -> number) Returns the area of a shape
  (type-case Shape shape
    [Square (s) (* s s)]
    [Circle (r) (* PI(* r r))]
    [Triangle (h w) (* h(* 0.5 w))]
    )
  )

(Square 2)
(Circle 5)
(Triangle 2 9)

(area (Square 2))
(area (Circle 5))
(area (Triangle 2 9))

(define (trinary_pow [product : number] [position : number]) : number
  (cond
    [(eq? position 0) product]
    [else (trinary_pow (* product 3) (- position 1))]))

(define (helper num [position : number] [sum : number]) : number
  (cond
    [(empty? num) sum]
    [else (helper (rest num) (+ position 1) (+ sum (trinary_pow (first num) position)))]))

(define (tern->num num) : number
  (helper num 0 0))

(tern->num (list 1 0 2 1))
(tern->num (list 1 2 0 1))



  
 