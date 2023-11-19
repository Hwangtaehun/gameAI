(define (domain redridinghood)
(:requirements :strips :negative-preconditions :equality)
(:predicates (at ?p ?loc)           ; ?p is at ?loc  
             (path_know ?p)         ; ?p know path
             (forward ?loc1 ?loc2)) ; only path ?loc1 -> ?loc2 

(:action moveto
  :parameters (?p ?from ?to)
  :precondition (and (forward ?from ?to) (at ?p ?from))
  :effect (and (at ?p ?to) (not (at ?p ?from))))

(:action tell-path
  :parameters (?p1 ?p2 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) 
                (not (= ?p1 ?p2)) (not (path_know ?p1)) (path_know ?p2))
  :effect (and (path_know ?p1))))