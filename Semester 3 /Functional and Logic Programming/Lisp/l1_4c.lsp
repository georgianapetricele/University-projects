;c)Write a function that, with a list given as parameter, inverts only continuous
;sequences of atoms. Example:
;(a b c (d (e f) g h i)) ==> (c b a (d (f e) i h g))




(defun myAppend(L1 L2)
  (if (null L1)
    L2
    (cons (car L1) (myAppend (cdr L1) L2) ) 
  )
)  


;reverse(l1..ln) = nil, if l-null
;                = reverse(l2..ln) U l1, otherwise

(defun myreverse(L)
    (cond
        ( (null L) nil)
        (T (myAppend (myreverse (cdr L)) (list (car L) ) ) )
    )
)

;invertList(l1..ln, Acc) = reverse(Acc), if l-null
;                        = reverse(Acc) U invertList(l1 nil) U invertList(l2..ln,nil), if l1-list
;                        = invertList(l2...ln,acc U l1),otherwise


(defun invertList(L Acc)
    (cond
        ( (null L) (myreverse Acc))
        ; if l not a list
        ( (atom L) nil ) 
        ;list -> we construct a list formed of the inverted L1 list and the inverted rest of the list, 
		    ;to which we append the reverse of the aux list (the list we obtaind so far on a superficial level)
        ( (listp (car L) ) (myAppend (myreverse Acc) (cons (invertList (car L) nil) (invertList (cdr L) nil) )  ) )
		    ;atom -> we invert the rest of the list and we append L1 to the aux list
		    (T (invertList(cdr L) (myAppend Acc (list(car L) ) )) )
		    
    )
)


(print (invertList '(a b c (d (e f) g h i)) nil))