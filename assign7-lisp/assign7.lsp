; *********************************************************************
; File   : assign7.lsp
; Author : Keith T. Fancher
; Class  : CS3490
; Date   : 04/07/04
; Purpose: To tire my silly little brain.
; *********************************************************************


; Function : buildpairs
; Arguments: two lists
; Returns  : a list of sublists, with each element of the same index in
;   the lists grouped together
; Examples : 
;   (buildpairs '(1 2 3) '(a b c)) --> ((1 a) (2 b) (3 c))
;   (buildpairs '(1 2) '(a b c))   --> NIL (the lists are of unequal length)
;   (buildpairs 'a 'b)             --> NIL (the arguments are not lists)
;   (buildpairs '() '())           --> NIL
(defun buildpairs(l1 l2)
  (cond
    ((not (listp l1)) nil) ; not a list
    ((not (listp l2)) nil) ; not a list
    ((not (equal (length l1) (length l2))) nil) ; not the same length
    ((null l1) nil) ; empty
    ((null l2) nil) ; empty
    (t (cons (list (car l1) (car l2)) (buildpairs (cdr l1) (cdr l2))))
  )
)


; Function : mappairs
; Arguments: two lists
; Returns  : a list of sublists, with each element of the same index in
;   the lists grouped together
; Examples : 
;   (mappairs '(1 2 3) '(a b c)) --> ((1 a) (2 b) (3 c))
;   (mappairs '(1 2) '(a b c))   --> NIL (the lists are of unequal length)
;   (mappairs 'a 'b)             --> NIL (the arguments are not lists)
;   (mappairs '() '())           --> NIL
(defun mappairs(l1 l2)
  (cond
    ((not (listp l1)) nil) ; not a list
    ((not (listp l2)) nil) ; not a list
    ((not (equal (length l1) (length l2))) nil) ; not the same length
    ((null l1) nil) ; empty
    ((null l2) nil) ; empty
    (t (mapcar 'list l1 l2)) ; good ol' mapcar
  )
)


; Function : subset
; Arguments: a predicate function name, a list
; Returns  : the subset of the input list for which the predicate is true
; Examples : 
;   (subset 'atom '(a b (c d) e))      --> (a b e)
;   (subset 'null '(a b () (c d) ()))  --> (NIL NIL)
;   (subset 'listp '(a b (c d) e))     --> ((c d))
;   (subset 'numberp 3)                --> NIL (3 is not a list)
(defun subset(func l)
  (cond
    ((not (listp l)) nil) ; not a list
    ((null l) nil) ; empty
    ((funcall func (car l)) (cons (car l) (subset func (cdr l))))
    (t (subset func (cdr l)))
  )
)


; Function : presentp
; Arguments: an s-expression, a list
; Returns  : T if expression is embedded anywhere in the list, NIL otherwise
; Examples : 
;   (presentp 'a '(d a f))           --> T
;   (presentp '(a) '(d (a b) f))     --> NIL
;   (presentp 'a '(d (a b) f))       --> T
;   (presentp '(a b) '(d (a b) f))   --> T
;   (presentp '(a b) '(d (a (b)) f)) --> NIL
(defun presentp(expr l)
  (cond
    ((not (listp l)) nil) ; not a list
    ((null l) nil) ; empty
    ((equal expr (car l)) t) ; equal!
    ((listp (car l)) (or (presentp expr (car l)) (presentp expr (cdr l))))
    (t (presentp expr (cdr l)))
  )
)


; Function : matchp
; Arguments: a pattern, a list
; Returns  : T if the pattern is found in the list, NIL if it's not
; Examples : 
;   (matchp '(*) '(a b c)) --> t (the * matches all of the elements in the list)
;   (matchp '(+) '(a b c)) --> t (the * matches all of the elements in the list)
;   (matchp '(+) '()) --> NIL (the + can't match 0 elements)
;   (matchp '(*) '()) --> t (the * can match 0 elements)
;   (matchp '(a b) '(a b)) --> t 
;   (matchp '(a b *) '(a b)) --> t (the * matches 0 elements) 
;   (matchp '(a b +) '(a b)) --> NIL (the + can't match 0 elements) 
;   (matchp '(* a b +) '(a b c d)) --> t (the * matches 0 elements, the + matches c, d) 
;   (matchp '(* a + b +) '(a b c d)) --> NIL (the first + can't match nothing) 
(defun matchp(pat l)
  (cond
    ; a whole lot of base cases
    ((not (listp pat)) nil) ; not a list
    ((not (listp l)) nil) ; not a list
    ((null pat) nil) ; empty
    ((and (null l) (not (equal pat '(*)))) nil) ; empty but pattern's not a star
    ((equal pat l) t) ; they're equal
    ((equal pat '(*)) t) ; star = everything
    ((and (equal pat '(+)) (not (= (length l) 0))) t) ; plus = anything length > 0

    ; then with the recursion
    ((equal (car pat) (car l)) (matchp (cdr pat) (cdr l))) ; first element equal
    ((equal (car pat) '*) (or  (matchp (cdr pat) l)  (matchp (cdr pat) (cdr l))  (matchp pat (cdr l)) ))
    ((equal (car pat) '+) (or (matchp (cdr pat) (cdr l))  (matchp pat (cdr l)) ))

    (t nil) ; or else!
  )
)

