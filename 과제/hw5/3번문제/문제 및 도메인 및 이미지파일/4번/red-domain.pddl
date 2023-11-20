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
             (eaten ?p)             ; ?p is eaten
             (snore ?p)             ; ?p snores
             (timing ?p)            ; ?p eat timing
             (foodchain ?p1 ?p2)    ; ?p1 eat ?p2
             (forward ?loc1 ?loc2)) ; only path ?loc1 -> ?loc2

(:action moveto
  :parameters (?p ?from ?to)
  :precondition (and (forward ?from ?to) (at ?p ?from) (not (stop ?p)))
  :effect (and (timing ?p) (at ?p ?to) (not (at ?p ?from))))

(:action pick-up
  :parameters (?p ?obj ?loc)
  :precondition (and (at ?p ?loc) (stop ?p) (like ?p ?obj))
  :effect (and (have ?p ?obj) (not (stop ?p))))
  
(:action eat-alive
  :parameters (?p1 ?p2 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) (hungry ?p1) 
                (foodchain ?p1 ?p2) (timing ?p2) (alive ?p1) (alive ?p2))
  :effect (and (eaten ?p2) (stop ?p2)))
  
(:action tell-path
  :parameters (?p1 ?p2 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) (not (= ?p1 ?p2))
                (not (path_know ?p1)) (path_know ?p2))
  :effect (and (path_know ?p1) (not (timing ?p1)) (stop ?p1) 
          (not (stop ?p2)) (hungry ?p2)))
  
(:action sleep-snoreloud
  :parameters (?p1 ?p2 ?p3 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) (at ?p3 ?loc) (hungry ?p1) 
                (not (= ?p2 ?p3)) (eaten ?p2) (eaten ?p3))
  :effect (and (snore ?p1) (not (hungry ?p1)))))