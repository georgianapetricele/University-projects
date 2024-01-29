;4.
;a) Write a function to return the sum of two vectors.

;sumVectors(a1..an,b1..bn) = NIL, if n=0
;                          = (a1+b1) + sumVectors(a2..an,b2..bn),otherwise
;
;

(defun sumVectors(V1 V2)
    (if (null V1)
        NIL
        (cons (+ (car V1) (car V2)) (sumVectors(cdr V1)(cdr V2)))
    )

)
    
(print (sumVectors '(5 4 3)'(3 4 5)))
  