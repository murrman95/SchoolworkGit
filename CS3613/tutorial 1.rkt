#lang slideshow

(require pict/flash)
(require racket/class
         racket/gui/base)

(define c (circle 10))
(define r (rectangle 10 20))

(define (square n)
  (filled-rectangle n n))

(define (four p)
  (define two-p (hc-append p p))
  (vc-append two-p two-p))

(define (checker p1 p2)
  (let ([p12 (hc-append p1 p2)]
        [p21 (hc-append p2 p1)])
    (vc-append p12 p21)))

(define (checkerboard p)
  (let* ([rp (colorize p "red")]
         [bp (colorize p "black")]
             (c (checker rp bp))
             (c4 (four c)))
    
             (four c4)))
(define (series mk)
  (hc-append 4 (mk 5) (mk 10) (mk 20)))

(define (rgb-series mk)
  (vc-append
   (series (lambda (sz) (colorize (mk sz) "red")))
   (series (lambda (sz) (colorize (mk sz) "green")))
   (series (lambda (sz) (colorize (mk sz) "blue")))))

(define (rgb-maker mk)
  (lambda (sz)
    (vc-append (colorize (mk sz) "red")
               (colorize (mk sz) "green")
               (colorize (mk sz) "blue"))))

(define rainbowL (list "red" "orange" "yellow" "green" "blue" "indigo" "violet"))



(define (rainbow shape)
  (map (lambda (color)
          (colorize shape color))
        (list "red" "orange" "yellow" "green" "blue" "purple")))

(define f (new frame% [label "My Art"]
               [width 300]
               [height 300]
               [alignment '(center center)]))
   
