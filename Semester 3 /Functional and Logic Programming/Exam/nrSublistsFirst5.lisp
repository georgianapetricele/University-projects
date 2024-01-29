
;2. You are given a nonlinear list. Compute the number of sublists (including the initial list) where the 
;first numeric atom is 5. For example, for the list: (A 5 (B C D) 2 1 (G (5 H) 7 D) 11 14) there are 3 such 
;lists: the initial list, (G (5 H) 7 D) and (5 H).
 
 (defun linearize(l) ;lin + keep only numbers
    (cond
      ((null l) nil)
      ((numberp l) (list l)) ;use it to get rid off nil
      ((atom l) nil)
      (t (mapcan #'linearize l)) ;use it to append all lists into one
    )
 )
 
 (print (linearize '(2 (A 4 5) 4)))
 

 
 (defun check(l)
      (cond
        ((null (linearize l)) nil)
        ((= (car (linearize l)) 5) t)
        (t nil)
      )
 )
 
 (defun countLists(l)
    (cond
        ( (atom l) 0) ;daca e atom nu sublista initializam de inceput
        ( (check l) (+ 1 (apply #'+(mapcar #'countLists l))) ) ;daca e sublista si respecta cond o incrementam
        ( t (apply '+(mapcar #'countLists l))) ;daca nu doar aplicam + intre celelalte solutii
    )
 )
 
 (print (countLists '(3 4(5 b c(5 C d)) (5 4 7)5 6) ))
