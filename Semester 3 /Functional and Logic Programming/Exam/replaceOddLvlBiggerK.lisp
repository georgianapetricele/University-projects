;Se dă o listă neliniară și se cere înlocuirea valorilor numerice care sunt mai mari decât o valoare k dată și sunt situate pe
;un nivel impar, cu numărul natural predecesor. Nivelul superficial se consideră 1.

;replaceOddLvlBiggerK(l,k,lvl) = l-1, atom(l) && l>k && lvl%2=1
;                              = l, atom(l)
;                              = U replaceOddLvlBiggerK(l(i),k,lvl+1), otherwise

(defun replaceOddLvlBiggerK(l k lvl)
  (cond 
      ((and(and (numberp l) (>= l k)) (=(mod lvl 2)1) ) (- l 1))
      ((atom l) l)
      (t (mapcar #'(lambda(x) (replaceOddLvlBiggerK x k (+ lvl 1)))l) )
  )
)


(defun main2(l k)
  (replaceOddLvlBiggerK l k 0)
)
