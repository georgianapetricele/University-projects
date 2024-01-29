;15. Determine the list of nodes accesed in postorder in a tree of type (2).
; (A (B) (C (D) (E)))

;  A
; / \
; B C
;  / \
;  D  E


;my_append(l1..ln,q1...qm)=q1..qm, if n=0
;                         =l1..ln, if m=0
;                         =[], if n=0, m=0
;                         =l1 U my_append(l2..ln,q1..qm),otherwise


(defun my_append(l q)
  (cond
    ( (and (null l) (null q) ) )
    ( (null l) q)
    ((null q) l)
    (t (cons (car l) (my_append(cdr l) q)) )
  )
)

;postorder(l1,l2,l3...ln)=[], if n=0
;                  =postorder(l2)//left U postorder(l3)//right U l1, otherwise


(defun postorder(arb)
  (cond
    ( (null arb) nil)
    (t (my_append (postorder (cadr arb)) 
                  (my_append (postorder (caddr arb)) (list (car arb) )
                  ) 
       )
    )
  )
)

(print (postorder '(A (B) (C (D) (E))) ) )
