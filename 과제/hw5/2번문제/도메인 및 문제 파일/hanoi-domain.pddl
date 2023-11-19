;; The Towers of Hanoi problem (formalisation by Hector Geffner).

(define (domain hanoi)
  (:requirements :strips)
  (:predicates (clear ?x)       ; ?x is clear (?x is either a disc or a pole)
               (on ?x ?y)       ; ?x is on ?y (?x is a disc; ?y is either a disc or a pole)
               (smaller ?x ?y)) ; ?x is smaller than ?y

  (:action move
    :parameters (?disc ?from ?to)
    :precondition (and (smaller ?disc ?to) 
                       (on ?disc ?from) 
		               (clear ?disc) 
		               (clear ?to))
    :effect  (and (clear ?from) 
                  (on ?disc ?to) 
                  (not (on ?disc ?from))  
		          (not (clear ?to))))
  )


                      
