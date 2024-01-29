;15. Determine the list of nodes accesed in postorder in a tree of type (2).


;parcurg_st(l1..ln,nrvert,nredg)=[], if n=0
;                               =[], if nrvert=1+nredg
;                               =l1+l2+parcurg_st(l3..ln,nrvert+1,nredg+l2),otherwise //l2 ne zice cati arbori are=>cate muchii se duc din nodul ala
;

(defun parcurg_st(arb nrvert nredg)
   (cond
     ((null arb) nil)
     ((= nrvert (+ 1 nredg)) nil)
      (t (cons (car arb) 
               (cons (cadr arb) 
                     (parcurg_st (cddr arb) (+ 1 nrvert) (+ (cadr arb) nredg))
               )
         )
     )
   )
)

;stang(l1,l2...ln)=parcurg_st(l3...ln,0,0)

(defun stang (arb)
    (parcurg_st (cddr arb) 0 0)
)

;parcurg_dr(l1..ln,nrvert,nredg)=[], if n=0
;                               =l1,..ln, if nrvert=1+nredg
;                               =l1+l2+parcurg_dr(l3..ln,nrvert+1,nredg+l2),otherwise
;

(defun parcurg_dr(arb nrvert nredg)
  (cond
    ((null arb) nil)
    ((= nrvert(+ 1 nredg)) arb)
    (t   (parcurg_st (cddr arb) (+ 1 nrvert) (+ (cadr arb) nredg))
    )
  )
)

;drept(l1,l2..ln)=parcurg_dr(l3...ln,0,0)
(defun drept(arb)
  (parcurg_dr (cddr arb) 0 0)
)

;my_append(l1..ln,q1...qm)=q1..qm, if n=0
;                         =l1..ln, if m=0
;                         =[], if n=0, m=0
;                         =l1 U my_append(l2..ln,q1..qm),otherwise

(defun my_append(l q)
  (cond
    ( (and (null l) (null q) ) nil)
    ( (null l) l)
    ( (null q) q)
    (t (cons (car l) (my_append (cdr l) q ) ))
  )
)


;postorder(l1,l2..ln)=[],if n=0
;                    =postorder(drept(l1..ln))U postorder(stang(l1..ln))Ul1, otherwise

(defun postorder(arb)
  (cond
    ((null arb) nil)
    (t (my_append (postorder (stang arb)) (my_append (postorder (drept arb)) (list (car arb)) )  ) )
  )
)


(print (postorder '(a 2 b 2 c 1 i 0 f 1 g 0 d 2 e 0 h 0) ))



