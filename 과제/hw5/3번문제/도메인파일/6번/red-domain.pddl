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
             (checked ?p)           ; ?p is checked
             (forward ?x ?y))       ; only path ?x -> ?y 

(:action moveto
  :parameters (?p ?from ?to)
  :precondition (and (forward ?p ?to) (at ?p ?from) (not (stop ?p)))
  :effect (and (at ?p ?to) (not (at ?p ?from))))

(:action pick-up
  :parameters (?p ?obj ?loc)
  :precondition (and (at ?p ?loc) (stop ?p) (like ?p ?obj))
  :effect (and (have ?p ?obj) (not (stop ?p))))
  
(:action eat-alive
  :parameters (?p1 ?p2 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) (hungry ?p1) (not (= ?p1 ?p2)) (not (stop ?p2)) (alive ?p1) (alive ?p2))
  :effect (and (eaten ?p2)))
  
(:action tell-path
  :parameters (?p1 ?p2 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) 
                (not (= ?p1 ?p2)) (not (path_know ?p1)) (path_know ?p2))
  :effect (and (path_know ?p1) (stop ?p1) (not (stop ?p2)) (hungry ?p2)))
  
(:action sleep-snoreloud
  :parameters (?p1 ?p2 ?p3 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) (at ?p3 ?loc) (hungry ?p1) (eaten ?p2) (eaten ?p3))
  :effect (and (snore ?p1) (not (hungry ?p1))))
  
(:action check
  :parameters (?p1 ?p2 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) (not (eaten ?p1)) (snore ?p2))
  :effect (and (checked ?p1)))
  
(:action save
  :parameters (?p1 ?p2 ?p3 ?p4 ?loc)
  :precondition (and (at ?p1 ?loc) (at ?p2 ?loc) (at ?p3 ?loc) (at ?p4 ?loc) (checked ?p1) (snore ?p2) (eaten ?p3) (eaten ?p4) (not (= ?p3 ?p4)))
  :effect (and (not (alive ?p2)) (not (eaten ?p3)) (not (eaten ?p4))))
  
(:action give
  :parameters (?p1 ?p2 ?obj ?loc)
  :precondition (and (have ?p1 ?obj) (at ?p1 ?loc) (at ?p2 ?loc))
  :effect (and (have ?p2 ?obj) 
               (not (have ?p1 ?obj))))) 