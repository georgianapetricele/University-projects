;b) Write a function to get from a given list the list of all atoms, on any 
;level, but on the same order. Example:
;(((A B) C) (D E)) ==> (A B C D E)



;myAppend(l1..ln,b1..bm) = b1..bm, if l1-null
;                        = l1 U myAppend(l2..ln,b1..bm)


(defun myAppend(L1 L2)
  (if (null L1)
    L2
    (cons (car L1) (myAppend (cdr L1) L2) ) 
  )
)  


;atomsList(l1..ln) = NIL, if n=0
;                  = atomsList(l1) U atomsList(l2..ln), if l1-list
;                  = l1 U atomsList(l2..ln) otherwise
;

(defun atomsList(L)
    (cond
        ( (null L) NIL)
        ( (listp (car L) ) (myAppend (atomsList(car L)) (atomsList(cdr L) ) ) )
        ( T (cons (car L)  (atomsList(cdr L)) ) )
    )
)

(print (atomsList '(((A B) C) (D E)) ) )