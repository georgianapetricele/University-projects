
;D. An n-ary tree is represented in Lisp as ( node subtree1 subtree2 ...).. Write a function to return
;the list of nodes on even levels, in increasing level order (0, 2, …). The root level is assumed 
;zero. A MAP function shall be used.
;Example for the tree (a (b (g 3 )) (c (d (e 6(h 6 7))) (f))) => (a g d f h)

;atomsEvenLvl(l)  = (list l), atom(l) and lvl %2 =0 
;                 = nil, atom(l)
;                 = U atomsEvenLvl(l(i))


(defun atomsEvenLvl(l lvl)
  (cond
      ((and (atom l) (= (mod lvl 2) 0)) (list l))
      ((atom l) nil)
      (t (mapcan #'(lambda (x) (atomsEvenLvl x (+ 1 lvl)))l) )
  )
)

(print (atomsEvenLvl '(a (b (g 3 )) (c (d (e 6(h 6 7))) (f))) -1 ))


(defun nrAtomsEven(l lvl)
  (cond
    ((and (atom l) (not(numberp l)) (eq (mod lvl 2) 0))  1)
    ((atom l) 0)
    (t (apply #'+(mapcar #'(lambda(x) (nrAtomsEven x (+ 1 lvl))) l)) )
  )
)

(print (nrAtomsEven '(a 3 (4 5 a (5 a v)67)a) -1 ))
