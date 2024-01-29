;nr sublists -condition maximum number on all odd levels is even

 (defun linearize3(l) ;lin + keep only numbers
    (cond
      ((null l) nil)
      ((numberp l) (list l)) ;use it to get rid off nil
      ((atom l) nil)
      (t (mapcan #'linearize3 l)) ;use it to append all lists into one
    )
 )
 
 ;(print (linearize '(2 (A 4 5) 4)))
 
 
 ;max(l1..ln) = l1, n=1
 
 (defun maxi(l)
    (cond
         ((null (cdr l)) (car l))
         (t (max (car l) (maxi (cdr l) ) ) )
    )
 )


(defun condMax(l)
   (cond
        ((null (linearize3 l)) nil)
        ((= (mod (maxi (linearize3 l)) 2)0) t)
        (t nil)
      )
)

(defun countSublists(l lvl)
  (cond 
    ((atom l) 0)
        ((and (=(mod lvl 2)1) (listp l) (condMax l))
        (+ 1(apply #'+(mapcar #'(lambda (x) (countSublists x (+ lvl 1)))l)))
        )
    (t (apply #'+(mapcar #'(lambda (x) (countSublists x (+ lvl 1))) l)))
  )
)

(print (countSublists '(a (b 8) (1 c 8) (1(8 f)) (((g)8)8) ) -1)) 
