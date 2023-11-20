(define (domain redridinghood)
(:requirements :strips :negative-preconditions :equality)
(:predicates (at ?p ?loc)           ; ?p is at ?loc  
             (have ?p ?obj)         ; ?p has ?obj
             (talk ?p)              ; ?p tell path
             (path_know ?p)         ; ?p know path
             (stop ?p)              ; ?p is stop
             (like ?p ?obj)         ; ?p like ?obj
             (hungry ?p)            ; ?p is hungry
             (alive ?p)             ; ?p is alive
             (foodchine ?p1 ?p2)    ; ?p1 eat ?p2
             (forward ?loc1 ?loc2)) ; only path ?loc1 -> ?loc2 

(:action moveto
  :parameters (?p ?from ?to)
  :precondition (and (forward ?from ?to) (at ?p ?from) (not (stop ?p)))
  :effect (and (at ?p ?to) (not (at ?p ?from))))

(:action pick-up
  :parameters (?p ?obj ?loc)
  :precondition (and (at ?p ?loc) (stop ?p) (like ?p ?obj))
  :effect (and (have ?p ?obj)))
  
(:action eat-alive
  :parameters (?p1 ?p2 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) (hungry ?p1) (not (= ?p1 ?p2)) (foodchine ?p1 ?p2) (alive ?p1) (alive ?p2))
  :effect (and (not (hungry ?p1)) (stop ?p2)))
  
(:action tell-path
  :parameters (?p1 ?p2 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) 
                (not (= ?p1 ?p2)) (not (path_know ?p1)) (path_know ?p2))
  :effect (and (path_know ?p1) (stop ?p1) (not (stop ?p2)) (hungry ?p2))))