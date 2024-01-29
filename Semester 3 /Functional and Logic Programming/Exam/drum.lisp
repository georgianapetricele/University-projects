(defun nrAp(e l)
  (cond
      ((and (atom l) (equal e l)) 1)
      ((atom l) 0)
      (t (apply '+(mapcar #'(lambda (x) (nrAp e x)) l)))
  )
)

(defun my_member(e l)
  (cond
      ((>(nrAp e l)0) t)
      (t nil)
  )
)

;Un arbore n-ar se reprezintă în LISP astfel ( nod subarbore1 subarbore2 .....). Se cere să se determine calea de la radăcină 
;către un nod dat. ​Se va folosi o funcție MAP.
;Exemplu​ pentru arborele (a (b (g)) (c (d (e)) (f))) 
;a) ​nod=e => (a c d e) 

;pathToNode(node,lvl,l1..ln) = l, if atom(l) and l=node and lvl=0 
;                        = l(i) U pathToNode(node,lvl+1,l(i))


(defun drum (l target)
  (cond
    ((and (atom l) (equal l target)) l)
    ( (atom l) nil)
    ((and (listp l) (my_member target l))
                   (append (list (car l)) (mapcan #'(lambda (x) (drum x target)) l)) )
    (t (mapcan #'(lambda (x) (drum x target)) l))
  )
)

(print (drum '(a (b (g)) (c (d (e)) (f))) 'e))
