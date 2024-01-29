;d) Write a list to return the maximum value of the numerical atoms from a list, at superficial level


;myMax(A B) = nil, if a,b not numbers
;           = b, if a not number or b>a
;           = a, if b not number or a>=B


(defun myMax(a b)
  (cond
      ((and (not (numberp a) ) (not (numberp b))) nil)
      ((not (numberp b)) a)
      ((not (numberp a)) b)
      ((> a b) a)
      (T b)
  )
)



;maxList(l1..ln) = l1, if n=l1
;                = myMax(l1, maxList(l2..ln)) otherwise


(defun maxList(l)
  (cond
      ((null (cdr l)) (car l))
      ( (myMax (car l) (maxList(cdr l) ) ) )
  )
)


(print (maxList '(2 3 4 5 2 8 9 10 2) ) )