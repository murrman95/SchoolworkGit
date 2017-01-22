
#lang plai

(define-type Jpair
  [jpair (key : string) (val : JSON)])

(define-type JSON
   (jnumber (jnumber : number))
   (jarray (list : (listof JSON)))
   (jstring (jstring : string))
   (jdict (jdict : (listof Jpair)))
   (jboolean (jboolean : boolean))
  )

(test (jstring? (jstring "hello"))  #t)
(test (jarray? (jarray (list (jboolean true)
                           (jnumber 10))))  #t)
(test (jdict? (jdict (list (jpair "happy"
                                 (jboolean true))
                          (jpair "cookies"
                                 (jnumber 10)))))  #t)

(define (json->string jVal) : string
  (type-case JSON jVal
    [jnumber (jNum) (number->string jNum)]
    [jstring (jStr) jStre]
    [jboolean (jBool) (boolean->string jBool)]
    [jarray (JSList) (string-append "["(string-append (map (json->string) (JSList)) "]"))]
    [jdict (JPList) (map (jpair->string) (JPList))]))

(define (jpair->string jpVal) : string
  (type-case JPair jpVal
    [JPair (jkey jval) (jkey (json->string jval))]))

