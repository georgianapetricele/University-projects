; Write a function to determine the number of nodes on the level k from a n-tree represented as follows: 
; (root list_nodes_subtree1 ... list_nodes_subtreen) 
; Eg: tree is (a (b (c)) (d) (e (f))) and k=1 => 3 nodes


;nrNodesLvlk(l1...ln level k) = 1, if atom(l) and level=k 
;                             = 0, if atom(l) and level != k
;                             = U nrNodesLvlk(li, level+1, k) , otherwise

(defun nrNodesLvlk(tree level k)
    (cond
        ( (and (atom tree) (= (- level 1) k)) 1)
        ( (atom tree) 0)
        (t (apply'+ (mapcar #'(lambda (a) (nrNodesLvlk a (+ level 1) k)) tree) ) )
    )

)


(print (nrNodesLvlk '(a (b) (c) (d)) 0 0) )





