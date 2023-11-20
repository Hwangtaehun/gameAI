;; problem file: red-prob5.pddl

(define (problem red-prob5)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf huntsman flower)
    (:init (alive red) (alive granny) (alive wolf) (alive huntsman)
           (at red home) (like red flower)
           (at wolf woods) (path_know wolf) (stop wolf) 
           (foodchain wolf red) (foodchain wolf granny)
           (at granny grannyhouse) (path_know granny) (timing granny)
           (at huntsman grannyhouse) (path_know huntsman)
           (forward home woods) (forward woods grannyhouse)) 
    (:goal (and (have red flower) (eaten red) (eaten granny) (not (hungry wolf)) (at wolf grannyhouse) (checked huntsman))))