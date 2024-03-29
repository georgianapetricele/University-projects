; C. Un arbore n-ar se reprezintă în LISP astfel ( nod subarbore1 subarbore2 .....). 
;    Se cere să se determine înălțimea unui nod în arbore. 
;    Se va folosi o funcție MAP.

; Exemplu pentru arborele (a (b (g)) (c (d (e)) (f)))
; a) nod=e => înălțimea e 0 
; b) nod=v => înălțimea e -1 
; c) nod=c => înălțimea e 2


; myMax(a b)
; = a, if a >= b
; = b, otherwise

(defun myMax(a b)
  (cond
    ((>= a b) a)
    (t b)
  )
)

; maxList(l1l2...ln) = 
; = -1, if n = 0
; = myMax(maxList(l1), maxList(l2...ln)), if l1 is a list
; = myMax(l1, maxList(l2...ln)), otherwise


(defun maxList(l)
  (cond
    ((null l) -1)
    ((listp (car l)) (myMax (maxList (car l)) (maxList (cdr l))))
    (t (myMax (car l) (maxList (cdr l))))
  )
)


; heightNode(l, elem, found)
; = -1, if l is an atom
; = heightNode(l1, elem, false) U ... U heightNode(ln, elem, false), if l is a list and found is false and elem != l1 (l = l1l2...ln)
; = 1 + maxList(heightNode(l1, elem, true) U ... U heightNode(ln, elem, true)), if l is a list and found is false and elem == l1
; = 1 + maxList(heightNode(l1, elem, true) U ... U heightNode(ln, elem, true)), otherwise



(defun heightNode(l elem found)
  (cond
    ((atom l) -1)
    ((and (listp l) (equal found NIL) (not (eq (car l) elem))) (apply  #'max (mapcar #' (lambda(x) (heightNode x elem NIL)) l)))
    ;1. daca nu o fost gasit + nu e egal primul cu elem
    ((and (listp l) (equal found NIL) (eq (car l) elem)) (+ 1 (apply #'maxList (list (mapcar #' (lambda (x) (heightNode x elem T)) l)))))
    ;2. nu o fost gasit + primul=elem
    (t (+ 1 (apply #'max(mapcar #' (lambda (x) (heightNode x elem T)) l))))
    ;3. o fost gasit
  )
)


(defun main(l elem)
  (heightNode l elem NIL)
)

(print (main '(a (b (g)) (c (d (e)) (f))) 'c ) )
